/*
 * Personnage.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "../Pion.h"

class Plateau;

class ImpalaJones: public Pion {
public:
	ImpalaJones(){};
	virtual ~ImpalaJones(){};

	// nbCases doit etre compris entre 1 et 3
	int deplacer(int nbCases, Plateau plateau);
};

#endif /* PERSONNAGE_H_ */
