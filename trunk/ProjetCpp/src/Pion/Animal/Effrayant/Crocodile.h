/*
 * Crocodile.h
 *
 *  Created on: 26 janv. 2015
 *      Author: Julien
 */

#ifndef PION_ANIMAL_EFFRAYANT_CROCODILE_H_
#define PION_ANIMAL_EFFRAYANT_CROCODILE_H_

#include <string>

#include "../../../Joueur.h"
#include "../../Animal.h"
#include "../Effrayant.h"

class Crocodile: public Effrayant {
public:
	Crocodile(Joueur* j) : Effrayant(0,j) {};
	~Crocodile(){};

	virtual string print() const {
		ostringstream id;
		id << getJoueur()->getId();
		return "(C," + id.str() + ")";
	}
	int action(Plateau *p, Affichage *affichage);

};

#endif /* PION_ANIMAL_EFFRAYANT_CROCODILE_H_ */
