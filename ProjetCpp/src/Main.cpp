//============================================================================
// Name        : ProjetCpp.cpp
// Author      : G
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "Joueur.h"


using namespace std;

int main() {
	cout << "Projet Jeu de Role" << endl; // prints wèwèwè Ma Geule

	/**
	 * Test initialisation joueur + liste des animaux
	 */
	int nbGazelles = 6;
	int nbZebres = 5;
	int nbElephants = 1;
	int nbLions = 1;
	int nbCrocos = 2;

	Joueur j(0, "Zizou", nbGazelles, nbZebres, nbElephants, nbLions, nbCrocos);


    return 0;
}
