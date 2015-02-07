/*
 * AffichageConsole.cpp
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#include "AffichageConsole.h"

#include <iostream>
#include <string>

#include "Joueur.h"
#include "Plateau/Case.h"
#include "Plateau/Plateau.h"

int AffichageConsole::menuDemarrage() {
	cout << "======================================" << endl;
	cout << "Bienvenue dans le jeu Drole de Zebres!" << endl;
	cout << "   1 - Jouer" << endl;
	cout << "   2 - Regles" << endl;
	cout << "   3 - Quitter" << endl;
	cout << "======================================" << endl;
	int res;
	cin >> res;
	while (!(res >= 1 && res <= 4)) {
		cout << "Erreur ! Veuillez entrer un chiffre compris entre 1 et 3"
				<< endl;
		cout << "======================================" << endl;
		cout << "Bienvenue dans le jeu Drole de Zebres!" << endl;
		cout << "   1 - Jouer (Joueur vs Ordi)" << endl;
		cout << "   2 - Jouer (Joueur vs Joueur)" << endl;
		cout << "   3 - Regles" << endl;
		cout << "   4 - Quitter" << endl;
		cout << "======================================" << endl;
		cin >> res;
	}
	return res;
}

int AffichageConsole::afficheRegle() {

	/** Faire un affichage des regles qui sont dans un texte **/

	int res;
	cout << "======================================" << endl;
	cout << "Entrez 1 pour retourner au menu" << endl;
	cin >> res;
	while (res != 1) {
		cout << "======================================" << endl;
		cout << "Erreur ! Veuillez entrer 1 pour retourner au menu" << endl;
		cin >> res;
	}
	return res;
}

void AffichageConsole::demandeNomJoueur(Joueur *j, int numJoueur) {
	cout << "======================================" << endl;
	cout << "Veuillez entrer le nom du joueur n°" << numJoueur << " : " << endl;
	cout << "======================================" << endl;
	string nom;
	cin >> nom;
	/** Verifier si le nom est correct? Comment? **/
	j->setNom(nom);
}

void AffichageConsole::affichePlateau(Plateau p) {
	/*string s = ""; */
	for (int i = 0; i < p.getTaillePlateauY(); i++) {
		for (int j = 0; j < p.getTaillePlateauX(); j++) {

			/* Affichage des cases d'IMPALA JONES*/
			if (i == 0 || i == 6 || j == 0 || j == 7) {
				//CASES NON ACCESSIBLES
				if ((i == 0 && j == 0) || (i == 6 && j == 0)) {
					//en haut à gauche ou en bas a gauche
					cout << "  X  |";
				} else if ((i == 0 && j == 7) || (i == 6 && j == 7)) {
					//en haut à droite ou en bas à droite
					cout << "  X  ";
				} else {
					// CASES ACCESSIBLES
					if (p.getCase(j, i).getPion() != NULL) {
						if (j == 7) {
							cout << "  I ";
						} else {
							cout << "  I  |";
						}
					} else {
						if (j == 7) {
							cout << "     ";
						} else {
							cout << "     |";
						}
					}
				}
			} else {
				/* Affichage des zones du jeu et des PIONS */
				if (p.getCase(j, i).getPion() != NULL) {
					cout << " " <<p.getCase(j, i).getPion() << " ";
				} else {
					cout << "   ";
				}

				if (p.getCase(j, i).getSecteur() != p.getCase(j+1, i).getSecteur()) {
					cout << "  |";
				} else {
					cout << "   ";
				}
			}
		}
		cout << "\n";
		if (i < p.getTaillePlateauY() - 1) {
			for (int k = 0; k < p.getTaillePlateauX(); k++) {
				if (k == 0 || k == p.getTaillePlateauX() - 1
						|| p.getCase(k, i).getSecteur()
								!= p.getCase(k, i+1).getSecteur()) {
					cout << " ___  ";
				} else {
					cout << "      ";
				}
			}
		}
		cout << "\n";

	}
	/*cout << s << endl;*/
}

int AffichageConsole::demandeDeplacerImpalaJones(){
	cout << "Déplacement d'Impala Jones : veuillez choisir un nombre compris entre 1 et 3" << endl;
	int res;
	cin >> res;
	while(!(res>=1 && res<=3)){
		cout << "Erreur! Veuillez choisir un nombre compris entre 1 et 3" << endl;
		cin >> res;
	}
	return res;
}

void AffichageConsole::afficheListAnimal(vector<Animal*> listAnimaux){
	int nbPion = listAnimaux.size();
	int i;
	cout << "(";
	for(i=0; i<nbPion; i++){
		cout << listAnimaux[i]->print() << "[n°" << i << "]";
		if(i == nbPion-1){
			cout << ")" << endl;
		}
		else{
			cout << " - ";
		}
	}
}


int AffichageConsole::selectionnerAnimal(vector<Animal*> listAnimaux){
	int nbPion = listAnimaux.size();
	cout << "Voici votre liste de pion : " << endl;
	cout << "---> ";
	afficheListAnimal(listAnimaux);
	cout << "Sélectionner l'animal que vous souhaitez poser sur le plateau selon sa position dans votre liste de pion" << endl;
	int positionAnimal;
	cin >> positionAnimal;
	while(!(positionAnimal>=0 && positionAnimal<=(nbPion-1))){
		cout << "Erreur ! Veuillez entrer un nombre compris entre 0 et " << (nbPion-1) << endl;
		cout << "Voici votre liste de pion : " << endl;
		cout << "---> ";
		afficheListAnimal(listAnimaux);
		cout << "Sélectionner l'animal que vous souhaitez poser sur le plateau selon sa position dans votre liste de pion" << endl;
		cin >> positionAnimal;
	}

	return positionAnimal;
}

void AffichageConsole::selectionnerPosition(int *x, int *y){

	/** A COMPLETER **/

	/*
	cout << "Selectionnez une case" << endl;
	int i, j;
	cin >> i;
	cin >> j;
	*/
}


