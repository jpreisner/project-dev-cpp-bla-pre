/*
 * Zebre.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ZEBRE_H_
#define ZEBRE_H_

#include "../Effrayant/Lion.h"
#include "../Peureux.h"

class Zebre: public Peureux {
public:
	Zebre() :
			Peureux(6) {

	}
	~Zebre(){
	}

	friend ostream& operator<<(ostream &strm, const Zebre &a) {
		return strm << "Zebre" << endl;
	}
};

#endif /* ZEBRE_H_ */
