/*
 * Zebre.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ZEBRE_H_
#define ZEBRE_H_

#include <sstream>
#include <string>

#include "../../../Joueur.h"
#include "../../Animal.h"
#include "../Peureux.h"

class Zebre: public Peureux {
public:
	Zebre(Joueur* j) : Peureux(6,j) {};
	Zebre() : Peureux(6) {};
	~Zebre(){};

	string print() const {
		ostringstream id;
		id << getJoueur()->getId();
		/*
		if(isCache()){
			return "(-," + id.str() + ")";
		}
		*/
		return "(Z," + id.str() + ")";
	}

	void action(Plateau *p, Affichage *affichage);
};

#endif /* ZEBRE_H_ */
