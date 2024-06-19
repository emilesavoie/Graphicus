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
    *vectorCapacity_ = initialVectCapacity;
    *vectorSize_ = initialVectSize;
}

Vecteur::~Vecteur()
{
}

int Vecteur::getCapacity()
{
    return *vectorCapacity_;
}

int Vecteur::getSize()
{
    return *vectorSize_;
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

void Vecteur::emptyVector()
{
    delete[] vect_;
    vect_ = new int[*vectorCapacity_];

    for(int i = 0; i < *vectorCapacity_; i++)
    {
        vect_[i] = NULL;
    }

    int newVectSize = *vectorSize_ * 2;
    *vectorSize_ = newVectSize;
}

bool Vecteur::isEmpty()
{
    if(*vectorSize_ == 0)
    {
        return true;
    }

    return false;
}

bool Vecteur::add(int *element)
{
    if(element != nullptr || *element > *vectorSize_)
    {
        if(*vectorCapacity_ <= *vectorSize_ + 1)
        {
            doubleCapacity();
        }

        vect_[*vectorSize_] = *element;
        *vectorSize_ += 1;
        return true;
    }

    return false;
}

int* Vecteur::get(int index)
{
    if(index < 0 || index > *vectorSize_)
    {
        return &vect_[index];
    }

    return nullptr;
}

int* Vecteur::rm(int index)
{
    if(get(index) != nullptr)
    {
        vect_[index] = NULL;
        *vectorSize_ += -1;
        *vectorCapacity_ += 1;

        return get(index);
    }

    return nullptr;
}
