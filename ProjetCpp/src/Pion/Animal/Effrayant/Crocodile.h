/*
 * Crocodile.h
 *
 *  Created on: 26 janv. 2015
 *      Author: Guillaume
 */

#ifndef PION_ANIMAL_EFFRAYANT_CROCODILE_H_
#define PION_ANIMAL_EFFRAYANT_CROCODILE_H_

#include "../Effrayant.h"

class Crocodile : public Effrayant{
public:
	Crocodile() {
	}

	virtual ~Crocodile(){

	}

	friend ostream& operator<<(ostream &strm, const Crocodile &a) {
		return strm << "Cocodile" << endl;
	}
};

#endif /* PION_ANIMAL_EFFRAYANT_CROCODILE_H_ */
