//============================================================================
// Name        : ProjetCpp.cpp
// Author      : G
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Affichage/AffichageConsole.h"
#include "Affichage/Affichage.h"
#include "Joueur/JoueurReel.h"
#include "Joueur/Ordinateur.h"
#include "Plateau/Plateau.h"
#include "Joueur.h"
#include "Partie.h"
#include "Regle.h"

using namespace std;

int main(){

	cout << "======================================" << endl;
	cout << "            Drôle de Zèbres           " << endl;
	cout << "======================================" << endl;
	int typeAffichage = Affichage::demandeTypeAffichage();
	Affichage * affichage = NULL;

	if (typeAffichage == 1) {
		affichage = new AffichageConsole();
	} else {

	}

	int menu_demarrage = affichage->menuDemarrage();

	// Lancer la partie (entre joueur et ordi)
	if (menu_demarrage == 1 || menu_demarrage == 2) {
		/* initialisation JOUEUR 1*/
		Joueur *joueur1 = new JoueurReel("");
		affichage->demandeNomJoueur(joueur1);

		/* initialisation JOUEUR 2*/
		Joueur *joueur2 = NULL;
		if (menu_demarrage == 2) {
			joueur2 = new JoueurReel("");
			affichage->demandeNomJoueur(joueur2);
		} else {
			joueur2 = new Ordinateur();
		}

		vector<Joueur*> vectJoueur;
		vectJoueur.push_back(joueur1);
		vectJoueur.push_back(joueur2);

		/* initialisation PLATEAU*/
		Plateau *plateau = new Plateau();
		Partie partie = Partie(vectJoueur,plateau);

		/* affichage plateau*/
		affichage->affichePlateau(*plateau);

		/* InitPartie */
		affichage->demandePositionInitialeImpalaJones(plateau->getImpalaJones());
		partie.lancerPartie(plateau->getImpalaJones()->getX(), plateau->getImpalaJones()->getY());

		/* JEU, JUSQUA CE QUE LA PARTIE SOIE FINIE*/
		int nbJoueurs = vectJoueur.size();
		int tourJoueur = 0;
		while (!Regle::finPartie(*plateau)) {
			cout<< "\n"<<endl;
			/* affichage plateau*/
			affichage->affichePlateau(*plateau);

			cout<< "======================================"<<endl;
			cout<< "\t Tour du joueur : "<<partie.getJoueurI(tourJoueur)->getNom()<<endl;

			partie.getJoueurI(tourJoueur)->jouer(plateau,affichage);
			affichage->affichePlateau(*plateau);
			affichage->demandeDeplacerImpalaJones(*partie.getPlateau(),*partie.getPlateau()->getImpalaJones());
			if(tourJoueur == nbJoueurs){
				tourJoueur = 0;
			}else{
				tourJoueur++;
			}
		}
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

	return 0;
}
