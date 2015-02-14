/*
 * Effrayant.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef EFFRAYANT_H_
#define EFFRAYANT_H_

#include <string>
#include <vector>

#include "../Animal.h"

using namespace std;

class Effrayant: public Animal {
private:
	vector<Animal> listAnimauxEffrayes;
public:
	Effrayant(int v = 0, Joueur* j = NULL) : Animal(v,j) {};
	virtual ~Effrayant(){};

	/**
	 * Ajouter l'animal a la liste des animaux effrayes
	 */
	void ajouterAnimalEffraye(const Animal& a){
		listAnimauxEffrayes.push_back(a);
	}

	/**
	 * retirer l'animal a la liste des animaux effrayes
	 * TODO
	 */
	void retirerAnimalEffraye(const Animal& a){
	}

	virtual string print() const{
		return "Effrayant";
	}
};

#endif /* EFFRAYANT_H_ */
