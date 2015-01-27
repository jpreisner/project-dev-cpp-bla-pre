/*
 * Elephant.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ELEPHANT_H_
#define ELEPHANT_H_

#include "../Neutre.h"

class Elephant: public Neutre {
public:
	Elephant() : Neutre(1) {};
	~Elephant() {};

	friend ostream& operator<<(ostream &strm, const Elephant &a) {
		return strm << "Elephant" << endl;
	}
};

#endif /* ELEPHANT_H_ */
