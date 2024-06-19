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
    layerState_ = INIT;
    layerAire_ = 0.0f;

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
    if(shape == nullptr || layerState_ != ACTIVE)
    {
        return false;
    }

    for (int i = 0; i < MAX_FORMES; i++)
    {
        if (formes_[i] == nullptr)
        {
            formes_[i] = shape;
        }
    }

    return true;
}

Forme* Couche::rmShape(int index)
{
    if(index > MAX_FORMES || index < 0 || layerState_ != ACTIVE)
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
        layerAire_ += formes_[i]->aire();
        i++;
    }

    return layerAire_;
}

bool Couche::translateLayer(int x, int y)
{
    if(layerState_ == ACTIVE)
    {
        int i = 0;

        while (formes_[i] != nullptr)
        {
            formes_[i]->translater(x, y);
            i++;
        }

        return true;
    }

    return false;  
}

bool Couche::resetLayer() //Check for fasle return case
{
    layerState_ = INIT;
    layerAire_ = 0.0f;

    for (int i = 0; i < MAX_FORMES; i++)
    {
        formes_[i] = nullptr;
    }

    return true;   
}

bool Couche::changeLayerState(int layerState)
{
    if(layerState >= 1 && layerState <= 3)
    {
        layerState_ = layerState;
        return true;
    }

    return false;
}

void Couche::dispLayer(ostream & s)
{
    
}







