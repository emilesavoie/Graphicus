/********
 * Fichier: cercle.cpp
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    rectangle.h.
********/

#include "rectangle.h"

Rectangle::Rectangle()
    :Forme(0, 0)
{
    dimensions_.height = 1;
    dimensions_.length = 1;
    aire_ = this->aire();
}

Rectangle::Rectangle(int x, int y, float height, float length)
    :Forme(x, y)
{
    dimensions_.height = height;
    dimensions_.length = length;
}

Dimensions Rectangle::getDimensions()
{
    return dimensions_;
}

void Rectangle::setDimensions(float height, float length)
{
    dimensions_.height = height;
    dimensions_.length = length;
    aire_ = this->aire();
}

double Rectangle::aire()
{
    aire_ = dimensions_.height * dimensions_.length;
    return aire_;
}

void Rectangle::afficher(ostream & s)
{
    s << shape_ << " (x= " << ancrage.x << ", y=" << ancrage.y << ", l=" << dimensions_.length << ", h=" << dimensions_.height << ", aire=" << aire_ << ")" << std::endl;
}



