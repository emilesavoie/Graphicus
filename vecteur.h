/********
 * Fichier: vecteur.h
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Declartation de la classe vecteur
********/

#ifndef VECTEUR_H
#define VECTEUR_H

#include "couche.h"

#define VECTOR_INITIAL_CAPACITY 1

class Vecteur
{
public:
    //================================================
    //Constructor - Destructor
    Vecteur();
    ~Vecteur();

    //================================================
    //Public methods
    int getCapacity();
    int getSize();

    Couche* get(int index);
    Couche* rm(int index);

    void doubleCapacity();
    void emptyVector();
    
    bool isEmpty();
    bool add(Couche* element);
    
    void disp(int index);

private:
    //================================================
    //Private members
    Couche** vect_;
    int vectorSize_;
    int vectorCapacity_;
};

#endif