/********
 * Fichier: carre.cpp
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    carre.h.
********/

#include "carre.h"

Carre::Carre(int x, int y, float sideLength)
    :Forme(x, y)
{
    sideLength_ = sideLength;
}

float Carre::getSideLength()
{
    return sideLength_;
}

void Carre::SetSideLenghth(float sideLenght)
{
    sideLength_ = sideLenght;
}

double Carre::aire()
{
    aire_ = sideLength_*sideLength_;
    return aire_;
}

void Carre::afficher(ostream & s)
{
    s << "" << shape_ << "( x= " << ancrage.x << ", y= " << ancrage.y << ", c= " << sideLength_ << ", aire= " << aire_ << std::endl;
}
