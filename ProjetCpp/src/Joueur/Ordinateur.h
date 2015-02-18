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
#include <vector>

#include "../Joueur.h"
#include "../Plateau/Plateau.h"

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
	int randomColonne(Plateau p, int ligne);
	int randomLigne(Plateau p, int colonne);
	int deplacementImpalaJones(Plateau p, ImpalaJones ij, Affichage *affichage);
	void joueurInitImpala(Plateau *p, Affichage *affichage);
};



#endif /* ORDINATEUR_H_ */
