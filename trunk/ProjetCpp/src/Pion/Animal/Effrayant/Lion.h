/*
 * Lion.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef LION_H_
#define LION_H_

#include "../Effrayant.h"
#include "../Peureux/Gazelle.h"
#include "../Peureux/Zebre.h"

using namespace std;

class Lion: public Effrayant {
public:
	Lion() :
			Effrayant(1) {

	}
	~Lion() {
	}

	friend ostream& operator<<(ostream &strm, const Lion &a) {
		return strm << "Lion" << endl;
	}
};

#endif /* LION_H_ */
