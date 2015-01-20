/*
 * Plateau.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <vector>
#include "Joueur.h"
#include "Pion.h"

using namespace std;

class Plateau {
public:
	Plateau() {
	}
	virtual ~Plateau();
private:
	Joueur joueur1;
	Joueur joueur2;
	vector<Pion> listPionPlateau;

};

#endif /* PLATEAU_H_ */
