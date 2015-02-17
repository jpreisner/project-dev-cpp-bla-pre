/*
 * Partie.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#include <string>
#include <vector>

#include "Joueur.h"

class Partie {
private:
	vector<Joueur*> vectJoueur;
	Plateau *plateau;
public:
	Partie(vector<Joueur*> vectJoueur, Plateau *plateau) :
		vectJoueur(vectJoueur), plateau(plateau){};

	virtual ~Partie(){};

	Joueur* getJoueurI(int i){
		return vectJoueur[i];
	}

	Plateau* getPlateau(){
		return plateau;
	}

	/**
	 * Lancer le premier tour en initialisant la position d'ImpalaJones
	 */
	int lancerPartie(int x, int y);

	int deroulementJeu(vector<Joueur*> vectJoueur, int tourJoueur, Affichage *affichage);

	/**
	 * Demander les noms, attribuer les cartes
	 */
	int initJoueurs();

	int sauvegarde(string path);
	int chargement(string path);

};

#endif /* PARTIE_H_ */
