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
	// si (-1, -1) ==> le pion n'est pas dans le jeu
	Pion(int pos_x=-1, int pos_y=-1) : x(pos_x), y(pos_y) {};
	virtual ~Pion() {};

	virtual string print() const{
		return "Pion ";
	}

	void setPosition(int x, int y){
		this->x=x;
		this->y=y;
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
