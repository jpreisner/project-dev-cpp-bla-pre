/*
 * JoueurReel.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "JoueurReel.h"

#include <iterator>
#include <typeinfo>
#include <vector>

#include "../Pion/Animal/Effrayant/Crocodile.h"
#include "../Pion/Animal/Effrayant/Lion.h"
#include "../Pion/Animal/Neutre/Elephant.h"
#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/Animal/Peureux/Zebre.h"
#include "../Plateau/Case.h"
#include "../Plateau/Plateau.h"

bool JoueurReel::jouer(int x, int y, int typeAnimal, Plateau* p) {
	if (p->getCase(x, y)->getPion() != NULL) {
		cerr << "Ajout impossible du pion en case :(" << x << "," << y << ")"
				<< endl;
		return false;
	} else {
		Pion* pion;

		// instanciation du pointeur selon le type demandé en parametre
		switch (typeAnimal) {
		case 1:
			pion = new Gazelle(this);
			break;
		case 2:
			pion = new Zebre(this);
			break;
		case 3:
			pion = new Elephant(this);
			break;
		case 4:
			pion = new Lion(this);
			break;
		case 5:
			pion = new Crocodile(this);
			break;
		default:
			break;
		}

		// test avec les animaux en reserve du joueur
		for (unsigned int i = 0; i < getListAnimaux().size(); i++) {
			// equivalent du instanceOF, peut-ètre à revoir
			if (typeid( *pion ) == typeid(*getListAnimaux()[i])) {
				// ajout de l'animal à la case
				p->getCase(x, y)->ajouterPion(getListAnimaux()[i]);
				// suppression de l'animal dans la reserve du joueur
				getListAnimaux().erase(getListAnimaux().begin() + i - 1);
				return true;
			}
		}
		cerr << "L'animal n'est pas dans les pions disponibles du joueur"
				<< endl;
		return false;
	}
	return false;
}
