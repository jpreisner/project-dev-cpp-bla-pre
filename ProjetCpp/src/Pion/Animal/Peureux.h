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
	vector<Animal> listAnimauxImpressionnant;
public:
	Peureux(int v = 0) : Animal(v) {};

	virtual ~Peureux(){};

	/**
	 * retirer l'animal a la liste des animaux impressionnants
	 */
	void ajouterAnimalImpressionnant(const Animal& a){
		listAnimauxImpressionnant.push_back(a);
	}

	/**
	 * retirer l'animal a la liste des animaux impressionnants
	 * TODO
	 */
	void retirerAnimalImpressionnant(const Animal& a){
	}

	virtual string print() const{
		return "Peureux";
	}
};

#endif /* PEUREUX_H_ */
