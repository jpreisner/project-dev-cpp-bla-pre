/*
 * Zebre.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ZEBRE_H_
#define ZEBRE_H_

#include <string>

#include "../Peureux.h"

class Zebre: public Peureux {
public:
	Zebre(Joueur* j) : Peureux(6,j) {};
	~Zebre(){};

	virtual string print() const {
		return "Zebre";
	}
};

#endif /* ZEBRE_H_ */
