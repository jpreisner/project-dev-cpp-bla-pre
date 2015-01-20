/*
 * Neutre.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef NEUTRE_H_
#define NEUTRE_H_

#include "../Animal.h"

class Neutre: public Animal {
public:
	Neutre(int v = 0) :
			Animal(v) {
	}
	virtual ~Neutre();
};

#endif /* NEUTRE_H_ */
