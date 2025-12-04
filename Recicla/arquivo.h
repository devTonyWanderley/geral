#ifndef ARQUIVO_H
#define ARQUIVO_H

#define IDIR "C:/Tony/Soft/cpp/Instâncias/"

#include <QString>
#include <QFile>
#include <QFileDialog>

#include "edgabarito.h"

#include <QDebug>

class Campo
{
public:
    Campo *Segue;
    QString Valor;
    Campo()
    {
        Segue = nullptr;
        Valor = "";
    }
    Campo(QString &arg)
    {
        Segue = nullptr;
        Valor = arg;
    }
};

class Rgst
{
public:
    Rgst *Segue;
    Campo *Primo;
    uint Count;
    Rgst()
    {
        Segue = nullptr;
        Primo = nullptr;
        Count = 0;
    }
    void Push(QString &arg)
    {
        if(!Primo)
        {
            Primo = new Campo(arg);
            Count++;
            return;
        }
        Campo * aponta = Primo;
        while(aponta->Segue) aponta = aponta->Segue;
        aponta->Segue = new Campo(arg);
        Count++;
    }
    QString Pop()
    {
        if(!Primo) return "";
        Campo * aponta = Primo;
        QString r = aponta->Valor;
        Primo = Primo->Segue;
        delete aponta;
        Count--;
        return r;
    }
};

class arquivo
{
private:
    QString Buffer;
    Lista<uint> ChMsc;
    Lista<QString> TtlMsc;
    //bool MDef;
    Lista<Lista<QString>> Dados;

    bool DefMascara(QStringList &msc);
    void SeparaPorBandeira(QString &fonte, QString bd, QStringList &qsl);
    void SeparaPorBandeira(QString &fonte, QChar bd, QStringList &qsl);
    void SeparaFixos(QString linha, Lista<QString> &qsl);
    bool LerDdsArq(QString dir, QString filtro, QString titulo);
public:
    arquivo();
    arquivo(QStringList &msc);

    void testes(QString dir, QString filtro, QString titulo);
    //void testes(QStringList &msc);
};

#endif // ARQUIVO_H
