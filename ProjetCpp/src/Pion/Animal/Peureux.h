/*
 * Peureux.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PEUREUX_H_
#define PEUREUX_H_

#include <string>
#include <vector>

#include "../Animal.h"

using namespace std;

class Peureux: public Animal {
private:
	bool cache;

public:
	Peureux(int v = 0, Joueur* j = NULL) : Animal(v,j), cache(false){};

	virtual ~Peureux(){};

	virtual string print() const{
		return "Peureux";
	}

	bool isCache() const {
		return cache;
	}

	void setCache(bool cache) {
		this->cache = cache;
	}

	void seCache();
};

#endif /* PEUREUX_H_ */
