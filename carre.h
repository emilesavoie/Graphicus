/********
 * Fichier: carre.h
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Declartation de la classe enfant carre
********/

#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"

class Carre:public Rectangle
{
public:
    //================================================
    //Constructor
    Carre();
    Carre(int x, int y, float sideLength);
    
    //================================================
    //Public methods
    float getSideLength();
    void SetSideLenghth(float sideLength);
    double aire();
    void afficher(ostream & s);

private:
    //================================================
    //Private members
    string shape_ = "Carre";
    float sideLength_;
    double aire_;
};

#endif