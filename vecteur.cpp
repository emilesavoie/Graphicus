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
	_capacity = VECTOR_INITIAL_CAPACITY;
	_size = 0;
	
	for(int i = 0; i < _capacity; i++)
	{
		vect[i] = nullptr;
	}

}

Vecteur::~Vecteur()
{
	for(int i = 0; i < _size; i++)
	{
		delete vect[i];
	}
	
	delete[] vect;

}

int Vecteur::getCapacity()
{
	return _capacity;
}

int Vecteur::getSize()
{
	return _size;
}

void Vecteur::doubleCapacity()
{
	int newCap = _capacity * 2
	Couche** tempVect = new Couche[newCap];
	
	for(int i = 0; i < newCap; i++)
	{
		if(i < _capacity)
		{
			tempVect[i] = vect[i];
		}
		else
		{
			tempVect[i] = nullptr;
		}
		
	}
	
	delete[] vect;
	
	vect = tempVect;
	
	delete tempVect;
	
	_capacity = _newCap;
}

void Vecteur::emptyVector()
{

}

bool Vecteur::isEmpty()
{
	if(_size == 0)
	{
		return true;
	}
	
	return false;
}

bool Vecteur::add(Couche *element)
{

}

Couche* Vecteur::get(int index)
{

}

Couche* Vecteur::rm(int index)
{

}

void Vecteur::disp(ostream & s)
{

}
