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
}

Canevas::~Canevas()
{
}

bool Canevas::ajouterCouche()
{
   Couche *couche = new Couche();

   if (canevas.getSize() < MAX_FORMES)
   {
      for (int i = 0; i < canevas.getSize(); i++)
      {
         if (canevas.get(i)->getState() == ACTIVE)
         {
            if (canevas.add(couche))
            {
               return true;
            }
         }
      }

      if (canevas.add(couche))
      {
         couche->changeLayerState(ACTIVE);
         return true;
      }
   }

   return false;
}

bool Canevas::retirerCouche(int index)
{
   this->reinitialiserCouche(index);

   if (canevas.rm(index))
   {
      return true;
   }

   return false;
}

bool Canevas::reinitialiser()
{
   canevas.emptyVector();

   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   if (index >= 0 && index < canevas.getSize())
   {
      if (canevas.get(index)->getState() == ACTIVE)
      {
         if (canevas.get(index)->resetLayer())
         {
            canevas.get(index)->changeLayerState(ACTIVE);
         }
      }
      else
      {
         canevas.get(index)->resetLayer();
      }

      bool noActiveCouche = false;
      for (int i = 0; i < canevas.getSize(); i++)
      {
         if (i != index && canevas.get(i)->getState() == ACTIVE)
         {
            noActiveCouche = true;
            break;
         }
      }

      if (!noActiveCouche)
      {
         canevas.get(0)->changeLayerState(ACTIVE);
      }

      return true;
   }

   return false;
}

bool Canevas::activerCouche(int index)
{
   if (index >= 0 && index < canevas.getSize())
   {
      for (int i = 0; i < canevas.getSize(); i++)
      {
         if (canevas.get(i)->getState() == ACTIVE)
         {
            canevas.get(i)->changeLayerState(INACTIVE);
         }
      }

      if (canevas.get(index)->changeLayerState(ACTIVE))
      {
         return true;
      }
   }

   return false;
}

bool Canevas::desactiverCouche(int index)
{
   if (index > 0 && index < canevas.getSize())
   {
      Couche *couche;
      couche = canevas.get(index);

      if (couche->changeLayerState(INACTIVE))
      {
         return true;
      }
   }

   return false;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   if (p_forme != nullptr)
   {
      for (int i = 0; i < canevas.getSize(); i++)
      {
         if (canevas.get(i)->getState() == ACTIVE)
         {
            if (canevas.get(i)->addShape(p_forme))
            {
               return true;
            }
         }
      }
   }

   return false;
}

bool Canevas::retirerForme(int index)
{
   if (index > 0 && index < canevas.getSize())
   {
      for (int i = 0; i < canevas.getSize(); i++)
      {
         if (canevas.get(i)->getState() == ACTIVE)
         {
            if (canevas.get(i)->rmShape(index))
            {
               return true;
            }
         }
      }
   }

   return false;
}

double Canevas::aire()
{
   double canevasAir = 0;

   for (int i = 0; i < canevas.getSize(); i++)
   {
      canevasAir += canevas.get(i)->getTotalAir();
   }
   return canevasAir;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   for (int i = 0; i < canevas.getSize(); i++)
   {
      Couche *couche;
      couche = canevas.get(i);

      if (couche->translateLayer(deltaX, deltaY))
      {
         return true;
      }
   }

   return true;
}

void Canevas::afficher(ostream &s)
{

   if (canevas.getSize() == 0)
   {
      s << "---- Aucune couche -----" << endl;
   }

   for (int i = 0; i < canevas.getSize(); i++)
   {
      s << "----- Couche " << i << " -----" << endl;

      Couche *couche;
      couche = canevas.get(i);

      couche->dispLayer(cout);
   }
}
