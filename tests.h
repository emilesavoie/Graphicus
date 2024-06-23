/********
 * Fichier: tests.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Description: Declaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut etre adapte a vos besoins de tests. Ce fichier
 *    fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "canevas.h"

using namespace std;

class Tests
{
public:
   // Methodes pour les tests unitaires des classes
   void tests_unitaires_formes();
   void tests_unitaires_couche();
   void tests_unitaires_vecteur();
   void tests_unitaires_canevas();
   void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   void tests_application_cas_01();
   void tests_application_cas_02();
   void tests_application(); // Appel de tous les tests applicatifs

   // Methodes pour la validation
   void tests_valid();
};

#endif

/*
QUESTIONS
   1. Return bool = true vs 1;
   2. detruire vs vider vecteur
   3. Precision pour point 6 de classe canevas:
         Elle offre la possibilité de réinitialiser une couche. Le tableau de formes de la couche est alors vidé
      et l’état de la couche devient initialisée si la couche n’est pas à l’état active

ADD ONS
   1. Bien tester la fonction de retirer une couche (tester la destruction)
   2. Probleme avec l'aire du canevas
   3. Verif reinit vs delete vs empty for all classes
   4. Etapes 24-27
*/
