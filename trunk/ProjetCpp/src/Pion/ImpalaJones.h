/*
 * Personnage.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include <string>

#include "../Pion.h"

class Plateau;

class ImpalaJones: public Pion {
public:
	ImpalaJones(int pos_x=1, int pos_y=0) : Pion(pos_x, pos_y){};
	virtual ~ImpalaJones(){};

	// nbCases doit etre compris entre 1 et 3
	int deplacer(int nbCases, Plateau *plateau);

	friend ostream& operator<<(ostream &strm, const ImpalaJones &ij) {
		return strm << "ImpalaJones (" << ij.getX() << ", " << ij.getY() << ")" << endl;
	}

	string print() const{
		return "ImpalaJones";
	}
};

#endif /* PERSONNAGE_H_ */
