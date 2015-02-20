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
	int typePlateau;
	ImpalaJones *ij;
	bool bonusInauguration;
public:
	Plateau(int num_plateau=1,ImpalaJones *ij= NULL) : typePlateau(num_plateau), ij(ij), bonusInauguration(false){
		initPlateau(num_plateau);
	}
	virtual ~Plateau(){
	}

	Case* getCase(int x, int y){
		return &cases[x][y];
	}

	unsigned int getTaillePlateauX(){
		return TAILLE_PLATEAU_X;
	}
	unsigned int getTaillePlateauY(){
		return TAILLE_PLATEAU_Y;
	}

	int getTypePlateau() const{
		return typePlateau;
	}


	void setImpalaJones(ImpalaJones* ij){
		this->ij = ij;
	}

	/* Affichage du plateau */
	string print();

	/* return true si le bonus Inauguration a ete donne */
	bool getbonusInauguration(){
		return bonusInauguration;
	}

	void setBonusInauguration(bool bonusInauguration){
		this->bonusInauguration = bonusInauguration;
	}

	ImpalaJones* getImpalaJones(){
		return ij;
	}

	void initPlateau(int num_plateau);
	void initPlateauNormal();
	void initPlateauReservePresident();
	int ajouterAnimal(int x, int y, Animal* a);

	/* Ajout d'ImpalaJones sur la case correspondant a sa position */
	int initImpalaJones(ImpalaJones *ij);

	/* return true si le secteur i est rempli par un seul joueur */
	bool secteurRempli(int secteur);
	/* supprime le pion sur la case i/j*/
	bool supprimerPion(int x, int y);

	/* methode pour echanger les 2 pions de 2 cases*/
	void echangerAnimalCases(Animal* a1, Animal* a2);

};

#endif /* PLATEAU_H_ */
