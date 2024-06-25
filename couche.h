/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Emile Savoie
 * Date : 16 juin 2024
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#define INIT 1
#define ACTIVE 2
#define INACTIVE 3

const int MAX_FORMES = 5;

#include "forme.h"

class Couche
{
   public:
    //================================================
    //Constructor - Destructor
    Couche();
    ~Couche();

    //================================================
    //Public methods
    bool addShape(Forme *shape);
    Forme* rmShape(int index);
    Forme* getShape(int index);
    double getTotalAir();
    bool translateLayer(int x, int y);
    bool resetLayer();
    bool changeLayerState(int layerState);
    int getState();
    void dispLayer(ostream & s);
   
   private:
    //================================================
    //Private members
     Forme* formes_[MAX_FORMES];
     int layerState_;
     float layerAire_;
};

#endif
