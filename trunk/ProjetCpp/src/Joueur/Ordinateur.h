/*
 * Ordinateur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_

#include <string>

#include "../Joueur.h"

class Ordinateur: public Joueur {
public:
	Ordinateur() :
			Joueur(0, "I-A") {
	}
	virtual ~Ordinateur() {

	}
};

#endif /* ORDINATEUR_H_ */
