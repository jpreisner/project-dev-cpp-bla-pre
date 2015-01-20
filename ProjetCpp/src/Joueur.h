/*
 * Joueur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_
#include <string>
#include <vector>
#include "Pion.h"

using namespace std;

class Joueur {
public:
	Joueur(int nbPoints = 0, string nom = "") : nbPoints(nbPoints), nom(nom) {
	}
	virtual ~Joueur();
protected:
	int nbPoints;
	string nom;
	vector<Pion> listPions;
};

#endif /* JOUEUR_H_ */
