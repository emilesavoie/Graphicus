/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : Emile Savoie
 * Date : 16 juin 2024
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
   Vecteur canevas;
};

Canevas::~Canevas()
{
   canevas.~Vecteur();
}

bool Canevas::ajouterCouche()
{
   Couche* couche;

   if(canevas.add(couche))
   {
      return true;
   }

   return false;
}

bool Canevas::retirerCouche(int index)
{
   if(canevas.rm(index))
   {
      return true;
   }

   return false;
}


bool Canevas::reinitialiser() //Check return false case;
{
   canevas.~Vecteur();

   Vecteur canevas;

   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   Couche* couche;

   if(canevas.get(index) != nullptr)
   {
      couche = canevas.get(index);
      couche->resetLayer();

      return true;
   }

   return false;
}

bool Canevas::activerCouche(int index)
{
   return true;
}

bool Canevas::desactiverCouche(int index)
{
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   return true;
}

bool Canevas::retirerForme(int index)
{
   return true;
}

double Canevas::aire()
{
   return 0.0;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   return true;
}

void Canevas::afficher(ostream & s)
{
}
