/*
 * Pion.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PION_H_
#define PION_H_

#include <iostream>

using namespace std;

class Pion {
public:
	Pion() {

	}
	virtual ~Pion() {

	}

	friend ostream& operator<<(ostream &strm, const Pion &a) {
		return strm << "Pion" << endl;
	}
};


#endif /* PION_H_ */
