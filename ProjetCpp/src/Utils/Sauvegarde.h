/*
 * Sauvegarde.h
 *
 *  Created on: 14 févr. 2015
 *      Author: Guillaume
 */

#ifndef UTILS_SAUVEGARDE_H_
#define UTILS_SAUVEGARDE_H_

#include <iostream>
#include <string>

#include "../Joueur.h"
#include "../Partie.h"
#include "../Plateau/Case.h"

using namespace std;

class Sauvegarde {
private:
	static void ecrireJoueur(Joueur *j,ofstream& fichier);
	static void ecrirePlateau(Plateau p,ofstream& fichier);
	static void ecrirePion(Pion *p, ofstream& fichier);
	static void lireJoueur(ifstream& fichier, Joueur* joueur);
	static void lirePlateau(ifstream& fichier, Plateau* plateau, vector<Joueur*> vectJoueur);

public:
	static bool sauvegarderPartie(Partie p, string fileName, int idJoueur);
	static int chargementPartie(string fileName,unsigned int& tourJoueur, Partie* partie);

};

#endif /* UTILS_SAUVEGARDE_H_ */
