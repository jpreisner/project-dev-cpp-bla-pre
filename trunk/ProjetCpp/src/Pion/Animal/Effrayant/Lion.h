/*
 * Lion.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef LION_H_
#define LION_H_

#include <string>

#include "../Effrayant.h"

using namespace std;

class Lion: public Effrayant {
public:
	Lion() : Effrayant(1) {};
	~Lion() {};

	virtual string print() const {
		return "Lion";
	}
};

#endif /* LION_H_ */
