#include "arquivo.h"

arquivo::arquivo()
{
    //MDef = false;
}

arquivo::arquivo(QStringList &msc)
{
    //MDef = DefMascara(msc);
}

bool arquivo::DefMascara(QStringList &msc)
{
    if(!msc.length()) return false;
    for(uint i = 0; i < msc.length(); i++)
    {
        QString tx = msc.at(i), tt, ch, tp;
        tt = tx.left(tx.indexOf(' '));
        tx = tx.right(tx.length() - tx.indexOf(' ') - 1);
        ch = tx.left(tx.indexOf(' '));
        tp = tx.right(tx.length() - tx.indexOf(' ') - 1);
        //tp = tx.right(tx.length() - 1);
        TtlMsc.PushBack(tt);
        ChMsc.PushBack(ch.toUInt());
        TpMsc.PushBack(tp);
    }
    return true;
}

bool arquivo::LerDdsArq(QString dir, QString filtro, QString titulo)
{
    QString id = QFileDialog::getOpenFileName(nullptr, titulo, dir, filtro);
    if(id == "") return false;
    QFile arq;
    arq.setFileName(id);
    if(!arq.open(QFile::ReadOnly | QFile::Text))return false;
    Buffer.clear();
    Buffer = arq.readAll();
    arq.close();
    return true;
}

void arquivo::testes(QString dir, QString filtro, QString titulo)
{
    QString tt, tp;
    uint ch;
    for(uint i = 1; i <= ChMsc.Length(); i++)
    {
        TtlMsc.GetN(tt, i);
        TpMsc.GetN(tp, i);
        ChMsc.GetN(ch, i);
        qDebug()
            << tt
            << '\t'
            << tp
            << '\t'
            << ch;
    }
    if(LerDdsArq(dir, filtro, titulo))
    {
        Lista<QString> lista;
        if(SeparaPorBandeira('\n', lista))
        {
            Lista<QString> lst1;
            while(lista.PopFront(tt))
            {
                SeparaFixos(tt, lst1);
                Dados.PushBack(lst1);
            }
            uint i = 1;
            while(Dados.GetN(lst1, i++))
            {
                uint j = 1;
                tp = "";
                while(lst1.GetN(tt, j++))
                {
                    tp += '\t';
                    tp += tt;
                }
                qDebug() << tp;
            }
        }
        else
            qDebug() << "Erro";
    }
}

bool arquivo::SeparaPorBandeira(QString bd, Lista<QString> &lst)
{
    if(!Buffer.length()) return false;
    QString tx, dd;
    while(lst.Length()) lst.PopBack(tx);
    tx = Buffer;
    while(tx.indexOf(bd) != -1)
    {
        dd = tx.left(tx.indexOf(bd));
        tx = tx.right(tx.length() - tx.indexOf(bd) - 1);
        lst.PushBack(dd);
    }
    lst.PushBack(tx);
    return true;
}

bool arquivo::SeparaPorBandeira(QChar bd, Lista<QString> &lst)
{
    QString tx = bd;
    return SeparaPorBandeira(tx, lst);
}

bool arquivo::SeparaFixos(QString linha, Lista<QString> &lst)
{
    QString tx, ty;
    while(lst.Length()) lst.PopBack(tx);
    uint i = 1, j;
    tx = linha;
    while(ChMsc.GetN(j, i))
    {
        ty = tx.left(j);
        tx = tx.right(tx.length() - j);
        lst.PushBack(ty);
        i++;
    }
    return true;
}
