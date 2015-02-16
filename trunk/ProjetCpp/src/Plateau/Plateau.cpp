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
	Joueur* joueur = NULL;
	for (int i = 1; i < TAILLE_PLATEAU_X - 1; ++i) {
		for (int j = 1; j < TAILLE_PLATEAU_Y - 1; ++j) {
			if (getCase(i, j)->getSecteur() == secteur) {
				if (getCase(i, j)->getPion() == NULL) {
					/* pas de pion sur la case*/
					return false;
				} else {
					/* il y a un pion sur la case*/
					if (joueur == NULL) {
						Animal* a = (Animal*) getCase(i, j)->getPion();
						joueur = a->getJoueur();
					} else {
						Animal* a = (Animal*) getCase(i, j)->getPion();
						if (joueur != a->getJoueur()) {
							return false;

						}
					}
				}
			}
		}
	}
	return true;
}

bool Plateau::bonusInauguration(){
	for (int i = SECT1; i <= SECT6; i++) {
		if (secteurRempli(i)) {
			for (int j = 1; j < TAILLE_PLATEAU_X - 1; j++) {
				for (int k = 1; k < TAILLE_PLATEAU_Y - 1; k++) {
					if (getCase(j, k)->getSecteur() == i) {
						Animal* a = (Animal*) getCase(j, k)->getPion();
						a->getJoueur()->ajouterPoints(5);
						return true;
						/* Ajout OK */
					}
				}
			}
		}
	}
	return false;
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
	return getCase(ij->getX(), ij->getY())->ajouterPion(ij);
}

void Plateau::echangerAnimalCases(Animal* a1, Animal* a2){
	int x_a1 = a1->getX();
	int y_a1 = a1->getY();
	int x_a2 = a2->getX();
	int y_a2 = a2->getY();

	a1->setX(x_a2);
	a1->setY(y_a2);
	a2->setX(x_a1);
	a2->setY(y_a2);

	getCase(x_a1, y_a1)->supprimerPion();
	getCase(x_a2, y_a2)->supprimerPion();

	getCase(x_a1, y_a1)->ajouterPion(a2);
	getCase(x_a2, y_a2)->ajouterPion(a1);
}

