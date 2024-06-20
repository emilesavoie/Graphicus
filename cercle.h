/********
 * Fichier: cercle.h
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Declartation de la classe enfant cercle
********/

#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"

class Cercle:public Forme
{
public:
    //================================================
    //Constructor
    Cercle();
    Cercle(int x, int y, float radius);

    //================================================
    //Public methods
    float getRadius();
    void setRadius(float radius);
    double aire();
    void afficher(ostream & s);

private:
    //================================================
    //Private members
    string shape_ = "Cercle";
    float radius_;
    double aire_;

};

#endif