/*
 * Plateau.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <vector>

#include "../Pion.h"
#include "Case.h"

#define TAILLE_PLATEAU_X 8
#define TAILLE_PLATEAU_Y 7

using namespace std;

class Pion;

class Plateau {
private:
	vector<Pion> listPionPlateau;
	Case cases[TAILLE_PLATEAU_X][TAILLE_PLATEAU_Y];

public:
	Plateau() {
	}
	virtual ~Plateau() {
	}
	
	int deplacerPion();

	const vector<Pion>& getListPionPlateau() const {
		return listPionPlateau;
	}

	Case getCase(int x, int y) {
		return cases[x][y];
	}
};

#endif /* PLATEAU_H_ */
