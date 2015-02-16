/*
 * Joueur.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Guillaume
 */

#include "Joueur.h"

#include <iterator>
#include <typeinfo>

#include "Pion/Animal/Effrayant/Crocodile.h"
#include "Pion/Animal/Effrayant/Lion.h"
#include "Pion/Animal/Neutre/Elephant.h"
#include "Pion/Animal/Peureux/Gazelle.h"
#include "Pion/Animal/Peureux/Zebre.h"
#include "Plateau/Case.h"
#include "Plateau/Plateau.h"

void Joueur::initListPions(int nbGazelles, int nbZebres, int nbElephants, int nbLions,
		int nbCrocos){
	int i;

	// 6 gazelles
	for (i = 0; i < nbGazelles; i++) {
		listAnimaux.push_back((new Gazelle(this)));
	}
	// 5 zebres
	for (i = 0; i < nbZebres; i++) {
		listAnimaux.push_back((new Zebre(this)));
	}
	// 1 elephant
	for (i = 0; i < nbElephants; i++) {
		listAnimaux.push_back((new Elephant(this)));
	}
	// 1 lion
	for (i = 0; i < nbLions; i++) {
		listAnimaux.push_back((new Lion(this)));
	}
	// 2 crocodiles
	for (i = 0; i < nbCrocos; i++) {
		listAnimaux.push_back((new Crocodile(this)));
	}
}

bool Joueur::jouer(int x, int y, int typeAnimal, Plateau* p){
	if (p->getCase(x, y)->getPion() != NULL) {
		cerr << "Ajout impossible du pion en case :(" << x << "," << y << ")" << endl;
		return false;
	}
	else {
		Pion* pion;

		/* instanciation du pointeur selon le type demandé en parametre */
		switch (typeAnimal) {
			case 1:		pion = new Gazelle(this);		break;
			case 2:		pion = new Zebre(this);			break;
			case 3:		pion = new Elephant(this);		break;
			case 4:		pion = new Lion(this);			break;
			case 5:		pion = new Crocodile(this);		break;
			default:			break;
		}

		/* test avec les animaux en reserve du joueur*/
		for (unsigned int i = 0; i < listAnimaux.size(); i++) {
			/* equivalent du instanceOF, peut-ètre à revoir.*/
			if (typeid( *pion ) == typeid(*listAnimaux[i])) {
				/* ajotu de l'animal à la case*/
				p->getCase(x, y)->ajouterPion(listAnimaux[i]);
				/* suppression de l'animal dans la reserve du joueur*/
				listAnimaux.erase(listAnimaux.begin() + i - 1);
				return true;
			}
		}
		cerr << "L'animal n'est pas dans les pions disponibles du joueur" << endl;
		return false;
	}
}

int Joueur::placementAnimal(Animal a, int x, int y){
	return 0;
}

void Joueur::ajouterPoints(int nb){
	setNbPoints(getNbPoints() + nb);
}

