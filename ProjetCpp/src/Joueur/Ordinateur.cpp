/*
 * Ordinateur.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Ordinateur.h"

#include <cstdlib>
#include <iterator>

#include "../Affichage/Affichage.h"
#include "../Partie.h"
#include "../Pion.h"
#include "../Plateau/Case.h"
#include "../Regle.h"


/**
 * Compteur permettant de savoir les choix de l'ordinateur lorsqu'il a la possibilité d'échanger un crocodile avec une gazelle
 * Pour ne pas obtenir une boucle longue, voir infini, on fixe un compteur à 3
 * -> lorsqu'au bout de 3 fois, si l'ordinateur a tiré aléatoirement le fait de faire un échange avec une gazelle, celui-ci sera forcé
 * a s'arreter
 */
static int cptActionCroco = 3;


/**
 * Pas besoin d'effectuer ce qu'il y a a faire dans jouerTour de JoueurReel, car l'ordinateur souhaite automatiquement jouer
 * Renvoie 1 car l'ordinateur ne veut pas quitter la partie
 */
int Ordinateur::jouerTour(Plateau* p, Affichage* affichage, Partie partie){
	jouer(p, affichage);
	return 1;
}

/**
 * L'ordinateur tire aléatoirement les coordonnéespour poser un animal puis appelle la méthode jouerCase
 */
bool Ordinateur::jouer(Plateau* plateau, Affichage * affiche){
	// Tirage aléatoire de la case à jouer
	int xImpala = plateau->getImpalaJones()->getX();
	int yImpala = plateau->getImpalaJones()->getY();
	int xPion;
	int yPion;
	if (xImpala == 0 || xImpala == TAILLE_PLATEAU_X-1) {
		// Impala sur une ligne verticale
		yPion = yImpala;
		//  on demande la position du Y
		xPion = randomColonne(*plateau, yPion);
		if(xPion == -1){
			cerr << "Erreur dans jouer (Ordinateur) : la ligne " << yPion << " est remplie" << endl;
			return false;
		}
	} else {
		// Impala sur une ligne horizontale
		xPion = xImpala;
		//  on demande la position du X
		yPion = randomLigne(*plateau, xPion);
		if(yPion == -1){
			cerr << "Erreur dans jouer (Ordinateur) : la colonne " << xPion << " est remplie" << endl;
			return false;
		}
	}
	return jouerCase(xPion, yPion, plateau, affiche);
}

/**
 * Selon les coordonnées passées en paramètre, ici l'ordinateur selectionne au hasard un animal à poser,
 * puis la méthode le pose sur le plateau ensuite la méthode action de l'animal est appelé
 * et enfin, le bonus inauguration est traité
 */
bool Ordinateur::jouerCase(int xPion, int yPion, Plateau* plateau, Affichage * affiche){
	// Ajout impossible du pion en case (xPion, yPion)
	if (plateau->getCase(xPion, yPion)->getPion() != NULL) {
		return false;
	}
	else {
		int nbPion = getListAnimaux().size();
		int pos = rand()%nbPion;

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

			// Affichage au joueur réel du coup jouer par l'ordinateur
			affiche->afficheCoupJoueOrdi(a);

			return true;
		}
		else {
			cerr << "Erreur dans le random d'animal"<< endl;
			return false;
		}
	}
	return false;
}

/**
 * Tire au hasard une ligne de la colonne passé en paramètre
 * Le résultat offrira la coordonnée (colonne, ligne), qui sera une case disponible
 */
int Ordinateur::randomLigne(Plateau p, int colonne){
	unsigned int i;
	vector<int> tab(0);
	for(i=1; i<p.getTaillePlateauY()-1; i++){
		// Si la ligne i n'est pas rempli, alors l'IA pourra la jouer
		if(!Regle::caseRempli(p, colonne, i)){
			cout << i << " ";
			tab.push_back(i);
		}
	}
	cout << endl;

	int size = tab.size();
	if(size == 0){
		cout << "Aucune possibilité dans randomLigne" << endl;
		return -1;
	}
	// Tirage d'un indice aléatoire
	int random = rand()%size;

	// On renvoi le résultat
	return tab[random];
}

/**
 * Tire au hasard une colonne de la ligne passé en paramètre
 * Le résultat offrira la coordonnée (colonne, ligne), qui sera une case disponible
 */
int Ordinateur::randomColonne(Plateau p, int ligne){
	unsigned int i;
	vector<int> tab(0);
	for(i=1; i<p.getTaillePlateauX()-1; i++){
		// Si la ligne i n'est pas rempli, alors l'IA pourra la jouer
		if(!Regle::caseRempli(p, i, ligne)){
			cout << i << " ";
			tab.push_back(i);
		}
	}
	cout << endl;

	int size = tab.size();
	if(size == 0){
		cout << "Aucune possibilité dans randomLigne" << endl;
		return -1;
	}
	// Tirage d'un indice aléatoire
	int random = rand()%size;

	// On renvoi le résultat
	return tab[random];
}

