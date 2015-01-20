/*
 * Ordinateur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_

#include "Joueur.h"

class Ordinateur: public Joueur {
public:
	Ordinateur() {
	}
	virtual ~Ordinateur();
};

#endif /* ORDINATEUR_H_ */
