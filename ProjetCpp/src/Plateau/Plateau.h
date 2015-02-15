/*
 * Plateau.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <string>

#include "../Pion/Animal.h"
#include "../Pion/ImpalaJones.h"
#include "../Pion.h"
#include "Case.h"

#define TAILLE_PLATEAU_X 8
#define TAILLE_PLATEAU_Y 7

using namespace std;

class Pion;

class Plateau {
private:
	Case cases[TAILLE_PLATEAU_X][TAILLE_PLATEAU_Y];
	enum secteurs : int{SECT1 = 1, SECT2 = 2, SECT3 = 3, SECT4 = 4, SECT5 = 5, SECT6 = 6};
public:
	Plateau() {
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
	virtual ~Plateau() {
	}

	int deplacerPion();

	int ajouterAnimal(int x, int y, Animal* a);

	/* Ajout d'ImpalaJones sur la case 1/0 */
	int initImpalaJones(ImpalaJones *ij);

	Case* getCase(int x, int y) {
		return &cases[x][y];
	}

	int getTaillePlateauX(){
		return TAILLE_PLATEAU_X;
	}
	int getTaillePlateauY(){
		return TAILLE_PLATEAU_Y;
	}

	/**
	 * Afficahge du plateau
	 */
	string print();

	/**
	 * return true si le secteur i est rempli par un seul joueur
	 */
	bool secteurRempli(int secteur);

	/* return true si le bonus Inauguration a ete donne */
	bool bonusInauguration();

	/* supprime le pion sur la case i/j*/
	bool supprimerPion(int x, int y);
};

#endif /* PLATEAU_H_ */
