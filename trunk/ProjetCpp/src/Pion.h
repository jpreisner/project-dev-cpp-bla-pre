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

	virtual string print() const{
		return "Pion";
	}
	int setPosition(int x, int y){

		return 0;
	}
};


#endif /* PION_H_ */
