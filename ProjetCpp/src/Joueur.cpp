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

void Joueur::initListPions(int nbGazelles, int nbZebres, int nbElephants, int nbLions, int nbCrocos){
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

int Joueur::jouer(){
	return 0;
}

int Joueur::placementAnimal(Animal a, int x, int y){
	return 0;
}

void Joueur::ajouterPoints(int nb){
	setNbPoints(getNbPoints() + nb);
}

