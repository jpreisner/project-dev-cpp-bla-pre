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
