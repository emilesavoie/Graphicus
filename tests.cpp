/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Emile Savoie
 * Date : 16 juin
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "tests.h"
#include "forme.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"

void Tests::tests_unitaires_formes()
{
    //----------------------------------------
    // Test constructeur par défaut
    std::cout << "---------- Test constructeur par défaut ----------" << std::endl;
    Cercle *cercle = new Cercle();
    Carre *carre = new Carre();
    Rectangle *rectangle = new Rectangle();

    cercle->afficher(cout);
    carre->afficher(cout);
    rectangle->afficher(cout);

    std::cout << std::endl;

    // Test set dimensions
    std::cout << "---------- Test set dimensions ----------" << std::endl;

    cercle->setRadius(5);
    carre->setDimensions(4);
    rectangle->setDimensions(3, 7);

    cercle->afficher(cout);
    carre->afficher(cout);
    rectangle->afficher(cout);

    // Test calcul aire
    std::cout << "---------- Test calcul aire ----------" << std::endl;
    std::cout << "Aire du cercle: " << cercle->aire() << std::endl;
    std::cout << "Aire du carré: " << carre->aire() << std::endl;
    std::cout << "Aire du rectangle: " << rectangle->aire() << std::endl;

    // Test valeurs limites
    std::cout << "---------- Test valeurs limites ----------" << std::endl;
    cercle->setRadius(0);
    carre->setDimensions(-1);
    rectangle->setDimensions(3, -2);

    cercle->afficher(cout);
    carre->afficher(cout);
    rectangle->afficher(cout);

    std::cout << "Aire du cercle avec rayon 0: " << cercle->aire() << std::endl;
    std::cout << "Aire du carré avec côté -1: " << carre->aire() << std::endl;
    std::cout << "Aire du rectangle avec largeur -2: " << rectangle->aire() << std::endl;

    delete cercle;
    delete carre;
    delete rectangle;
}

void Tests::tests_unitaires_couche()
{
   Forme *cercle = new Cercle();
   Forme *carre = new Carre();
   Forme *rectangle = new Rectangle();

   Couche *couche = new Couche();

   couche->changeLayerState(ACTIVE);

   cout << "========== TESTS UNITAIRE COUCHE ==========" << endl;

   std::cout << "---------- Test add shape ----------" << endl;

   couche->addShape(cercle);
   couche->addShape(carre);
   couche->addShape(rectangle);

   couche->dispLayer(cout);

   std::cout << endl;

   std::cout << "---------- Test remove shape ----------" << endl;
   std::cout << " - Remove rectangle" << endl;

   couche->rmShape(2);

   couche->dispLayer(cout);

   std::cout << endl;

   std::cout << "---------- Test get shape ----------" << endl;
   std::cout << " - Get cercle" << endl;

   Forme *forme = couche->getShape(0);
   forme->afficher(cout);

   std::cout << " - Reprint couche" << endl;

   couche->dispLayer(cout);

   std::cout << endl;

   std::cout << "---------- Test total air ----------" << endl;

   std::cout << "Total air: " << couche->getTotalAir() << endl;

   std::cout << endl;

   std::cout << "---------- Test Translate couche ----------" << endl;
   std::cout << " - Before" << endl;
   couche->dispLayer(cout);
   std::cout << " - After: x = 3, y = -10" << endl;
   couche->translateLayer(3, -10);
   couche->dispLayer(cout);

   std::cout << endl;

   std::cout << "---------- Test reset layer ----------" << endl;
   std::cout << " - Before" << endl;
   couche->dispLayer(cout);
   std::cout << " - After" << endl;
   couche->resetLayer();
   couche->dispLayer(cout);

   std::cout << endl;

   std::cout << "---------- Test set couche state ----------" << endl;
   std::cout << " - Before" << endl;
   couche->dispLayer(cout);
   std::cout << " - After: active" << endl;
   couche->changeLayerState(ACTIVE);
   couche->dispLayer(cout);

   delete cercle;
   delete carre;
   delete rectangle;

   delete couche;

   std::cout << endl;
}

void Tests::tests_unitaires_vecteur()
{

   cout << "========== TESTS UNITAIRE VECTEUR ==========" << endl;
   Forme *cercle = new Cercle();
   Forme *carre = new Carre();
   Forme *rectangle = new Rectangle();

   Forme *cercle2 = new Cercle(2, 4, 2);
   Forme *carre2 = new Carre(2, 3, 1);
   Forme *rectangle2 = new Rectangle(0, 5, 1, 2);

   Couche *couche1 = new Couche();

   couche1->changeLayerState(ACTIVE);

   couche1->addShape(carre);
   couche1->addShape(rectangle);
   couche1->addShape(cercle);

   couche1->dispLayer(cout);

   Couche *couche2 = new Couche();

   couche2->changeLayerState(ACTIVE);

   couche2->addShape(cercle2);
   couche2->addShape(carre2);
   couche2->addShape(rectangle2);

   Vecteur *vect = new Vecteur();

   vect->add(couche1);
   vect->add(couche2);

   vect->disp(std::cout);

   delete cercle;
   delete rectangle;
   delete carre;

   delete cercle2;
   delete rectangle2;
   delete carre2;

   delete couche1;
   delete couche2;

   delete[] vect;
}

