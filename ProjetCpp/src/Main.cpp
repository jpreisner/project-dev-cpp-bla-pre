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
#include "Pion/Animal/Peureux/Gazelle.h"
#include "Pion/Animal/Neutre/Elephant.h"
#include "Pion/Animal/Peureux/Zebre.h"

class AffichageConsole;


using namespace std;

int main() {
	cout << "Projet Jeu de Role" << endl; // prints w�w�w� Ma Geule

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
	/*
	for (i = 0; i < j.getListAnimaux().size(); i++) {
		cout << "listAnimaux[" << i << "]=" << j.getAnimal(i)->print() << endl;
	}
	*/

	ImpalaJones ij(1, 0);
	AffichageConsole affichage;
	Plateau p;
	p.initImpalaJones(&ij);
	affichage.affichePlateau(p);

	Joueur* ptJ = &j;

	Animal* pt1 = j.getAnimal(0);	// gazelle
	Animal* pt2 = j.getAnimal(6);	// zebre
	Animal* pt3 = j.getAnimal(11);	// elephant

	cout << "Affichage des animaux � ajouter (apres pointeur)" << endl;

	cout << "A1 = " << pt1->print() << endl;
	cout << "A2 = " << pt2->print() << endl;
	cout << "A3 = " << pt3->print() << endl;


	p.ajouterAnimal(5,2,pt1);
	p.ajouterAnimal(6,2,pt2);
	p.ajouterAnimal(6,3,pt3);
	cout<<"Affichage du plateau :" <<endl;
	affichage.affichePlateau(p);

	p.bonusInauguration();
	
	cout << "Test d'un joueur apr�s bonus inauguration : "<<j << endl;

	if(p.supprimerPion(5,2)){
		cout<<"Pion Bien supprim�"<<endl;
	}
	affichage.affichePlateau(p);

	// cases a remplir

	// Ajout d'un lion
	cout<<"Test methode joueur d'un joueur"<<endl;
	Plateau* ptPlateau = &p;
	ptJ->jouer(3,4,4,ptPlateau);
	affichage.affichePlateau(p);


	cout << "Test D�placement de ImpalaJones" << endl;
	//ImpalaJones ij(1, 0);
	ij.deplacer(3, ptPlateau);
	ij.deplacer(3, ptPlateau);
	cout << ij << endl;
	affichage.affichePlateau(p);

	cout << ij << endl;
	ij.deplacer(3, &p);
	cout << ij << endl;
	affichage.affichePlateau(p);

	/* Test de l'affichage des regles
	affichage.afficheRegle();
	*/

	/*
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
	cout << "            Dr�le de Z�bres           " << endl;
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
	// Afficher les r�gles
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
