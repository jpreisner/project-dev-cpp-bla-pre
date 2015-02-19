/*
 * Plateau.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Plateau.h"

#include <iostream>

#include "../Joueur.h"

/**
 * Deplacement du pion sur le plateau
 */
int Plateau::deplacerPion(){
	return 0;
}

int Plateau::ajouterAnimal(int x, int y, Animal* a){
	a->setY(y);
	a->setX(x);
	return getCase(x, y)->ajouterPion(a);
}

bool Plateau::secteurRempli(int secteur){
	for (int i = 1; i < TAILLE_PLATEAU_X - 1; ++i) {
		for (int j = 1; j < TAILLE_PLATEAU_Y - 1; ++j) {
			if (getCase(i, j)->getSecteur() == secteur) {
				if (getCase(i, j)->getPion() == NULL) {
					/* pas de pion sur la case*/
					return false;
				}
			}
		}
	}
	return true;
}

bool Plateau::supprimerPion(int x, int y){
	if (getCase(x, y) != NULL) {
		getCase(x, y)->supprimerPion();
		return true;
	} else {
		return false;
	}
}

int Plateau::initImpalaJones(ImpalaJones *ij){
	setImpalaJones(ij);
	return getCase(ij->getX(), ij->getY())->ajouterPion(ij);
}

void Plateau::echangerAnimalCases(Animal* a1, Animal* a2){
	int x_a1 = a1->getX();
	int y_a1 = a1->getY();
	int x_a2 = a2->getX();
	int y_a2 = a2->getY();

	// Suppression des pions
	if(getCase(x_a1, y_a1)->supprimerPion() == -1){
		cout << "Erreur pour supprimer l'animal " << a1->print() << " qui n'est pas présent en (" << x_a1 << ", " << y_a1 << ")" << endl;
	}
	if(getCase(x_a2, y_a2)->supprimerPion() == -1){
		cout << "Erreur pour supprimer l'animal " << a2->print() << " qui n'est pas présent en (" << x_a2 << ", " << y_a2 << ")" << endl;
	}

	a1->setX(x_a2);
	a1->setY(y_a2);
	a2->setX(x_a1);
	a2->setY(y_a1);

	// Ajout des pions
	if(getCase(x_a1, y_a1)->ajouterPion(a2) == -1){
		cout << "Erreur pour ajouter l'animal " << a2->print() << " en (" << x_a1 << ", " << y_a1 << ")" << endl;
	}
	if(getCase(x_a2, y_a2)->ajouterPion(a1) == -1){
		cout << "Erreur pour ajouter l'animal " << a1->print() << " en (" << x_a2 << ", " << y_a2 << ")" << endl;
	}

}

void Plateau::initPlateau(int num_plateau){
	if(num_plateau == 1){
		initPlateauNormal();
	}
	else{
		initPlateauReservePresident();
	}
}

void Plateau::initPlateauNormal(){
		/* ZONE 1 */
		cases[1][1] = Case(SECT1);
		cases[1][2] = Case(SECT1);
		cases[1][3] = Case(SECT1);
		cases[2][3] = Case(SECT1);
		cases[2][4] = Case(SECT1);

		/* ZONE 2 */
		cases[2][1] = Case(SECT2);
		cases[2][2] = Case(SECT2);
		cases[3][2] = Case(SECT2);
		cases[3][3] = Case(SECT2);
		cases[3][4] = Case(SECT2);
		cases[4][4] = Case(SECT2);
		cases[5][4] = Case(SECT2);

		/* ZONE 3 */
		cases[3][1] = Case(SECT3);
		cases[4][1] = Case(SECT3);
		cases[5][1] = Case(SECT3);
		cases[6][1] = Case(SECT3);
		cases[4][2] = Case(SECT3);
		cases[4][3] = Case(SECT3);
		cases[5][3] = Case(SECT3);

		/* ZONE 4 */
		cases[5][2] = Case(SECT4);
		cases[6][2] = Case(SECT4);
		cases[6][3] = Case(SECT4);

		/* ZONE 5 */
		cases[1][4] = Case(SECT5);
		cases[1][5] = Case(SECT5);
		cases[2][5] = Case(SECT5);

		/* ZONE 6 */
		cases[6][4] = Case(SECT6);
		cases[3][5] = Case(SECT6);
		cases[4][5] = Case(SECT6);
		cases[5][5] = Case(SECT6);
		cases[6][5] = Case(SECT6);
}

void Plateau::initPlateauReservePresident(){
		/* ZONE 1 */
		cases[1][1] = Case(SECT1);
		cases[1][2] = Case(SECT1);
		cases[1][3] = Case(SECT1);

		/* ZONE 2 */
		cases[1][4] = Case(SECT2);
		cases[2][4] = Case(SECT2);
		cases[2][3] = Case(SECT2);
		cases[2][2] = Case(SECT2);
		cases[3][2] = Case(SECT2);

		/* ZONE 3 */
		cases[1][5] = Case(SECT3);
		cases[2][5] = Case(SECT3);
		cases[3][5] = Case(SECT3);
		cases[4][5] = Case(SECT3);
		cases[3][4] = Case(SECT3);
		cases[3][3] = Case(SECT3);
		cases[4][3] = Case(SECT3);

		/* ZONE 4 */
		cases[4][4] = Case(SECT4);
		cases[5][4] = Case(SECT4);
		cases[5][5] = Case(SECT4);

		/* ZONE 5 */
		cases[2][1] = Case(SECT5);
		cases[3][1] = Case(SECT5);
		cases[4][1] = Case(SECT5);
		cases[4][2] = Case(SECT5);
		cases[5][2] = Case(SECT5);
		cases[5][3] = Case(SECT5);
		cases[6][3] = Case(SECT5);
		cases[6][4] = Case(SECT5);
		cases[6][5] = Case(SECT5);

		/* ZONE 6 */
		cases[5][1] = Case(SECT6);
		cases[6][1] = Case(SECT6);
		cases[6][2] = Case(SECT6);
	}
