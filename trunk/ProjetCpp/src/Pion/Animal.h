/*
 * Animal.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "../Pion.h"

class Animal: public Pion {
// attributs
private:
	int valeur;

// méthodes
public:
	Animal(int v = 0) :
			valeur(v) {
	};
	virtual ~Animal() {
	};

	// getters
	int getValeur() {
		return valeur;
	}

};

#endif /* ANIMAL_H_ */
