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

	Joueur j(0, "Zizou", nbGazelles, nbZebres, nbElephants, nbLions, nbCrocos);
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

	Joueur* ptJ = &j;

	Animal a1 = Gazelle(ptJ);
	Animal a2 = Zebre(ptJ);
	Animal a3 = Elephant(ptJ);

	Animal* pt1 = &a1;
	Animal* pt2 = &a2;
	Animal* pt3 = &a3;


	p.ajouterAnimal(5,2,pt1);
	p.ajouterAnimal(6,2,pt2);
	p.ajouterAnimal(6,3,pt3);
	affichage.affichePlateau(p);

	cout<<"AVANT BONUS INNAUGURATION"<<endl;
	p.bonusInauguration();
	cout<<"APRES BONUS INNAUGURATION"<<endl;
	cout << j << endl;

	if(p.supprimerPion(5,2)){
		cout<<"Pion Bien supprimé"<<endl;
	}
	affichage.affichePlateau(p);

	/* cases a remplir*/

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
