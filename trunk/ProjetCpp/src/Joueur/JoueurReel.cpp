/*
 * JoueurReel.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "JoueurReel.h"

#include <iterator>
#include <vector>

#include "../Partie.h"
#include "../Pion/Animal/Effrayant/Crocodile.h"
#include "../Pion/Animal/Effrayant/Lion.h"
#include "../Pion/Animal/Neutre/Elephant.h"
#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/Animal/Peureux/Zebre.h"
#include "../Pion/ImpalaJones.h"
#include "../Pion.h"
#include "../Plateau/Case.h"
#include "../Plateau/Plateau.h"
#include "../Regle.h"
#include "../Utils/Sauvegarde.h"

/**
 * Affiche le menu du joueur, puis execute l'action que le joueur souhaite faire :
 *  jouer, afficher ses pions en main, sauvegarde ou quitter
 *  Renvoie 0 si le joueur souhaite quitter, 1 sinon
 */
int JoueurReel::jouerTour(Plateau* p, Affichage* affichage, Partie partie){
	int jeu;
	// Affichage du menu du joueur
	do{
		jeu = affichage->menuJoueur(this);
		// Si jeu = 2 ==> le joueur joue
		if(jeu == 2){
			bool joue = false;
			do{
				joue = jouer(p, affichage);
			}while(!joue);
			break;
		}
		// Le joueur ne joue pas mais fait une autre action
		else{
			string filename;

			switch(jeu){
				// Le joueur souhaite afficher sa liste de pions
				case 1 : affichage->afficheListAnimal(getListAnimaux());	break;

				// Le joueur souhaite sauvegarder la partie
				case 3 :
						cout<<"Veuillez saisir le nom du fichier de sauvegarde :"<<endl;
						cin>>filename;
						Sauvegarde::sauvegarderPartie(partie,filename, getId());
						affichage->afficheSauvegarde();
				break;	// a modifier le save.txt, et proposer au joueur d'entrer un nom de sauvegarde

				// Le joueur souhaite quitter la partie
				case 4 : return 0;
			}
		}
	}while(jeu!=2);
	return 1;
}

/**
 * Le joueur sélectionne les coordonnées ou il souhaite poser un animal puis appelle la méthode jouerCase
 */
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

/**
 * Selon les coordonnées passées en paramètre, ici le joueur selectionne un animal à poser, puis la méthode le pose sur le plateau
 *  ensuite la méthode action de l'animal est appelé et enfin, le bonus inauguration est traité
 */
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
				affiche->messageBonusInauguration(getNom());
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

/**
 * Détermine les possibles déplacements d'Impala Jones, et demande au joueur ou souhaite-t-il poser Impala Jones en conséquence
 */
int JoueurReel::deplacementImpalaJones(Plateau p, ImpalaJones ij, Affichage *affichage){
	// Le joueur doit déplacer Impala Jones avant de passer son tour
	int possibilite = Regle::possibiliteDeplacementImpalaJones(p,ij);
	return affichage->demandeDeplacerImpalaJones(p, ij, possibilite);
}

/**
 * Demande au joueur de positionner Impala Jones pour la 1ere fois sur le plateau
 */
void JoueurReel::joueurInitImpala(Plateau *p, Affichage *affichage){
	do{
		affichage->demandePositionInitialeImpalaJones(p->getImpalaJones());
	}
	while(p->initImpalaJones(p->getImpalaJones()));
}

/**
 * Demande au joueur ce qu'il souhaite échanger le crocodile qu'il vient de poser avec une gazelle voisine, séparé d'une riviere
 */
int JoueurReel::choixActionCrocodile(vector<Gazelle*> voisin, Plateau p, Affichage *affichage){
	return affichage->demandeChoixActionCrocodile(voisin, p);
}
