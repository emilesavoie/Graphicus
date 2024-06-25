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
    vectorCapacity_ = VECTOR_INITIAL_CAPACITY;
    vect_ = new Couche*[vectorCapacity_];
    vectorSize_ = 0;
}

Vecteur::~Vecteur()
{
    for(int i = 0; i < vectorSize_; i++)
    {
        delete vect_[i];
    }

    delete[] vect_;
}

int Vecteur::getCapacity()
{
    return vectorCapacity_;
}

int Vecteur::getSize()
{
    return vectorSize_;
}

void Vecteur::doubleCapacity()
{
    int newCapacity = vectorCapacity_ * 2;

    Couche** temp = new Couche*[newCapacity];

    for(int i = 0; i < vectorCapacity_; i++)
    {
        temp[i] = vect_[i];
    }
    
    delete[] vect_;

    vect_ = temp;
    vectorCapacity_ = newCapacity;
}

void Vecteur::emptyVector()
{
    for(int i = 0; i < vectorSize_; i++)
    {
        delete vect_[i];
    }

    vectorSize_ = 0;
}

bool Vecteur::isEmpty()
{
    if(vectorSize_ == 0)
    {
        return true;
    }

    return false;
}

bool Vecteur::add(Couche *element)
{
    if(element != nullptr)
    {
        if(vectorCapacity_ <= vectorSize_ + 1)
        {
            this->doubleCapacity();
        }

        vect_[vectorSize_] = element;
        vectorSize_ ++;
        return true;
    }

    return false;
}

Couche* Vecteur::get(int index)
{
    if(index > 0 || index <= vectorSize_)
    {
        return vect_[index];
    }

    return nullptr;
}

Couche* Vecteur::rm(int index)
{
    if(get(index) != nullptr || index >= 0 || index <= vectorSize_)
    {
        Couche** temp = new Couche*[vectorCapacity_];

        for(int i = 0; i < vectorSize_; i++)
        {
            if(i == index)
            {
                i++;
            }

            temp[i] = vect_[i];
        }

        vectorSize_ --;

        return get(index);
    }

    return nullptr;
}

void Vecteur::disp(ostream & s)
{
    
    for(int i = 0; i < vectorSize_; i++)
    {
        s << "----- Couche " << i << "-----" << endl;
        vect_[i]->dispLayer(cout);
    }
}