/********
 * Fichier: vecteur.h
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Declartation de la classe vecteur
********/

#ifndef VECTEUR_H
#define VECTEUR_H

#define VECTOR_INITIAL_CAPACITY 1

#include "couche.h"

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

    int* get(int index);
    int* rm(int index);

    void doubleCapacity();
    void emptyVector();
    
    bool isEmpty();
    bool add(int *element);
    
    void disp(int index);

private:
    //================================================
    //Private members
    int *vect_;
    int *vectorSize_;
    int *vectorCapacity_;

};



#endif