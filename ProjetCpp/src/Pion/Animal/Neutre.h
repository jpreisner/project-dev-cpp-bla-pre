/*
 * Neutre.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef NEUTRE_H_
#define NEUTRE_H_

#include <string>

#include "../Animal.h"

class Neutre: public Animal {
public:
	Neutre(int v = 0, Joueur* j = NULL) : Animal(v,j) {};
	virtual ~Neutre(){};

	virtual string print() const{
		return "Neutre";
	}
};

#endif /* NEUTRE_H_ */
