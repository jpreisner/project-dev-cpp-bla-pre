/*Gazelle.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef GAZELLE_H_
#define GAZELLE_H_

#include <sstream>
#include <string>

#include "../Peureux.h"

class Lion;

class Gazelle: public Peureux {
public:
	Gazelle(Joueur* j) : Peureux(2,j) {};
	~Gazelle() {};

	string print() const {
		ostringstream id;
		id << getJoueur()->getId();
		/*
		if(isCache()){
			return "(-," + id.str() + ")";
		}
		*/
		return "(G," + id.str() + ")";
	}
	void action(Plateau *p, Affichage *affichage);
	void fuite(Plateau *p);
};

#endif /* GAZELLE_H_ */
