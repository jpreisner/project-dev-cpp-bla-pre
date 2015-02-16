/*
 * Partie.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#include <string>

#include "Joueur.h"
#include "Plateau/Plateau.h"

class Partie {
private:
	Joueur *joueur1;
	Joueur *joueur2;
	Plateau *plateau;
public:
	Partie(Joueur *joueur1, Joueur *joueur2, Plateau *plateau) :
			joueur1(joueur1), joueur2(joueur2), plateau(plateau){};

	virtual ~Partie(){};

	Joueur* getJoueur1(){
		return joueur1;
	}

	Joueur* getJoueur2(){
		return joueur2;
	}

	Plateau* getPlateau(){
		return plateau;
	}

	/**
	 * Lancer le premier tour
	 */
	int lancerPartie();

	/**
	 * Demander les noms, attribuer les cartes
	 */
	int initJoueurs();

	/*friend ostream& operator<<(ostream &strm, const Partie &a) {
	 strm << "Partie" << endl;
	 strm << "\t Pions Joueur 1 : " << endl;
	 for (int i = 0; i < a.getJoueur1().getNbPoints(); i++) {
	 strm << "\t Pion " << i << " : " << a.getJoueur1().getAnimal(i)->print() << endl;
	 }

	 strm << "\t Pions Joueur 2 : " << endl;
	 for (int i = 0; i < a.getJoueur2().getNbPoints(); i++) {
	 strm << "\t Pion " << i << " : " << a.getJoueur2().getAnimal(i)->print() << endl;
	 }

	 //TODO AFFICHER PLATEAU
	 strm << a.plateau.print() << endl;
	 return strm;
	 }*/

	int sauvegarde(string path);
	int chargement(string path);

};

#endif /* PARTIE_H_ */
