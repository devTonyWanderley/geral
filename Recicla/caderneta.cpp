#include "caderneta.h"

bool LerArquivo(QString dir, QString filtro, QByteArray &qba)
{
    QString id = QFileDialog::getOpenFileName(nullptr, "Abrir arquivo", dir, filtro);
    if(id == "") return false;
    QFile arq;
    arq.setFileName(id);
    if(!arq.open(QFile::ReadOnly | QFile::Text))return false;
    qba.clear();
    qba = arq.readAll();
    arq.close();
    return true;
}

void SeparaTexto(Lista<QByteArray>&partes, QByteArray &texto, char sep)
{
    QByteArray ln;
    while(partes.Length()) partes.PopFront(ln);
    while(texto.indexOf(sep) > -1)
    {
        ln = texto.left(texto.indexOf(sep));
        partes.PushBack(ln);
        texto = texto.right(texto.length() - texto.indexOf(sep) - 1);
    }
    partes.PushBack(texto);
    texto.clear();
}


void SeparaTexto(Lista<QByteArray>&partes, QByteArray &texto, QByteArray sep)
{
    QByteArray ln;
    while(partes.Length()) partes.PopFront(ln);
    while(texto.indexOf(sep) > -1)
    {
        ln = texto.left(texto.indexOf(sep));
        partes.PushBack(ln);
        texto = texto.right(texto.length() - texto.indexOf(sep) - sep.length());
    }
    partes.PushBack(texto);
    texto.clear();
}

void TxPraDouble(QByteArray tx, double &d)
{
    if((tx.indexOf('.') == -1) && (tx.indexOf(',') == -1))
    {
        d = tx.toDouble();
        return;
    }
    int i = tx.indexOf('.');
    if(i == -1) i = tx.indexOf(',');
    QByteArray t0 = tx.left(i), t1 = tx.right(tx.length() - i - 1);
    d = t1.toDouble();
    d /= pow(10, (double)(t1.length()));
    d += t0.toDouble();
}

void LerLnFixPnt(QByteArray ln, QString &id, QString &atr, double &x, double &y, double &z)
{
    id = (QString)ln.left(4);
    ln = ln.right(34);
    QByteArray tx = ln.left(8);
    ln = ln.right(26);
    TxPraDouble(tx, x);
    tx = ln.left(8);
    ln = ln.right(18);
    TxPraDouble(tx, y);
    tx = ln.left(6);
    atr = (QString)ln.right(11);
    TxPraDouble(tx, z);
}

Quadro * Navega(Quadro *qd, Locus lc)
{
    Quadro *r = nullptr;
    if(
        (lc.get_x() < (qd->GetXc() - qd->GetSl())) ||
        (lc.get_x() > (qd->GetXc() + qd->GetSl())) ||
        (lc.get_y() < (qd->GetYc() - qd->GetSa())) ||
        (lc.get_y() > (qd->GetYc() + qd->GetSa()))
        )
        return r;
    r = qd;
    bool n, e;
    while(r->NE)
    {
        n = (lc.get_y() >= r->GetYc());
        e = (lc.get_x() >= r->GetXc());
        if(n)
        {
            if(e)
                r = r->NE;
            else
                r = r->NW;
        }
        else
        {
            if(e)
                r = r->SE;
            else
                r = r->SW;}
    }
    return r;
}

bool LerCaderneta(Quadro &qd)       //  É cedo pra usar esta rotina .. tem que resolver a navegação primeiro.
{
    QByteArray buf;
    if(!LerArquivo(IDIR, "Texto (*.txt)", buf)) return false;
    Lista<QByteArray> linhas;
    SeparaTexto(linhas, buf, '\n');
    uint i = 0;
    QString id, atr;
    double x, y, z, xi, xa, yi, ya;
    bool flg = false;
    while(linhas.GetN(buf, ++i))
    {
        LerLnFixPnt(buf, id, atr, x, y, z);     //  parametrizar a leitura por comprimento fixo
                                                //  tanto nos comprimentos quanto na órdem em que
                                                //  eles aparecem
        Ponto p(id, atr, x, y, z);
        qd.Lp.PushFront(p);
        if(flg)
        {
            if(x < xi) xi = x;
            else if(x > xa) xa = x;
            if(y < yi) yi = y;
            else if(y > ya) ya = y;
        }
        else
        {
            xi = xa = x;
            yi = ya = y;
            flg = true;
        }
    }
    //  aqui, modela-se o quadro
    qd.DimQuadro(xi, yi, xa, ya);
    return true;
}

void EstruQuadro(Quadro *qd)        //  Precisa-se de um bom mecanismo de navegação por valor
{
    Locus l(qd->GetXc(), qd->GetYc());
    Pilha<Locus> pl;
    pl.Push(l);
    Quadro *aponta = qd;
    while(pl.Lenght())
    {
        pl.Pop(l);
        aponta = Navega(aponta, l);
        if(aponta)
        {
            if(aponta->DivideQuadro())
            {
                l.set_x(aponta->SE->GetXc());
                l.set_y(aponta->SE->GetYc());
                pl.Push(l);
                l.set_x(aponta->SW->GetXc());
                l.set_y(aponta->SW->GetYc());
                pl.Push(l);
                l.set_x(aponta->NW->GetXc());
                l.set_y(aponta->NW->GetYc());
                pl.Push(l);
                l.set_x(aponta->NE->GetXc());
                l.set_y(aponta->NE->GetYc());
                pl.Push(l);
            }
        }
    }
/**
     * preencher quadro:
     *      *raiz -> pilha;
     *      enquanto topo:
     *          acessa topo;    ..  eAtual = topo
     *          remove topo;    ..  pop!
     *          se existe pontos no eAtual & critério de distancia:
     *              cria SE em eAtual;
     *              SE -> topo;
     *              cria SW em eAtual;
     *              SW -> topo;
     *              cria NW em eAtual;
     *              NW -> topo;
     *              cria NE em eAtual;
     *              NE -> topo;
     *              enquanto eAtual.Lp:
     *                  eAtual.Lp.ponto -> (NE .. SE, conforme posição relativa);
     *              fim enquanto;
     *          fim se;
     *      fim enquanto;
    */
}
