/*
 * Ordinateur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_

#include <string>

#include "../Joueur.h"

class Ordinateur: public Joueur {
public:
	Ordinateur(int id=2) :
			Joueur(0, "I-A", id) {
	}
	virtual ~Ordinateur() {
	}

	friend ostream& operator<<(ostream &strm, const Ordinateur &a) {
		strm << "Ordinateur : " << a.getNom() << endl;
		return strm;
	}
};



#endif /* ORDINATEUR_H_ */