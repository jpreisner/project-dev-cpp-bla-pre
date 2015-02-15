/*
 * Affichage.h
 *
 *  Created on: 6 f�vr. 2015
 *      Author: Julien
 */

#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include <vector>

#include "Pion/Animal.h"
#include "Pion/ImpalaJones.h"


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
	virtual int demandeDeplacerImpalaJones(Plateau p, ImpalaJones ij) = 0;
	virtual void afficheListAnimal(vector<Animal*> listAnimaux) = 0;
	virtual int selectionnerAnimal(vector<Animal*> listAnimaux) = 0;
	virtual int selectionnerPosition(int *x, int *y, Plateau p) = 0;
	virtual void affichePion(Pion *p, Joueur *j) = 0;
	virtual int menuJoueur(Joueur *j) = 0;
	virtual int demandeLigne(Plateau p, int colonne) = 0;
	virtual int demandeColonne(Plateau p, int ligne) = 0;
	virtual void afficheImpalaJones() = 0;
	/* FIXME : mettre des "const" a chaque param ? sauf pour selectionnerPosition */
	/* A COMPLETER */
};

#endif /* AFFICHAGE_H_ */