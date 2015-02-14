/*
 * Crocodile.h
 *
 *  Created on: 26 janv. 2015
 *      Author: Julien
 */

#ifndef PION_ANIMAL_EFFRAYANT_CROCODILE_H_
#define PION_ANIMAL_EFFRAYANT_CROCODILE_H_

#include <string>

#include "../Effrayant.h"

class Crocodile: public Effrayant {
public:
	Crocodile(Joueur* j) : Effrayant(0,j) {};
	~Crocodile(){};

	virtual string print() const {
		return "Crocodile";
	}

};

#endif /* PION_ANIMAL_EFFRAYANT_CROCODILE_H_ */
