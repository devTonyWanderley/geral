#ifndef ARQUIVO_H
#define ARQUIVO_H

#define IDIR "C:/Tony/Soft/cpp/Instâncias/"

#include <QString>
#include <QFile>
#include <QFileDialog>

#include "edgabarito.h"

#include <QDebug>

class arquivo
{
private:
    QString Buffer;
    Lista<uint> ChMsc;
    Lista<QString> TtlMsc;
    Lista<QString> TpMsc;
    //bool MDef;
    Lista<Lista<QString>> Dados;

    bool DefMascara(QStringList &msc);
    bool LerDdsArq(QString dir, QString filtro, QString titulo);
    bool SeparaPorBandeira(QString bd, Lista<QString> &lst);
    bool SeparaPorBandeira(QChar bd, Lista<QString> &lst);
    bool SeparaFixos(QString linha, Lista<QString> &lst);
public:
    arquivo();
    arquivo(QStringList &msc);

    void testes(QString dir, QString filtro, QString titulo);
};

#endif // ARQUIVO_H
