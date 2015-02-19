/*
 * Regle.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef REGLE_H_
#define REGLE_H_

#include "Pion/ImpalaJones.h"

class Joueur;

class Plateau;

class Regle {
public:
	Regle(){};
	virtual ~Regle(){};

	static bool colonneRempli(Plateau p, int colonne);
	static bool ligneRempli(Plateau p, int ligne);
	static bool caseRempli(Plateau p, int colonne, int ligne);
	static bool finPartie(Plateau p);

	/* Par rapport au déplacement de Impala Jones */
	static int possibiliteDeplacementImpalaJones(Plateau p, ImpalaJones ij);
	static bool testDeplacementImpalaJones(Plateau p, int x, int y, int nbCases);

	/* Comptage des points */
	static int calculPointsJoueur(Plateau p, Joueur *j);
	static int joueurMajoriteDansSecteur(Plateau p,int secteur);
	static int valeurSecteur(Plateau p,int secteur);

};

#endif /* REGLE_H_ */
