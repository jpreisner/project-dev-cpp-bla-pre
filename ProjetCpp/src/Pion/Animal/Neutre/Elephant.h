/*
 * Elephant.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ELEPHANT_H_
#define ELEPHANT_H_

#include <string>

#include "../../../Joueur.h"
#include "../../Animal.h"
#include "../Neutre.h"

class Elephant: public Neutre {
public:
	Elephant(Joueur* j) : Neutre(1,j) {};
	~Elephant() {};

	virtual string print() const {
		ostringstream id;
		id << getJoueur()->getId();
		return "(E," + id.str() + ")";
	}
	int action(Plateau *p){return 0;}
};

#endif /* ELEPHANT_H_ */
