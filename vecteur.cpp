/********
 * Fichier: cercle.cpp
 * Auteurs: Emile Savoie
 * Date: 16 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    vecteur.h.
********/

#include "vecteur.h"

Vecteur::Vecteur()
{
    int initialVectSize = 0;
    int initialVectCapacity = VECTOR_INITIAL_CAPACITY;

    vect_ = new int[initialVectCapacity];
    vectorCapacity_ = &initialVectCapacity;
    vectorSize_ = &initialVectSize;
}

Vecteur::~Vecteur()
{
}

int* Vecteur::getCapacity()
{
    return vectorCapacity_;
}

int* Vecteur::getSize()
{
    return vectorSize_;
}

void Vecteur::doubleCapacity()
{
    int newCapacity = *vectorCapacity_ * 2;

    int *newArr = new int[newCapacity];

    for(int i = 0; i < *vectorCapacity_; i++)
    {
        newArr[i] = vect_[i];
    }

    delete vect_;

    vect_ = newArr;
    
    *vectorCapacity_ = newCapacity;
}





