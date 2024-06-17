/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Emile Savoie
 * Date : 16 juin 2024
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche()
{
    classState_ = INIT;
    stateAire_ = 0.0f;

    for (int i = 0; i < MAX_FORMES; i++)
    {
        formes_[i] = nullptr;
    }    
}

Couche::~Couche()
{
}

bool Couche::addShape(Forme *shape)
{
    if(shape == nullptr || classState_ != ACTIVE)
    {
        return 0;
    }

    for (int i = 0; i < MAX_FORMES; i++)
    {
        if (formes_[i] == nullptr)
        {
            formes_[i] = shape;
        }
    }

    return 1;
}

Forme* Couche::rmShape(int index)
{
    if(index > MAX_FORMES || index < 0 || classState_ != ACTIVE)
    {
        return nullptr;
    }

    for(int i = index; i < MAX_FORMES - 1; i++)
    {
        formes_[i] = formes_[i+1];
    }

    return formes_[index];
}

Forme* Couche::getShape(int index)
{
    if(index > MAX_FORMES || index < 0)
    {
        return nullptr;
    }

    return formes_[index];
}

double Couche::getTotalAir()
{
    int i = 0;

    while(formes_[i] != nullptr)
    {
        stateAire_ += formes_[i]->aire();
        i++;
    }

    return stateAire_;
}

bool Couche::translateLayer(int x, int y)
{
    if(classState_ == ACTIVE)
    {
        int i = 0;

        while (formes_[i] != nullptr)
        {
            formes_[i]->translater(x, y);
            i++;
        }

        return 1;
    }

    return 0;  
}

bool Couche::resetLayer()
{
    classState_ = INIT;
    stateAire_ = 0.0f;

    for (int i = 0; i < MAX_FORMES; i++)
    {
        formes_[i] = nullptr;
    }

    return 1;   
}

bool Couche::changeLayerState(int layerState)
{
    if(layerState >= 1 && layerState <= 3)
    {
        classState_ = layerState;
        return 1;
    }

    return 0;
}

void Couche::dispLayer()
{
    
}







