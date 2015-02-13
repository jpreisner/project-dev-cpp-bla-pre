/*
 * AffichageConsole.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef AFFICHAGECONSOLE_H_
#define AFFICHAGECONSOLE_H_

#include <vector>

#include "Affichage.h"
#include "Pion/Animal.h"

class Animal;

class AffichageConsole: public Affichage {
public:
	AffichageConsole(){};
	virtual ~AffichageConsole(){};
	int menuDemarrage();
	int afficheRegle();
	void demandeNomJoueur(Joueur *j, int numJoueur);
	void affichePlateau(Plateau p);
	int demandeDeplacerImpalaJones();
	void afficheListAnimal(vector<Animal*> listAnimaux);
	int selectionnerAnimal(vector<Animal*> listAnimaux);
	int selectionnerPosition(int *x, int *y, Plateau p);
	void affichePion(Pion *p, Joueur *j);
	int menuJoueur(Joueur *j);
	string demandePath();
	/* A COMPLETER */
};

#endif /* AFFICHAGECONSOLE_H_ */
