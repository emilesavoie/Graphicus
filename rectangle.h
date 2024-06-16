/********
 * Fichier: rectangle.h
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Declartation de la classe enfant rectangle
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"
#include "dimensions.h"

using namespace std;

class Rectangle:public Forme
{
public:
    //================================================
    //Constructor
    Rectangle(int x, int y, float height, float length);

    //================================================
    //Public methods
    Dimensions getDimensions();
    void setDimensions(float height, float length);
    double aire();
    void afficher(ostream & s);

private:
    //================================================
    //Private members
    string shape_ = "Rectangle";
    float aire_;
protected:
    //================================================
    //Protected members
    Dimensions dimensions_;
};


#endif