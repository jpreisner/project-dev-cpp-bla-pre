/*
 * Crocodile.h
 *
 *  Created on: 26 janv. 2015
 *      Author: Julien
 */

#ifndef PION_ANIMAL_EFFRAYANT_CROCODILE_H_
#define PION_ANIMAL_EFFRAYANT_CROCODILE_H_

#include "../Effrayant.h"

class Crocodile: public Effrayant {
public:
	Crocodile(){
		Effrayant(0);
	};
	virtual ~Crocodile(){};

	friend ostream& operator<<(ostream &strm, const Crocodile &a) {
		return strm << "Crocodile" << endl;
	}
};

#endif /* PION_ANIMAL_EFFRAYANT_CROCODILE_H_ */
