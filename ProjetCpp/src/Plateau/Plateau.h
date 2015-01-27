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

using namespace std;

class Pion;

class Plateau {
private:
	vector<Pion> listPionPlateau;
	Case cases[8][7];

public:
	Plateau() {
	}
	virtual ~Plateau() {
	}
	int deplacerPion();

};

#endif /* PLATEAU_H_ */
