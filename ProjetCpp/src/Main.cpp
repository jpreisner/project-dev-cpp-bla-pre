//============================================================================
// Name        : ProjetCpp.cpp
// Author      : G
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

#include "AffichageConsole.h"
#include "Joueur.h"
#include "Pion/Animal.h"
#include "Pion/ImpalaJones.h"
#include "Plateau/Plateau.h"

class AffichageConsole;


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

	Joueur j(0, "Zizou", 1, nbGazelles, nbZebres, nbElephants, nbLions, nbCrocos);
	cout << j << endl;

	unsigned int i;
	for (i = 0; i < j.getListAnimaux().size(); i++) {
		cout << "listAnimaux[" << i << "]=" << j.getAnimal(i)->print() << endl;
	}

	ImpalaJones ij(1, 0);
	cout << "Position de Impala Jones : (" << ij.getX() << ", " << ij.getY() << ")" << endl;

	AffichageConsole affichage;
	Plateau p;
	p.initImpalaJones(ij);
	affichage.affichePlateau(p);
	/*p.print();*/

	/*
	cout << "Test Déplacement de ImpalaJones" << endl;
	ImpalaJones ij(1, 0);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	ij.deplacer(3, p);
	cout << ij << endl;
	*/

	/** Affichage final **/
	/*
	cout << "======================================" << endl;
	cout << "            Drôle de Zèbres           " << endl;
	cout << "======================================" << endl;
	int typeAffichage = Affichage::demandeTypeAffichage();
	if(typeAffichage == 1){
		AffichageConsole affichage;
	}
	int menu_demarrage = affichage.menuDemarrage();

	// Lancer la partie (entre joueur et ordi)
	if(menu_demarrage == 1){

	}
	// Lancer la partie (entre joueur1 et joueur2)
	else if(menu_demarrage == 2){

	}
	// Afficher les règles
	else if(menu_demarrage == 3){

	}
	// Charger une partie
	else if(menu_demarrage == 4){

	}
	// Quitter
	else if(menu_demarrage == 5){
		return 0;
	}
	*/

	return 0;
}
