/*
 * Ordinateur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_

#include <iostream>
#include <string>

#include "../Joueur.h"

class Ordinateur: public Joueur {
public:
	Ordinateur() : Joueur(0, "I-A") {
	}
	virtual ~Ordinateur() {};

	bool jouer(Plateau* plateau, Affichage * affiche);
	bool jouerCase(int xPion, int yPion, Plateau* plateau, Affichage * affiche);

	friend ostream& operator<<(ostream &strm, const Ordinateur &a) {
		strm << "Ordinateur : " << a.getNom() << endl;
		return strm;
	}
};



#endif /* ORDINATEUR_H_ */
