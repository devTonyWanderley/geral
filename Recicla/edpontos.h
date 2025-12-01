/**
 * @date    Início 29/11/25 12:41
 * @brief   Agrupar estruturas de dados de pontos e seus auxiliares
 *          Utiliza as estruturas-gabarito de 'edgabarito.h'
 */
#ifndef EDPONTOS_H
#define EDPONTOS_H

#include <QString>
#include <cmath>
#include "edgabarito.h"


class Locus
{
public:
    Locus();
    Locus(double x, double y);
    Locus(Locus &outro);
    void set_x(double x);
    void set_y(double y);
    double get_x();
    double get_y();
    Locus operator = (Locus &outro);
private:
    double X;
    double Y;
};

class Ponto
{
public:
    Ponto();
    Ponto(QString id, QString atr, double x, double y, double z);
    Ponto(Ponto &outro);
    void setId(QString id);
    void setAtr(QString atr);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    QString getId();
    QString getAtr();
    double getX();
    double getY();
    double getZ();
    Ponto projEmXy();
    double dist(Ponto &outro);
    Ponto operator = (Ponto outro);
    bool operator == (Ponto outro);
private:
    QString Nome;
    QString Atri;
    double Abci;
    double Orde;
    double Cota;
};

class Quadro
{
private:
    double Xc;
    double Yc;
    double Sl;
    double Sa;
    //bool DivideQuadro();
public:
    Quadro *NE;
    Quadro *NW;
    Quadro *SW;
    Quadro *SE;
    Lista<Ponto> Lp;
    Quadro();
    Quadro(double xc, double yc, double sl, double sa);
    Quadro(Quadro &outro);
    Quadro operator = (Quadro &outro);
    void GetDimQuadro(double &xc, double &yc, double &sl, double &sa);
    double GetXc();
    double GetYc();
    double GetSl();
    double GetSa();
    void SetDimQuadro(double xc, double yc, double sl, double sa);
    void SetXc(double arg);
    void SetYc(double arg);
    void SetSl(double arg);
    void SetSa(double arg);
    void DimQuadro(double xi, double yi, double xa, double ya);
    void DimQuadro(Quadro tronco, bool norte, bool este);
    bool MinDistMax(double m);  //  critério pra dividir

    bool DivideQuadro();
};

#endif // EDPONTOS_H
