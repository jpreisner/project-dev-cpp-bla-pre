/*
 * Lion.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef LION_H_
#define LION_H_

#include <iostream>
#include <string>
#include <sstream>

#include "../../../Joueur.h"
#include "../../Animal.h"
#include "../Effrayant.h"

using namespace std;

class Lion: public Effrayant {
public:
	Lion(Joueur* j) : Effrayant(1,j) {
	};
	~Lion() {};

	virtual string print() const {
		ostringstream id;
		id << getJoueur()->getId();
		return "(L," + id.str() + ")";
	}
	void action(Plateau *p, Affichage *affichage);
};

#endif /* LION_H_ */
