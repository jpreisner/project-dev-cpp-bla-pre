/*
 * Plateau.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <string>

#include "Case.h"

#define TAILLE_PLATEAU_X 8
#define TAILLE_PLATEAU_Y 7

using namespace std;

class Pion;

class Plateau {
private:
	Case cases[TAILLE_PLATEAU_X][TAILLE_PLATEAU_Y];

public:
	Plateau() {
		/* remplissage manuel des zones*/
		cases[1][1] = Case(1);
		cases[1][2] = Case(1);
		cases[5][2] = Case(1);
		cases[6][2] = Case(1);
		cases[1][3] = Case(1);
		cases[2][3] = Case(1);
		cases[6][3] = Case(1);
		cases[2][4] = Case(1);
		cases[2][1] = Case(2);
		cases[2][2] = Case(2);
		cases[3][2] = Case(2);
		cases[3][3] = Case(2);
		cases[1][4] = Case(2);
		cases[3][4] = Case(2);
		cases[4][4] = Case(2);
		cases[5][4] = Case(2);
		cases[1][5] = Case(2);
		cases[2][5] = Case(2);
		cases[3][1] = Case(3);
		cases[4][1] = Case(3);
		cases[5][1] = Case(3);
		cases[6][1] = Case(3);
		cases[4][2] = Case(3);
		cases[4][3] = Case(3);
		cases[5][3] = Case(3);
		cases[6][4] = Case(3);
		cases[3][5] = Case(3);
		cases[4][5] = Case(3);
		cases[5][5] = Case(3);
		cases[6][5] = Case(3);
	}
	virtual ~Plateau() {
	}

	int deplacerPion();

	Case getCase(int x, int y) {
		return cases[x][y];
	}

	string print();
};

#endif /* PLATEAU_H_ */
