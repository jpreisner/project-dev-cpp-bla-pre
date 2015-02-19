/*
 * Animal.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
#include <sstream>

#include "../Pion.h"
#include "../Joueur.h"

class Affichage;
class Joueur;
class Plateau;

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
	 * action appelé lorsque l'animal est posé et est en fonction des autres animaux environnants
	 * Renvoie 1 si il n'y a plus d'action a effectué après l'appel de cette fonction, et 0 sinon
	 */
	virtual void action(Plateau *p, Affichage *affichage) = 0;


	virtual string print() const{
		return "Animal";
	}
};

#endif /* ANIMAL_H_ */
