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


bool JoueurReel::jouer(Plateau* plateau, Affichage * affiche) {
	int xImpala = plateau->getImpalaJones()->getX();
	int yImpala = plateau->getImpalaJones()->getY();
	int xPion = 0;
	int yPion = 0;
	if (xImpala == 0 || xImpala == TAILLE_PLATEAU_X-1) {
		// Impala sur une ligne verticale
		yPion = yImpala;
		//  on demande la position du Y
		xPion = affiche->demandeColonne(*plateau, yPion);
	} else {
		// Impala sur une ligne horizontale
		xPion = xImpala;
		//  on demande la position du X
		yPion = affiche->demandeLigne(*plateau, xPion);
	}
	return jouerCase(xPion, yPion, plateau, affiche);
}

bool JoueurReel::jouerCase(int xPion, int yPion, Plateau* plateau, Affichage * affiche) {
	if (plateau->getCase(xPion, yPion)->getPion() != NULL) {
		cerr << "Ajout impossible du pion en case :(" << xPion << "," << yPion << ")" << endl;
		return false;
	}
	else {
		int typeAnimal = affiche->selectionnerAnimal(getListAnimaux());
		int nbPion = getListAnimaux().size();
		int pos = 0;
		// instanciation du pointeur selon le type demandé en parametre
		switch (typeAnimal) {
		// Gazelle
		case 1:
			while (pos < nbPion) {
				if (dynamic_cast<Gazelle*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
			// Zebre
		case 2:
			while (pos < nbPion) {
				if (dynamic_cast<Zebre*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
			// Elephant
		case 3:
			while (pos < nbPion) {
				if (dynamic_cast<Elephant*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
			// Lion
		case 4:
			while (pos < nbPion) {
				if (dynamic_cast<Lion*>(getListAnimaux()[pos]) == NULL) {
					pos++;
				} else {
					break;
				}
			}
			break;
			// Crocodile
		case 5:
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
			return false;
		}

		if (pos < nbPion) {
			// ajout de l'animal à la case
			plateau->ajouterAnimal(xPion, yPion, getListAnimaux()[pos]);
			// suppression de l'animal dans la reserve du joueur
			getListAnimaux().erase(getListAnimaux().begin() + pos);

			Animal *a = dynamic_cast<Animal*>(plateau->getCase(xPion, yPion)->getPion());
			if (a == NULL) {
				cerr << "Erreur dans jouer (JoueurReel.cpp) : le pion posé n'est pas un animal !" << endl;
				// Supprimer le pion?
				return false;
			}

			// Appel de la fonction action du pion
			a->action(plateau, affiche);
			affiche->affichePlateau(*plateau);

			/* BONUS INNAUGURATION */
			if (!plateau->getbonusInauguration() && plateau->secteurRempli(plateau->getCase(xPion, yPion)->getSecteur())) {
				ajouterPoints(5);
				plateau->setBonusInauguration(true);
			}
			return true;
		}
		else {
			cerr << "L'animal n'est pas dans les pions disponibles du joueur"<< endl;
			return false;
		}
	}
	return false;
}
