/*
 * Pion.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PION_H_
#define PION_H_

#include <string>

using namespace std;

class Pion {
private:
	int x;	// position horizontale
	int y;	// position verticale

public:
	Pion(int pos_x=0, int pos_y=0) : x(pos_x), y(pos_y) {};
	virtual ~Pion() {};

	virtual string print() const{
		return "Pion";
	}
	int setPosition(int x, int y){

		return 0;
	}

	int getX() const {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY() const {
		return y;
	}

	void setY(int y) {
		this->y = y;
	}
};


#endif /* PION_H_ */
