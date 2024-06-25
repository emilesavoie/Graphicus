#
# Auteur: C.-A. Brunet
# Date: 13 juin 2024
# Modifie par : Emile Savoie
# Date : 5 juin 2024
# Description: compilation de graphicus-02. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-02: graphicus-02.o tests.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o vecteur.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o vecteur.o

graphicus-02.o: graphicus-02.cpp tests.h
	g++ -c -g graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h rectangle.h carre.h cercle.h
	g++ -c -g tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h
	g++ -c -g canevas.cpp

couche.o: couche.cpp couche.h forme.h
	g++ -c -g couche.cpp

forme.o: forme.cpp forme.h
	g++ -c -g forme.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ -c -g rectangle.cpp

cercle.o: cercle.cpp cercle.h
	g++ -c -g cercle.cpp

carre.o: carre.cpp carre.h
	g++ -c -g carre.cpp

vecteur.o: vecteur.cpp vecteur.h 
	g++ -c -g vecteur.cpp

clean:
	rm  -f *.o
