/**
 * @date    Início 29/11/25 15:28
 * @bug     Posteriormente, calibrar o temanho da linha fixa ou parametrizar os dados
 */
#ifndef CADERNETA_H
#define CADERNETA_H

#define IDIR "C:/Tony/Soft/cpp/Instâncias/"

#include "edpontos.h"
#include "mascara.h"

#include <QString>
#include <QFile>
#include <QFileDialog>

bool LerArquivo(QString dir, QString filtro, QByteArray &qba);
void SeparaTexto(Lista<QByteArray>&partes, QByteArray &texto, char sep);
void SeparaTexto(Lista<QByteArray>&partes, QByteArray &texto, QByteArray sep);
void TxPraDouble(QByteArray tx, double &d);
void LerLnFixPnt(QByteArray ln, QString &id, QString &atr, double &x, double &y, double &z);
Quadro * Navega(Quadro *qd, Locus lc);
bool LerCaderneta(Quadro &qd);
#endif // CADERNETA_H
