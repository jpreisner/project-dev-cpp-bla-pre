/*
 * Plateau.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <string>

#include "../Pion/Animal.h"
#include "../Pion/ImpalaJones.h"
#include "../Pion.h"
#include "Case.h"
#include "Secteurs.h"

#define TAILLE_PLATEAU_X 8
#define TAILLE_PLATEAU_Y 7

using namespace std;

class Pion;

class Plateau {
private:
	Case cases[TAILLE_PLATEAU_X][TAILLE_PLATEAU_Y];
	ImpalaJones *ij;
	bool bonusInauguration;
public:
	Plateau() : bonusInauguration(false){
		ij = new ImpalaJones(0,0);
		initPlateau1();
	}
	virtual ~Plateau(){
	}

	void initPlateau1();

	int deplacerPion();

	int ajouterAnimal(int x, int y, Animal* a);

	int initImpalaJones(ImpalaJones *ij);

	Case* getCase(int x, int y){
		return &cases[x][y];
	}

	int getTaillePlateauX(){
		return TAILLE_PLATEAU_X;
	}
	int getTaillePlateauY(){
		return TAILLE_PLATEAU_Y;
	}

	/* Affichage du plateau */
	string print();

	/* return true si le secteur i est rempli par un seul joueur */
	bool secteurRempli(int secteur);

	/* return true si le bonus Inauguration a ete donne */
	bool getbonusInauguration(){
		return bonusInauguration;
	}

	/* supprime le pion sur la case i/j*/
	bool supprimerPion(int x, int y);

	/* methode pour echanger les 2 pions de 2 cases*/
	void echangerAnimalCases(Animal* a1, Animal* a2);

	void setBonusInauguration(bool bonusInauguration){
		this->bonusInauguration = bonusInauguration;
	}

	ImpalaJones* getImpalaJones(){
		return ij;
	}
};

#endif /* PLATEAU_H_ */
