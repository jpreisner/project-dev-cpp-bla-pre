//============================================================================
// Name        : ProjetCpp.cpp
// Author      : G
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Affichage/AffichageConsole.h"
#include "Joueur/JoueurReel.h"
#include "Joueur/Ordinateur.h"
#include "Joueur.h"
#include "Partie.h"
#include "Pion/ImpalaJones.h"
#include "Plateau/Plateau.h"
#include "Regle.h"
#include "Utils/SaisieSecure.h"
using namespace std;

int main(){
	unsigned int res;
	do{
		cout << "1- Test de programme" << endl;
		cout << "2- Appel du vrai programme" << endl;
		SaisieSecure::saisieSecureInt(res);
	}while(res != 1 && res != 2);

	// Test, permet de debugger nos fonctions qu'on ajoute au fur et a mesure
	if(res == 1){
		JoueurReel j("Zizou");
		cout << j << endl;

		// Affichage de la liste initialisée
		AffichageConsole affichage;
		affichage.afficheListAnimal(j.getListAnimaux());

		// Ajout d'Impala Jones dans le plateau
		ImpalaJones ij(1, 0);
		Plateau p;
		p.initImpalaJones(&ij);

		j.jouerCase(2, 1, &p, &affichage);
		j.jouerCase(3, 2, &p, &affichage);
		j.jouerCase(3, 1, &p, &affichage);
	}
	// Vrai programme qui sera ici quand tout sera fini
	else{
		srand (time(NULL));
		cout << "======================================" << endl;
		cout << "            Drôle de Zèbres           " << endl;
		cout << "======================================" << endl;

		// Demande le type d'affichage aux joueurs
		int typeAffichage = Affichage::demandeTypeAffichage();
		Affichage * affichage = NULL;
		if (typeAffichage == 1) {
			affichage = new AffichageConsole();
		}
		else {
			cout << "Cette affichage n'a pas été implémentée" << endl;
			return 0;
		}

		// Appel du menu de démarrage
		int menu_demarrage = affichage->menuDemarrage();

		// Jouer
		if (menu_demarrage == 1 || menu_demarrage == 2) {
			// Initialisation du joueur 1
			Joueur *joueur1 = new JoueurReel();
			affichage->demandeNomJoueur(joueur1);

			// Initialisation du joueur 2
			Joueur *joueur2 = NULL;
			// Cas ou le joueur 2 est un joueur "reel"
			if (menu_demarrage == 2) {
				joueur2 = new JoueurReel();
				affichage->demandeNomJoueur(joueur2);
			}
			// Cas ou le joueur 2 est l'ordinateur
			else {
				joueur2 = new Ordinateur();
			}

			// Les joueurs sont dans une liste pour les manipuler plus facilement par la suite
			vector<Joueur*> vectJoueur;
			vectJoueur.push_back(joueur1);
			vectJoueur.push_back(joueur2);

			// Initialisation de la partie
			int num_plateau = affichage->demandePlateau();
			Partie partie = Partie(vectJoueur,new Plateau(num_plateau));

			// Affichage du plateau
			affichage->affichePlateau(*partie.getPlateau());

			// Tirage au sort pour savoir qui commence
			int tourJoueur = affichage->pileOuFace(vectJoueur[0], vectJoueur[1]);	// i=0 ou 1

			// Début de la partie
			affichage->messageDebutPartie(vectJoueur[tourJoueur]);

			// Demande de placement de Impala Jones
			vectJoueur[tourJoueur]->joueurInitImpala(partie.getPlateau(), affichage); /* TODO A TESTER */

			// Détermination du joueur qui doit maintenant jouer
			int nbJoueurs = vectJoueur.size();
			if(tourJoueur == nbJoueurs-1){
				tourJoueur = 0;
			}
			else{
				tourJoueur++;
			}

			// Déroulement du jeu jusqu'à que la partie prenne fin
			int continuer = 0;
			while(continuer != 1){
				continuer = partie.deroulementJeu(vectJoueur, tourJoueur, affichage);	// = 0 si tout est ok
				if(continuer == -2){
					// Le joueur a décidé de quitter
					return 0;
				}
				else if(continuer == -1){
					cerr << "Une erreur est présente dans deroulementJeu (Partie.cpp)" << endl;
				}
				// Détermination du prochain joueur
				if(tourJoueur == nbJoueurs-1){
					tourJoueur = 0;
				}
				else{
					tourJoueur++;
				}
			}
			/* Affichage en fin de partie */
			partie.finPartie(vectJoueur,affichage);
		}

		// Afficher les règles
		else if (menu_demarrage == 3) {
			affichage->afficheRegle();
		}

		// Charger une partie
		else if (menu_demarrage == 4) {

		}

		// Quitter
		else if (menu_demarrage == 5) {
			return 0;
		}
	}

	return 0;
}