/**
 * Détermine les possibles déplacements d'Impala Jones, et l'ordinateur tire au hasard poser Impala Jones en conséquence
 */
int Ordinateur::deplacementImpalaJones(Plateau p, ImpalaJones ij, Affichage *affichage){
	int random = 0;

	// Le joueur doit déplacer Impala Jones avant de passer son tour
	int possibilite = Regle::possibiliteDeplacementImpalaJones(p,ij);
	if (possibilite == 0) {
		return -1;
	}
	/* Impala Jones peut etre placé sur l'une des 3 cases suivantes */
	else if (possibilite == -1) {
		random = rand()%3 + 1;
		return random;
	}
	/* Impala Jones peut etre placé soit sur la prochaine case, soit sur la suivante */
	else if (possibilite == -2) {
		random = rand()%2 + 1;
		return random;
	}
	/* Impala Jones peut etre placé soit sur la prochaine case, soit celle plus loin de 2 cases (+3)*/
	else if (possibilite == -3) {
		random = rand()%2 + 1;
		if(random == 2){
			random = 3;
		}
		return random;
	}
	/* Impala Jones peut etre placé soit sur la 2ème case suivante, soit sur la 3ème case suivante */
	else if (possibilite == -4) {
		random = rand()%2 + 2;
		return random;
	}
	/* Impala Jones ne peut pas etre placé que a la case +1  */
	else if (possibilite == -5) {
		return 1;
	}
	/* Impala Jones ne peut pas etre placé que la la case +2  */
	else if (possibilite == -6) {
		return 2;
	}
	/* Impala Jones ne peut pas etre placé que la la case +3  */
	else if (possibilite == -7) {
		return 3;
	}
	/* Impala Jones ne peut pas etre placé sur l'une des 3 cases suivantes -> recherche de la première prochaine case libre */
	else if (possibilite > 0) {
		return possibilite;
	}
	else {
		cerr << "Erreur dans l'appel de la méthode possibiliteDeplacementImpalaJones" << endl;
		return -1;
	}
}

/**
 * L'ordinateur positionne aléatoirement Impala Jones pour la 1ere fois sur le plateau
 */
void Ordinateur::joueurInitImpala(Plateau *p, Affichage *affichage){
	int random_x, random_y;
	int size;

	// Random pour savoir si impala est sur une ligne ou colonne
	int random1 = rand()%2;
	int random2;
	// ligne -> x = 0 ou getTailleX()-1
	if(random1 == 0){
		random2 = rand()%2;
		if(random2 == 0){
			random_x = 0;
		}
		else{
			random_x = p->getTaillePlateauX()-1;
		}
		// Maintenant tirage aléatoire de y
		size = p->getTaillePlateauY()-2;
		random_y = rand()%size+1;
	}
	// colonne
	else{
		random2 = rand()%2;
		if(random2 == 0){
			random_y = 0;
		}
		else{
			random_y = p->getTaillePlateauY()-1;
		}
		// Maintenant tirage aléatoire de x
		size = p->getTaillePlateauX()-2;
		random_x = rand()%size+1;
	}

	p->getImpalaJones()->setX(random_x);
	p->getImpalaJones()->setY(random_y);
	p->initImpalaJones(p->getImpalaJones());
	affichage->messageInitImpalaOrdi(random_x, random_y);
}

/**
 * L'ordinateur interprete l'échange entre un crocodile et une gazelle, ou non
 */
int Ordinateur::choixActionCrocodile(vector<Gazelle*> voisin, Plateau p, Affichage *affichage){
	int size = voisin.size() + 1;

	// voisin est vide, donc on retourne 1 pour qu'aucun changement soit effectué
	if(size == 1){
		cptActionCroco = 3;
		cout << "fin" << endl;
		return 1;
	}

	// Dans le cas ou le cpt est à 0 : on force l'ordinateur a choisir "ne rien faire"
	if(cptActionCroco == 0){
		cout << "fin" << endl;
		return size;
	}

	// Tirage au sort de l'action a faire
	int random = rand()%size + 1;

	// Cas ou l'ordinateur a tiré aléatoirement l'option "ne rien faire"
	if(random == size){
		// On remet le compteur à 3
		cptActionCroco = 3;
		cout << "fin" << endl;
	}
	else{
		cptActionCroco--;
		cout << "random" << endl;
	}

	return random;
}
