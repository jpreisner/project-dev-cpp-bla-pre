/*Gazelle.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef GAZELLE_H_
#define GAZELLE_H_

#include "../Effrayant/Lion.h"
#include "../Peureux.h"

class Lion;

class Gazelle: public Peureux {
public:
	Gazelle() : Peureux(2) {};
	virtual ~Gazelle() {};

	friend ostream& operator<<(ostream &strm, const Gazelle &a) {
		return strm << "Gazelle" << endl;
	}
};

#endif /* GAZELLE_H_ */
