/*
 * JoueurReel.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "JoueurReel.h"

#include <iterator>
#include <vector>

#include "../Pion/Animal/Effrayant/Crocodile.h"
#include "../Pion/Animal/Effrayant/Lion.h"
#include "../Pion/Animal/Neutre/Elephant.h"
#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/Animal/Peureux/Zebre.h"
#include "../Plateau/Case.h"
#include "../Plateau/Plateau.h"

bool JoueurReel::jouer(int x, int y, Plateau* p, Affichage * affiche){
	if (p->getCase(x, y)->getPion() != NULL) {
		cerr << "Ajout impossible du pion en case :(" << x << "," << y << ")" << endl;
		return false;
	} else {
		Animal* animal;
		int typeAnimal = affiche->selectionnerAnimal(getListAnimaux());
		int nbPion = getListAnimaux().size();
		int pos = 0;

		// instanciation du pointeur selon le type demandé en parametre
		switch(typeAnimal) {
		case 1 :
			while (pos < nbPion) {
				if (dynamic_cast<Gazelle*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
		case 2 :
			while (pos < nbPion) {
				if (dynamic_cast<Zebre*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
		case 3 :
			while (pos < nbPion) {
				if (dynamic_cast<Elephant*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
		case 4 :
			while (pos < nbPion) {
				if (dynamic_cast<Lion*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
		case 5 :
			while (pos < nbPion) {
				if (dynamic_cast<Crocodile*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
		default:
			cerr << "L'animal n'existe pas" << endl;
			return false;		}

		if (pos < nbPion) {
			// ajout de l'animal à la case
			p->getCase(x, y)->ajouterPion(getListAnimaux()[pos]);
			// suppression de l'animal dans la reserve du joueur
			getListAnimaux().erase(getListAnimaux().begin() + pos - 1);

			/* BONUS INNAUGURATION */
			if (p->secteurRempli(p->getCase(x, y)->getSecteur())){
				ajouterPoints(5);
			}

			return true;
		} else {
			cerr << "L'animal n'est pas dans les pions disponibles du joueur" << endl;
			return false;
		}
	}
	return false;
}
