/********
 * Fichier: cercle.cpp
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    cercle.h.
********/

#include "cercle.h"

Cercle::Cercle()
    :Forme(0, 0)
{
    radius_ = 1;
    aire_ = this->aire();
}

Cercle::Cercle(int x, int y, float radius)
    :Forme(x, y)
{
    radius_ = radius;
    aire_ = this->aire();
}

float Cercle::getRadius()
{
    return radius_;
}

void Cercle::setRadius(float radius)
{
    radius_ = radius;
    aire_ = this->aire();
}

double Cercle::aire()
{
    aire_ = 3.14*(radius_*radius_);
    return aire_;
}

void Cercle::afficher(ostream & s)
{
    s << shape_ << " (x= " << ancrage.x << ", y=" << ancrage.y << ", c=" << radius_ << ", aire=" << aire_ << ")" << std::endl;
}