void Tests::tests_unitaires_canevas()
{
    std::cout << "========== TESTS UNITAIRES CANEVAS ==========" << std::endl;

    Canevas *canevas = new Canevas();

    Forme *cercle = new Cercle();
    Forme *carre = new Carre();
    Forme *rectangle = new Rectangle();

    std::cout << "---------- Test ajout de formes dans différentes couches ----------" << std::endl;
    
    canevas->ajouterCouche();
    canevas->activerCouche(0);
    canevas->ajouterForme(cercle);
    
    canevas->ajouterCouche();
    canevas->activerCouche(1);
    canevas->ajouterForme(carre);
    
    canevas->ajouterCouche();
    canevas->activerCouche(2);
    canevas->ajouterForme(rectangle);

    canevas->afficher(std::cout);

    std::cout << std::endl;

    std::cout << "---------- Test suppression de formes dans différentes couches ----------" << std::endl;
    canevas->activerCouche(0);
    canevas->retirerForme(0);

    canevas->activerCouche(1);
    canevas->retirerForme(0);

    canevas->afficher(std::cout);

    std::cout << std::endl;

    std::cout << "---------- Test calcul de l'aire totale ----------" << std::endl;
    canevas->activerCouche(0);
    canevas->ajouterForme(cercle);

    canevas->activerCouche(1);
    canevas->ajouterForme(carre);

    canevas->activerCouche(2);
    canevas->ajouterForme(rectangle);

    double aire_totale = canevas->aire();
    std::cout << "Aire totale du canevas: " << aire_totale << std::endl;

    std::cout << std::endl;

    std::cout << "---------- Test reinitialisation du canevas ----------" << std::endl;
    canevas->reinitialiser();

    canevas->afficher(std::cout);

    delete canevas;
}

