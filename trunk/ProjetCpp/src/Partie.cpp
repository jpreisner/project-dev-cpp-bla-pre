/*
 * Partie.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Partie.h"

#include <iostream>

#include "Affichage/Affichage.h"
#include "Pion/ImpalaJones.h"
#include "Pion.h"
#include "Plateau/Plateau.h"
#include "Utils/Sauvegarde.h"

/**
 * Lancer le premier tour
 */
int Partie::lancerPartie(int x, int y){
	cout << "coord ij=(" << getPlateau()->getImpalaJones()->getX() << ", " << getPlateau()->getImpalaJones()->getY() << ")" << endl;
	ImpalaJones * ij = new ImpalaJones(x,y);
	return getPlateau()->initImpalaJones(ij);
}

int Partie::deroulementJeu(vector<Joueur*> vectJoueur, int tourJoueur, Affichage *affichage){
	int nbCases, jeu;

	// Affiche du plateau
	affichage->affichePlateau(*getPlateau());

	// Message indiquant c'est a qui de jouer
	affichage->afficheTour(getJoueurI(tourJoueur));

	// Affichage du menu du joueur
	do{
		jeu = affichage->menuJoueur(getJoueurI(tourJoueur));
		// Si jeu = 2 ==> le joueur joue
		if(jeu == 2){
			bool joue = false;
			do{
				joue = getJoueurI(tourJoueur)->jouer(getPlateau(),affichage);
			}while(!joue);
			break;
		}
		// Le joueur ne joue pas mais fait une autre action
		else{
			switch(jeu){
				// Le joueur souhaite afficher sa liste de pions
				case(1) : affichage->afficheListAnimal(getJoueurI(tourJoueur)->getListAnimaux());	break;

				// Le joueur souhaite sauvegarder la partie
				case(3) : Sauvegarde::sauvegarderPartie(*this,"save.txt");	break;	// a modifier le save.txt, et proposer au joueur d'entrer un nom de sauvegarde

				// Le joueur souhaite quitter la partie
				case(4) : return 0;
			}
		}
	}while(jeu!=2);

	// Affiche du plateau apres que le joueur ait joué
	affichage->affichePlateau(*getPlateau());

	// Le joueur doit déplacer Impala Jones avant de passer son tour
	nbCases = affichage->demandeDeplacerImpalaJones(*getPlateau(),*getPlateau()->getImpalaJones());
	getPlateau()->getImpalaJones()->deplacer(nbCases, getPlateau());
	return 1;
}

/**
 * Demander les noms, attribuer les cartes
 */
int Partie::initJoueurs(){

	return 0;
}

int Partie::sauvegarde(string path){
	return 0;
}

int Partie::chargement(string path){
	/*
	string file = path + ".txt";
	// Lecture
	ifstream fichier(file, ios::in);
	if(!fichier){
		cout << "Erreur lors de l'ouverture du fichier " << file << endl;
		return -1;
	}
	// Lecture ligne par ligne
    string ligne;
    while(getline(fichier, ligne)){
            cout << ligne << endl;
    }

	// Fin de la lecture
	fichier.close();
	*/
	return 0;
}
