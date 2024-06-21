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
   bool all_tests_passed = true;

   //----------------------------------------========
   // Test constructeur par défaut
   Forme *cercle = new Cercle();
   Forme *carre = new Carre();
   Forme *rectangle = new Rectangle();

   std::cout << "---------- Test default constructor ----------" << endl;

   cercle->afficher(cout);
   carre->afficher(cout);
   rectangle->afficher(cout);

   std::cout << endl;

   std::cout << "---------- Test set dimensions ----------" << endl;

   cercle->~Forme();
   carre->~Forme();
   rectangle->~Forme();
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

   couche2->addShape(cercle2);
   couche2->addShape(carre2);
   couche2->addShape(rectangle2);

   Vecteur *vect = new Vecteur();

   vect->add(couche1);
   vect->add(couche2);

   vect->disp(0);
   vect->disp(1);

   delete[] cercle;
   delete[] rectangle;
   delete[] carre;

   delete couche1;
   delete couche2;

   delete vect;
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
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
   tests_unitaires_vecteur();
   // tests_application_cas_01();
   // tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "========== TESTS APPLICATION (FORMES) ==========" << endl;
   // tests_unitaires_formes();
   // tests_unitaires_couche();
   tests_unitaires_vecteur();
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}
