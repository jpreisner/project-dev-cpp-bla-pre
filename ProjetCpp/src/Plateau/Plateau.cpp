/*
 * Plateau.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Plateau.h"

/**
 * Deplacement du pion sur le plateau
 */
int Plateau::deplacerPion() {

	return 0;
}

string Plateau::print() {
	string s = "";
	for (int i = 0; i < TAILLE_PLATEAU_Y; i++) {
		for (int j = 0; j < TAILLE_PLATEAU_X; j++) {
			if (i == 0 || i == 6 || j == 0 || j == 7) {
				/* Affichage des cases d'IMPALA JONES*/
				if (i == 0 && j == 0) {
					//en haut à gauche
					cout << "  X  |";
				} else if (i == 0 && j == 7) {
					//en haut à droite
					cout << "  X  ";
				} else if (i == 6 && j == 0) {
					//en bas à gauche
					cout << "  X  |";
				} else if (i == 6 && j == 7) {
					//en bas à droite
					cout << "  X  ";
				} else {
					// autres cases
					if (cases[j][i].getPion() != NULL) {
						cout << "  I  |";
					} else {
						if(j==7){
							cout << "     ";
						}else{
							cout << "     |";
						}
					}
				}
			} else {
				/* Affichage des zones du jeu*/
				cout << "  A  |";
			}
		}
		cout << "\n";
		if (i < TAILLE_PLATEAU_Y - 1) {
			for (int k = 0; k < TAILLE_PLATEAU_X; k++) {
				cout << " ___  ";
			}
		}
		cout << "" << endl;

	}

	return s;
}
