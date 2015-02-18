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
	Ordinateur(int nbPoints = 0, string nom="I-A", int nbGazelles = 6, int nbZebres = 5,
			int nbElephants = 1, int nbLions = 1, int nbCrocos = 2) :
			Joueur(nbPoints, nom , nbGazelles, nbZebres, nbElephants, nbLions, nbCrocos){};
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
	int jouerTour(Plateau* p, Affichage* affichage, Partie partie);
};



#endif /* ORDINATEUR_H_ */
