/*
 * Joueur.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Guillaume
 */

#include "Joueur.h"

#include "Pion/Animal/Effrayant/Crocodile.h"
#include "Pion/Animal/Effrayant/Lion.h"
#include "Pion/Animal/Neutre/Elephant.h"
#include "Pion/Animal/Peureux/Gazelle.h"
#include "Pion/Animal/Peureux/Zebre.h"

class Pion;


/**
 * Permet d'initialiser tous les pions d'un joueur
 * 6 gazelles
 * 5 zebres
 * 1 elephant
 * 1 lion
 * 2 crocos
 */
void Joueur::initListPions(int nbGazelles, int nbZebres, int nbElephants, int nbLions, int nbCrocos) {

	/**
	 * Utiliser les pointeurs ???
	 */

	int i;

	// 6 gazelles
	for (i = 0; i < nbGazelles; i++) {
		listAnimaux.push_back(*(new Gazelle()));
	}
	// 5 zebres
	for (i = 0; i < nbZebres; i++) {
		listAnimaux.push_back(*(new Zebre()));
	}
	// 1 elephant
	for (i = 0; i < nbElephants; i++) {
		listAnimaux.push_back(*(new Elephant()));
	}
	// 1 lion
	for (i = 0; i < nbLions; i++) {
		listAnimaux.push_back(*(new Lion()));
	}
	// 2 crocodiles
	for (i = 0; i < nbCrocos; i++) {
		listAnimaux.push_back(*(new Crocodile()));
	}
}

int jouer() {

	return 0;
}

int placementAnimal(Animal a, int x, int y){

	return 0;
}

