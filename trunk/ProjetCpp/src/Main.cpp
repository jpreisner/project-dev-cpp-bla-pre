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

#include "Affichage/AffichageConsole.h"
#include "Joueur/JoueurReel.h"
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
	JoueurReel j("Zizou");
	cout << j << endl;

	cout << "Test affichage de la liste de pion" << endl;
	AffichageConsole affichage;
	affichage.afficheListAnimal(j.getListAnimaux());



	ImpalaJones ij(1, 0);
	Plateau p;
	p.initImpalaJones(&ij);
	affichage.affichePlateau(p);

	Joueur* ptJ = &j;

	Animal* pt1 = j.getAnimal(0);	// gazelle
	Animal* pt2 = j.getAnimal(6);	// zebre
	Animal* pt3 = j.getAnimal(11);	// elephant

	cout << "Affichage des animaux à ajouter (apres pointeur)" << endl;

	cout << "A1 = " << pt1->print() << endl;
	cout << "A2 = " << pt2->print() << endl;
	cout << "A3 = " << pt3->print() << endl;


	p.ajouterAnimal(5,2,pt1);
	p.ajouterAnimal(6,2,pt2);
	p.ajouterAnimal(6,3,pt3);
	cout<<"Affichage du plateau :" <<endl;
	affichage.affichePlateau(p);
	
	cout << "Test d'un joueur après bonus inauguration : "<<j << endl;
/*
	if(p.supprimerPion(5,2)){
		cout<<"Pion Bien supprimé"<<endl;
	}*/
	affichage.affichePlateau(p);

	// cases a remplir

	// Ajout d'un lion
	cout<<"Test methode joueur d'un joueur"<<endl;
	Plateau* ptPlateau = &p;
	ptJ->jouer(3,4,ptPlateau,&affichage);
	affichage.affichePlateau(p);


	cout << "Test Déplacement de ImpalaJones" << endl;
	//ImpalaJones ij(1, 0);
	ij.deplacer(3, ptPlateau);
	ij.deplacer(3, ptPlateau);
	cout << ij << endl;
	affichage.affichePlateau(p);

	cout << ij << endl;
	ij.deplacer(3, &p);
	cout << ij << endl;
	affichage.affichePlateau(p);

	cout<<p.getCase(5,2)->getPion()->getX()<<endl;
	p.echangerAnimalCases(pt1,pt2);
	affichage.affichePlateau(p);
	cout<<p.getCase(5,2)->getPion()->getX()<<endl;

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
