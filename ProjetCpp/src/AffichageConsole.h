/*
 * AffichageConsole.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef AFFICHAGECONSOLE_H_
#define AFFICHAGECONSOLE_H_

#include "Affichage.h"

class AffichageConsole: public Affichage {
public:
	AffichageConsole(){};
	virtual ~AffichageConsole(){};
	int menuDemarrage();
	int afficheRegle();
	void demandeNomJoueur(Joueur *j, int numJoueur);
	void affichePlateau(Plateau p);
	/* A COMPLETER */
};

#endif /* AFFICHAGECONSOLE_H_ */
