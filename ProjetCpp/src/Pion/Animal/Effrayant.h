/*
 * Effrayant.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef EFFRAYANT_H_
#define EFFRAYANT_H_

#include <string>
#include <vector>

#include "../Animal.h"

using namespace std;

class Effrayant: public Animal {

public:
	Effrayant(int v = 0, Joueur* j = NULL) : Animal(v,j) {};
	virtual ~Effrayant(){};

	virtual string print() const{
		return "Effrayant";
	}
};

#endif /* EFFRAYANT_H_ */
