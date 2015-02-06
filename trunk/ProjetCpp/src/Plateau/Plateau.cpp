/*
 * Plateau.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Plateau.h"

#include <iostream>

/**
 * Deplacement du pion sur le plateau
 */
int Plateau::deplacerPion() {

	return 0;
}

/** A enlever car présent dans la classe Affichage **/
string Plateau::print() {
	string s = "";
	for (int i = 0; i < TAILLE_PLATEAU_Y; i++) {
		for (int j = 0; j < TAILLE_PLATEAU_X; j++) {

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
					if (cases[j][i].getPion() != NULL) {
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
				if (cases[j][i].getPion() != NULL) {
					cout << " " << cases[j][i].getPion() << " ";
				} else {
					cout << "   ";
				}

				if (cases[j][i].getSecteur() != cases[j + 1][i].getSecteur()) {
					cout << "  |";
				} else {
					cout << "   ";
				}
			}
		}
		cout << "\n";
		if (i < TAILLE_PLATEAU_Y - 1) {
			for (int k = 0; k < TAILLE_PLATEAU_X; k++) {
				if (k == 0 || k == TAILLE_PLATEAU_X - 1
						|| cases[k][i].getSecteur()
								!= cases[k][i + 1].getSecteur()) {
					cout << " ___  ";
				} else {
					cout << "      ";
				}
			}
		}
		cout << "\n";

	}

	return s;
}

int Plateau::ajouterAnimal(int x, int y, Animal &a) {
	return getCase(x, y).ajouterPion(a);
}

