/*
 * Affichage.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include <vector>

#include "Pion/Animal.h"


class Joueur;
class Plateau;

using namespace std;

class Affichage {
public:
	Affichage(){};
	virtual ~Affichage(){};
	static int demandeTypeAffichage();
	virtual int menuDemarrage() = 0;
	virtual int afficheRegle() = 0;
	virtual void demandeNomJoueur(Joueur *j, int numJoueur) = 0;
	virtual void affichePlateau(Plateau p) = 0;
	virtual int demandeDeplacerImpalaJones() = 0;
	virtual void afficheListAnimal(vector<Animal*> listAnimaux) = 0;
	virtual int selectionnerAnimal(vector<Animal*> listAnimaux) = 0;
	virtual void selectionnerPosition(int *x, int *y) = 0;
	/* A COMPLETER */
};

#endif /* AFFICHAGE_H_ */
