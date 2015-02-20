/*
 * JoueurReel.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef JOUEURREEL_H_
#define JOUEURREEL_H_

#include <iostream>
#include <string>
#include "../Affichage/Affichage.h"
#include "../Joueur.h"

class JoueurReel: public Joueur {
public:
	JoueurReel(int nbPoints = 0, string nom = "", int nbGazelles = 6, int nbZebres = 5,
			int nbElephants = 1, int nbLions = 1, int nbCrocos = 2) :
			Joueur(nbPoints, nom, nbGazelles, nbZebres, nbElephants, nbLions, nbCrocos){};
	virtual ~JoueurReel(){};

	friend ostream& operator<<(ostream &strm, const JoueurReel &a) {
		strm << "Joueur Reel : " << a.getNom() << endl;
		return strm;
	}

	bool jouer(Plateau* plateau, Affichage * affiche);
	bool jouerCase(int xPion, int yPion, Plateau* plateau, Affichage * affiche);
	int deplacementImpalaJones(Plateau p, ImpalaJones ij, Affichage *affichage);
	void joueurInitImpala(Plateau *p, Affichage *affichage);
	int jouerTour(Plateau* p, Affichage* affichage, Partie partie);
	int choixActionCrocodile(vector<Gazelle*> voisin, Plateau p, Affichage *affichage);

};

#endif /* JOUEURREEL_H_ */
