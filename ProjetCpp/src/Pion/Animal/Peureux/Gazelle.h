/*Gazelle.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef GAZELLE_H_
#define GAZELLE_H_

#include <string>

#include "../Peureux.h"

class Lion;

class Gazelle: public Peureux {
public:
	Gazelle() : Peureux(2) {};
	~Gazelle() {};

	virtual string print() const {
		return "Gazelle";
	}
};

#endif /* GAZELLE_H_ */