void Tests::tests_valid()
{
   std::cout << std::endl;
   std::cout << "ETAPE 1-2" << std::endl;
   std::cout << "1: Creation d'un canevas" << std::endl;
   std::cout << "2: Affichage de son contenu" << std::endl;
   std::cout << std::endl;

   Canevas *canevas = new Canevas();
   canevas->afficher(std::cout);

   std::cout << std::endl;

   std::cout << "ETAPE 3-5" << std::endl;
   std::cout << "3: Ajout de 5 couches au canevas" << std::endl;
   std::cout << "4: Affichage de son contenu" << std::endl;
   std::cout << std::endl;

   for (int i = 0; i < 5; i++)
   {
      canevas->ajouterCouche();
   }

   canevas->afficher(std::cout);

   std::cout << std::endl;
   std::cout << "5. Affichage de l'aire du canevas" << std::endl;
   std::cout << "Aire du canevas: " << canevas->aire() << std::endl;

   std::cout << std::endl;
   std::cout << "ETAPE 6-9" << std::endl;
   std::cout << "6: Activer la couche 2 et y ajouter les elements suivant" << std::endl;
   std::cout << "    " << "cercle (x=0, y=1, rayon=5)" << std::endl;
   std::cout << "    " << "carre (x=1, y=2, cote=6)" << std::endl;
   std::cout << "    " << "rectangle (x=2, y=3, largeur=4, hauteur=9)" << std::endl;

   Forme *cercle1 = new Cercle(0, 1, 5);
   Forme *carre1 = new Carre(1, 2, 6);
   Forme *rectange1 = new Rectangle(2, 3, 4, 9);

   canevas->activerCouche(2);
   canevas->ajouterForme(cercle1);
   canevas->ajouterForme(carre1);
   canevas->ajouterForme(rectange1);

   std::cout << "7: Activer la couche 1 et y ajouter les elements suivant" << std::endl;
   std::cout << "    " << "rectangle (x=0, y=0, largeur=12, hauteur=3)" << std::endl;
   std::cout << "8: Affichage de son contenu" << std::endl;
   std::cout << std::endl;

   Forme *rectange2 = new Rectangle(0, 0, 12, 3);

   canevas->activerCouche(1);
   canevas->ajouterForme(rectange2);

   canevas->afficher(std::cout);

   std::cout << std::endl;
   std::cout << "9. Afficher l'aire du canevas" << std::endl;
   std::cout << "Aire du canevas: " << canevas->aire() << std::endl;

   std::cout << std::endl;
   std::cout << "ETAPE 10-13" << std::endl;
   std::cout << "10: Activer la couche 0 et y ajouter les elements suivant" << std::endl;
   std::cout << "    " << "rectangle (x=0, y=0, largeur=1, hauteur=1)" << std::endl;
   std::cout << "    " << "carre (x=0, y=0, cote=1)" << std::endl;
   std::cout << "    " << "cercle (x=0, y=0, rayon = 1)" << std::endl;
   std::cout << "11: Activer la couche la couche 2 et appliquer une translation de x=2 et y=1" << std::endl;
   std::cout << "12: Afficher de son contenu" << std::endl;
   std::cout << std::endl;

   Forme *rectangle3 = new Rectangle();
   Forme *carre3 = new Carre();
   Forme *cercle3 = new Cercle();

   canevas->activerCouche(0);

   canevas->ajouterForme(rectangle3);
   canevas->ajouterForme(carre3);
   canevas->ajouterForme(cercle3);

   canevas->activerCouche(2);
   canevas->translater(2, 1);

   canevas->afficher(std::cout);

   std::cout << std::endl;
   std::cout << "13. Affichage de l'aire du canevas" << std::endl;
   std::cout << "Aire du canevas: " << canevas->aire() << std::endl;

   std::cout << std::endl;
   std::cout << "ETAPE 14-20" << std::endl;
   std::cout << "14: Activer la couche 0 et retirer la deuxieme forme" << std::endl;
   std::cout << "15: Reinitialiser la couche 1" << std::endl;
   std::cout << "16:Activer la couche 2" << std::endl;
   std::cout << "17: Enlever la couche 2 du canevas" << std::endl;
   std::cout << "18: Activer la couche 4" << std::endl;
   std::cout << std::endl;

   canevas->activerCouche(0);
   canevas->retirerForme(1);

   canevas->reinitialiserCouche(1);

   canevas->activerCouche(2);
   canevas->retirerCouche(2);

   if (!canevas->activerCouche(4))
   {
      std::cout << "L'ajout n'a pas pu etre effectue, car l'indexe est invalide" << std::endl;
      std::cout << "Aucune modification est donc apporte au canevas" << std::endl;
      std::cout << std::endl;
   }

   std::cout << "19: Afficher le contenu du canevas" << std::endl;
   std::cout << std::endl;

   canevas->afficher(std::cout);

   std::cout << std::endl;
   std::cout << "20: Afficher l'aire du canevas" << std::endl;
   std::cout << "Aire du canevas: " << canevas->aire() << std::endl;
   std::cout << std::endl;

   std::cout << "ETAPE 21-23" << std::endl;
   std::cout << "21: Reinitialiser le canevas" << std::endl;
   std::cout << "22: Afficher le canevas" << std::endl;
   std::cout << std::endl;

   canevas->reinitialiser();
   canevas->afficher(std::cout);

   std::cout << std::endl;
   std::cout << "23: Afficher l'aire" << std::endl;
   std::cout << "Aire du canevas: " << canevas->aire() << std::endl;
   std::cout << std::endl;

   std::cout << "ETAPE 24-27" << std::endl;
   std::cout << "24: Activer la couche 3 et ajouter les elements suivants" << std::endl;
   std::cout << std::endl;

   if (!canevas->activerCouche(3))
   {
      std::cout << "L'activation n'a pas pu etre effectue, car l'indexe est invalide" << std::endl;
      std::cout << "Aucune modification est donc apporte au canevas" << std::endl;
      std::cout << std::endl;
   }

   Forme *carre4 = new Carre(10, 10, 10);
   Forme *null = nullptr;

   std::cout << "    carre (x=10, y=10, cote=10)" << std::endl;
   std::cout << std::endl;

   if (!canevas->ajouterForme(carre4))
   {
      std::cout << "L'ajout n'a pas pu etre effectue, car la couche n'est pas active" << std::endl;
      std::cout << "Aucune modification est donc apporte au canevas" << std::endl;
      std::cout << std::endl;
   }

   std::cout << "    Pointeur null" << std::endl;
   std::cout << std::endl;
   if (!canevas->ajouterForme(null))
   {
      std::cout << "L'ajout n'a pas pu etre effectue, car l'ajout d'un pointeur nulle est interdite" << std::endl;
      std::cout << "Aucune modification est donc apporte au canevas" << std::endl;
      std::cout << std::endl;
   }

   std::cout << "26: Afficher le contenu du canevas" << std::endl;
   std::cout << std::endl;

   canevas->afficher(std::cout);

   std::cout << std::endl;
   std::cout << "27: Afficher l'aire" << std::endl;
   std::cout << "Aire du canevas: " << canevas->aire() << std::endl;
   std::cout << std::endl;
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_couche();
   tests_unitaires_vecteur();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "========== TESTS VALIDATION ==========" << endl;
   // tests_valid();
   // tests_unitaires_couche();
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;
   tests_unitaires_formes();
   tests_unitaires_couche();
   tests_unitaires_vecteur();
   tests_unitaires_canevas();
}
