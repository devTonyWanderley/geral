#include "edpontos.h"

Locus::Locus()
{
    X = Y = 0;
}

Locus::Locus(double x, double y)
{
    X = x;
    Y = y;
}

Locus::Locus(Locus &outro)
{
    X = outro.X;
    Y = outro.Y;
}

void Locus::set_x(double x)
{
    X = x;
}

void Locus::set_y(double y)
{
    Y = y;
}

double Locus::get_x()
{
    return X;
}

double Locus::get_y()
{
    return Y;
}

Locus Locus::operator =(Locus &outro)
{
    X = outro.X;
    Y = outro.Y;
    return *this;
}

Ponto::Ponto()
{
    Nome = Atri = "";
    Abci = Orde = Cota = 0;
}

Ponto::Ponto(QString id, QString atr, double x, double y, double z)
{
    Nome = id;
    Atri = atr;
    Abci = x;
    Orde = y;
    Cota = z;
}

Ponto::Ponto(Ponto &outro)
{
    Nome = outro.getId();
    Atri = outro.getAtr();
    Abci = outro.getX();
    Orde = outro.getY();
    Cota = outro.getZ();
}

void Ponto::setId(QString id)
{
    Nome = id;
}

void Ponto::setAtr(QString atr)
{
    Atri = atr;
}

void Ponto::setX(double x)
{
    Abci = x;
}

void Ponto::setY(double y)
{
    Orde = y;
}

void Ponto::setZ(double z)
{
    Cota = z;
}

QString Ponto::getId()
{
    return Nome;
}

QString Ponto::getAtr()
{
    return Atri;
}

double Ponto::getX()
{
    return Abci;
}

double Ponto::getY()
{
    return Orde;
}

double Ponto::getZ()
{
    return Cota;
}

Ponto Ponto::projEmXy()
{
    return Ponto(Nome + "_p", Nome + "_xy", Abci, Orde, 0);
}

double Ponto::dist(Ponto &outro)
{
    return pow((pow((outro.Abci - Abci), 2) + pow((outro.Orde - Orde), 2) + pow((outro.Cota - Cota), 2)), 0.5);
}

Ponto Ponto::operator = (Ponto outro)
{
    Nome = outro.Nome;
    Atri = outro.Atri;
    Abci = outro.Abci;
    Orde = outro.Orde;
    Cota = outro.Cota;
    return *this;
}

bool Ponto::operator == (Ponto outro)
{
    if(Abci != outro.Abci) return false;
    if(Orde != outro.Orde) return false;
    return (Cota == outro.Cota);
}

Quadro::Quadro()
{
    NE = NW = SW = SE = nullptr;
    Xc = Yc = Sl = Sa = 0;
}

Quadro::Quadro(double xc, double yc, double sl, double sa)
{
    NE = NW = SW = SE = nullptr;
    Xc = xc;
    Yc = yc;
    Sl = sl;
    Sa = sa;
}

Quadro::Quadro(Quadro &outro)
{
    NE = NW = SW = SE = nullptr;
    Xc = outro.Xc;
    Yc = outro.Yc;
    Sl = outro.Sl;
    Sa = outro.Sa;
}

Quadro Quadro::operator = (Quadro &outro)
{
    NE = NW = SW = SE = nullptr;
    Xc = outro.Xc;
    Yc = outro.Yc;
    Sl = outro.Sl;
    Sa = outro.Sa;
    return *this;
}

void Quadro::GetDimQuadro(double &xc, double &yc, double &sl, double &sa)
{
    xc = Xc;
    yc = Yc;
    sl = Sl;
    sa = Sa;
}

double Quadro::GetXc()
{
    return Xc;
}

double Quadro::GetYc()
{
    return Yc;
}

double Quadro::GetSl()
{
    return Sl;
}

double Quadro::GetSa()
{
    return Sa;
}

void Quadro::SetDimQuadro(double xc, double yc, double sl, double sa)
{
    Xc = xc;
    Yc = yc;
    Sl = sl;
    Sa = sa;
}

void Quadro::SetXc(double arg)
{
    Xc = arg;
}

void Quadro::SetYc(double arg)
{
    Yc = arg;
}

void Quadro::SetSl(double arg)
{
    Sl = arg;
}

void Quadro::SetSa(double arg)
{
    Sa = arg;
}

void Quadro::DimQuadro(double xi, double yi, double xa, double ya)
{
    Xc = (xa + xi) / 2;
    Yc = (ya + yi) / 2;
    Sl = ((double)pow(2, (double)((uint)log2(1000 * (xa - xi))))) / 1000.0;
    Sa = ((double)pow(2, (double)((uint)log2(1000 * (ya - yi))))) / 1000.0;
}

void Quadro::DimQuadro(Quadro tronco, bool norte, bool este)
{
    tronco.GetDimQuadro(Xc, Yc, Sl, Sa);
    Sl /= 2.0;
    Sa /= 2.0;
    if(este) Xc += Sl;
    else Xc -= Sl;
    if(norte) Yc += Sa;
    else Yc -= Sa;
}

bool Quadro::MinDistMax(double m)
{
    Ponto p, q;
    uint i = 1, j;
    while(Lp.GetN(p, i))
    {
        j = i + 1;
        while(Lp.GetN(q, j))
        {
            Ponto pp = p.projEmXy(), qq = q.projEmXy();
            if(pp.dist(qq) >= m) return true;
            j++;
        }
        i++;
    }
    return false;
}

bool Quadro::DivideQuadro()
{
    if((Sl < 0.003) || (Sa < 0.003) || (Lp.Length() < 2) || (!MinDistMax(0.002))) return false;
    NE = new Quadro;
    NE->DimQuadro(*this, true, true);
    NW = new Quadro;
    NW->DimQuadro(*this, true, false);
    SW = new Quadro;
    SW->DimQuadro(*this, false, false);
    SE = new Quadro;
    SE->DimQuadro(*this, false, true);
    Ponto p;
    while(Lp.PopFront(p))
    {
        if(p.getX() < Xc)
        {
            if(p.getY() < Yc) SW->Lp.PushFront(p);
            else NW->Lp.PushFront(p);
        }
        else
        {
            if(p.getY() < Yc) SE->Lp.PushFront(p);
            else NE->Lp.PushFront(p);
        }
    }
    return true;
}
