/*
 * Animal.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <sstream>
#include <string>

#include "../Joueur.h"
#include "../Pion.h"

class Affichage;
class Plateau;
class Joueur;

using namespace std;


class Animal: public Pion {
// attributs
private:
	int valeur;
	Joueur* joueur;

// méthodes
public:
	Animal(int v = 0, Joueur* joueur = NULL) : valeur(v), joueur(joueur) {
	}
	virtual ~Animal() {
	}

	// getters
	int getValeur() {
		return valeur;
	}


	Joueur* getJoueur() const{
		return joueur;
	}

	/**
	 * on le pose en (x,y)
	 */
	int poser(int x, int y);

	/**
	 * action appelé lorsque l'animal est posé et est en fonction des autres animaux environnants
	 */
	virtual void action(Plateau *p, Affichage *affichage) = 0;

	/**
	 * cacher ou montrer
	 */
	int retourner();

	virtual string print() const{
		//ostringstream id;
		//id << getJoueur()->getId();
		//return "(Animal," + id.str() + ")";
		return "Animal";
	}
};

#endif /* ANIMAL_H_ */
