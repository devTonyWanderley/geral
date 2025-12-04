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
    QString ch, tt;
    for(uint i = 0; i < msc.length(); i++)
    {
        ch = msc.at(i);
        tt = ch.left(ch.indexOf(' '));
        ch = ch.right(ch.length() - ch.indexOf(' ') - 1);
        TtlMsc.PushBack(tt);
        ChMsc.PushBack(ch.toUInt());
    }
    return true;
}

void arquivo::SeparaPorBandeira(QString &fonte, QString bd, QStringList &qsl)
{
    QString tx = fonte, dd;
    qsl.clear();
    while(tx.indexOf(bd) != -1)
    {
        dd = tx.left(tx.indexOf(bd));
        tx = tx.right(tx.length() - tx.indexOf(bd) - 1);
        qsl.push_back(dd);
    }
    qsl.push_back(tx);
}

void arquivo::SeparaPorBandeira(QString &fonte, QChar bd, QStringList &qsl)
{
    QString tx = bd;
    SeparaPorBandeira(fonte, tx, qsl);
}

void arquivo::SeparaFixos(QString linha, Lista<QString> &qsl)
{
    QString tx = linha, ty;
    qsl.Clear();
    uint i = 1, j;
    while(ChMsc.GetN(j, i))
    {
        ty = tx.left(j);
        tx = tx.right(tx.length() - j);
        qsl.PushBack(ty);
        i++;
    }
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
    if(!LerDdsArq(dir, filtro, titulo))
    {
        qDebug() << "algo errado...";
        return;
    }
    QStringList linhas;
    SeparaPorBandeira(Buffer, '\n', linhas);
    qDebug()
        << linhas.length()
        << " linhas de dados.";
    for(uint i = 0; i < linhas.length(); i++)
    {
        qDebug()
        << linhas.at(i);
        Lista<QString> qsl;
        SeparaFixos(linhas.at(i), qsl); //  ......................................
        Dados.PushFront(qsl);
    }
    Lista<QString> nome;
    qDebug()
        << Dados.Length();
      //  << Dados.GetFront(nome);
     //   << nome.at(1);
    /*
    QStringList qsl;
    uint i = 1;
    while(Dados.GetN(qsl, i))
    {
        qDebug()
            << qsl.at(0);
        i++;
    }
    */
}
