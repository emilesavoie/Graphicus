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
   if(index > 0 && index < canevas.getSize())
   {
      Couche* couche;
      couche = canevas.get(index);

      if(couche->changeLayerState(ACTIVE))
      {
         return true;
      }
   }

   return false;
}

bool Canevas::desactiverCouche(int index)
{
   if(index > 0 && index < canevas.getSize())
   {
      Couche* couche;
      couche = canevas.get(index);

      if(couche->changeLayerState(INACTIVE))
      {
         return true;
      }
   }

   return false;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   if(p_forme != nullptr)
   {
      Couche* couche;
      couche = canevas.get(canevas.getSize() + 1);

      if(couche->addShape(p_forme))
      {
         return true;
      }
           
   }

   return false;
}

bool Canevas::retirerForme(int index)
{
   if(index > 0 && index < canevas.getSize())
   {
      Couche* couche;
      couche = canevas.get(index);

      if(couche->rmShape(index))
      {
         return true;
      }
   }

   return false;
}

double Canevas::aire()
{
   double canevasAir = 0;

   for(int i = 0; i < canevas.getSize(); i++)
   {
      Couche* couche;
      couche = canevas.get(i);

      canevasAir += couche->getTotalAir();
   }
   return canevasAir;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   for(int i = 0; i < canevas.getSize(); i++)
   {
      Couche* couche;
      couche = canevas.get(i);

      if(couche->translateLayer(deltaX, deltaY))
      {
         return true;
      }
   }

   return true;
}

void Canevas::afficher(ostream & s)
{      
   
   if(canevas.getSize() == 0)
   {
      s << "---- Aucune couche -----" << endl;
   }

   for(int i = 0; i < canevas.getSize(); i++)
   {
      s << "----- Couche " << i << " -----";

      Couche* couche;
      couche = canevas.get(i);

      couche->dispLayer(cout);
   }
}
