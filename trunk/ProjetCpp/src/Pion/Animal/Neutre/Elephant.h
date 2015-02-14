/*
 * Elephant.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ELEPHANT_H_
#define ELEPHANT_H_

#include <string>

#include "../Neutre.h"

class Elephant: public Neutre {
public:
	Elephant(Joueur* j) : Neutre(1,j) {};
	~Elephant() {};

	virtual string print() const {
		return "Elephant";
	}
};

#endif /* ELEPHANT_H_ */
