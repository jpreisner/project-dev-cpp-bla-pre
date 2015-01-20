/*
 * Plateau.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <vector>

#include "../Joueur.h"
#include "../Pion.h"
#include "Case.h"

using namespace std;

class Plateau {
public:
	Plateau() {
	}
	virtual ~Plateau(){

	}
private:
	vector<Pion> listPionPlateau;
	Case cases[6][5];
};

#endif /* PLATEAU_H_ */
