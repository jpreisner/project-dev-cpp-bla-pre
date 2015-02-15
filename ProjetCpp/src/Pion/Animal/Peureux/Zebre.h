/*
 * Zebre.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ZEBRE_H_
#define ZEBRE_H_

#include <iostream>
#include <string>

#include "../../../Joueur.h"
#include "../../Animal.h"
#include "../Peureux.h"

class Zebre: public Peureux {
public:
	Zebre(Joueur* j) : Peureux(6,j) {};
	~Zebre(){};

	string print() const {
		ostringstream id;
		id << getJoueur()->getId();
		return "(Z," + id.str() + ")";
	}
};

#endif /* ZEBRE_H_ */
