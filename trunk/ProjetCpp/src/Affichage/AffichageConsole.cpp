/*
 * AffichageConsole.cpp
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#include "AffichageConsole.h"

#include <fstream>
#include <iostream>
#include <string>

#include "../Joueur.h"
#include "../Pion/Animal/Effrayant/Crocodile.h"
#include "../Pion/Animal/Effrayant/Lion.h"
#include "../Pion/Animal/Neutre/Elephant.h"
#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/Animal/Peureux/Zebre.h"
#include "../Pion.h"
#include "../Plateau/Case.h"
#include "../Plateau/Plateau.h"
#include "../Regle.h"

int AffichageConsole::menuDemarrage(){
	cout << "======================================" << endl;
	cout << "Bienvenue dans le jeu Droles de Zebres!" << endl;
	cout << "   1 - Jouer (Joueur vs Ordi)" << endl;
	cout << "   2 - Jouer (Joueur vs Joueur)" << endl;
	cout << "   3 - Regles" << endl;
	cout << "   4 - Charger une partie" << endl;
	cout << "   5 - Quitter" << endl;
	cout << "======================================" << endl;
	int res;
	cin >> res;
	while (!(res >= 1 && res <= 5)) {
		cout << "Erreur ! Veuillez entrer un chiffre compris entre 1 et 5" << endl;
		cout << "======================================" << endl;
		cout << "Bienvenue dans le jeu Droles de Zebres!" << endl;
		cout << "   1 - Jouer (Joueur vs Ordi)" << endl;
		cout << "   2 - Jouer (Joueur vs Joueur)" << endl;
		cout << "   3 - Regles" << endl;
		cout << "   4 - Charger une partie" << endl;
		cout << "   5 - Quitter" << endl;
		cout << "======================================" << endl;
		cin >> res;
	}
	return res;
}

int AffichageConsole::afficheRegle(){
	cout << "======================================" << endl;
	cout << "        Affichage des règles :        " << endl;
	cout << "======================================" << endl;
	// Lecture
	ifstream fichier("Regles.txt", ios::in);
	if (!fichier) {
		cout << "Erreur lors de l'ouverture du fichier Regles.txt" << endl;
		return -1;
	}
	// Lecture ligne par ligne
	string ligne;
	while (getline(fichier, ligne)) {
		cout << ligne << endl;
	}

	// Fin de la lecture
	fichier.close();

	int res;
	cout << "======================================" << endl;
	cout << "Entrez 1 pour retourner au menu" << endl;
	cin >> res;
	while (res != 1) {
		cout << "======================================" << endl;
		cout << "Erreur ! Veuillez entrer 1 pour retourner au menu" << endl;
		cin >> res;
	}
	return res;
}

void AffichageConsole::demandeNomJoueur(Joueur *j){
	cout << "======================================" << endl;
	cout << "Veuillez entrer le nom du joueur n°" << j->getId() << " : " << endl;
	cout << "======================================" << endl;
	string nom;
	cin >> nom;
	/** Verifier si le nom est correct? Comment? NULL? **/
	while (nom.compare("I-A") == 0) {
		cout << "Erreur ! Vous ne pouvez pas vous appeler I-A (réservé à l'ordinateur)" << endl;
		cout << "======================================" << endl;
		cout << "Veuillez entrer le nom du joueur n°" << j->getId() << " : " << endl;
		cout << "======================================" << endl;
		cin >> nom;
	}
	j->setNom(nom);
}

void AffichageConsole::affichePlateau(Plateau p){
	int i, j;

	/* Affichage des i */
	cout << "      ";
	for (i = 0; i < p.getTaillePlateauX(); i++) {
		cout << "  i=" << i << "   ";
		if (i == 0 || i == 6) {
			cout << " ";
		}
	}
	cout << "\n";

	/* Affichage de la toute 1ère ligne horizontale */
	cout << "              ";
	for (i = 1; i < p.getTaillePlateauX()-1; i++) {
		cout << "========";
	}
	cout << "=\n";

	/* Affichage du reste du plateau */
	for (j = 0; j < p.getTaillePlateauY(); j++) {
		/* Partie du haut */
		cout << "j=" << j;
		if(j!= 0 && j!=p.getTaillePlateauY()-1){
			cout << " ||";
		}
		for (i = 0; i < p.getTaillePlateauX(); i++) {
			if (i == p.getTaillePlateauX()-1) {
				cout << "|";
			}
			// Cases inaccessibles
			if ((i == 0 && j == 0) || (i == 0 && j == 6)) {
				cout << "          ";
			}
			// Cases accessibles

			/* Affichage du pion ici */
			else if (p.getCase(i, j)->getPion() != NULL) {
				cout << " " << p.getCase(i, j)->getPion()->print() << " ";
			}
			else if(!(i == 7 && j == 6) && !(i == 7 && j == 0)){
				cout << "       ";
			}
			if (i == 0) {
				cout << "|";
			}

			/* Distinction des secteurs */
			if (j != 0 && j != p.getTaillePlateauY() - 1 && i != 0
					&& i != p.getTaillePlateauX() - 1
					&& p.getCase(i, j)->getSecteur()
							== p.getCase(i + 1, j)->getSecteur()) {
				cout << " ";
			}
			else if(!((i == 7 && j == 6)  || (i == 7 && j == 0))){
				cout << "|";
			}
		}
		if(j!=0 && j!=p.getTaillePlateauY()-1){
			cout << "|";
		}
		cout << "\n";

		/* Partie du bas */
		cout << "    ";
		if(j == p.getTaillePlateauY()-1){
			cout << "  ";
		}
		else if(j == p.getTaillePlateauY()-2 || j==0){
			cout << " =";
		}
		else{
			cout << "||";
		}

		for (i = 0; i < p.getTaillePlateauX(); i++) {
			if(!(i==p.getTaillePlateauX()-1 && j==p.getTaillePlateauY()-1)){
				if (i == 7) {
					cout << "|";
				}
				// Cases inaccessibles
				if(i==0 && j==p.getTaillePlateauY()-1){
					cout << "        ";
				}
				else if ((j == 0 || j == 5 || j == 6)) {
					cout << "=======";
				}
				// Cases accessibles
				/* Distinction des secteurs */
				else if (j != 0 && j != p.getTaillePlateauY() - 1 && i != 0 && i != p.getTaillePlateauX() - 1
						&& p.getCase(i, j)->getSecteur() == p.getCase(i, j + 1)->getSecteur()) {
					cout << "       ";
				}
				else {
					cout << "-------";
				}
				if (i == 0 && j!=p.getTaillePlateauY()-1) {
					cout << "|";
				}
				if((i==0 || i == p.getTaillePlateauX()-2 || i == p.getTaillePlateauX()-1)){
					if(j == p.getTaillePlateauY()-1 || (i == p.getTaillePlateauX()-1 && j==p.getTaillePlateauY()-2)
							|| (i == p.getTaillePlateauX()-1 && j==0)){
						cout << "=";
					}
					else{
						cout << "|";
					}
				}

				else if(j==0 || j == p.getTaillePlateauY()-2 || j == p.getTaillePlateauY()-1){
					cout << "=";
				}
				else {
					cout << "o";
				}
			}
		}
		if(j!=p.getTaillePlateauY()-1 && j!=p.getTaillePlateauY()-2 && j!=0){
			cout << "|";
		}
		cout << "\n";
	}
}

int AffichageConsole::demandeDeplacerImpalaJones(Plateau p, ImpalaJones ij){
	cout << "======================================" << endl;
	int possibilite = Regle::possibiliteDeplacementImpalaJones(p, ij);
	int res;
	if (possibilite == 0) {
		cout << "Fin du jeu !" << endl;
		cout << "======================================" << endl;
		return -1;
	}
	/* Impala Jones peut etre placé sur l'une des 3 cases suivantes */
	else if (possibilite == -1) {
		cout << "Déplacement d'Impala Jones : veuillez choisir un nombre compris entre 1 et 3"
				<< endl;
		cin >> res;
		while (!(res >= 1 && res <= 3)) {
			cout << "Erreur! Veuillez choisir un nombre compris entre 1 et 3" << endl;
			cin >> res;
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones peut etre placé soit sur la prochaine case, soit sur la suivante */
	else if (possibilite == -2) {
		cout << "Déplacement d'Impala Jones : veuillez choisir entre 1 et 2" << endl;
		cin >> res;
		while (!(res == 1 || res == 2)) {
			cout << "Erreur! Veuillez choisir entre 1 et 2" << endl;
			cin >> res;
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones peut etre placé soit sur la prochaine case, soit celle plus loin de 2 cases (+3)*/
	else if (possibilite == -3) {
		cout << "Déplacement d'Impala Jones : veuillez choisir entre 1 et 3" << endl;
		cin >> res;
		while (!(res == 1 || res == 3)) {
			cout << "Erreur! Veuillez choisir entre 1 et 3" << endl;
			cin >> res;
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones peut etre placé soit sur la 2ème case suivante, soit sur la 3ème case suivante */
	else if (possibilite == -4) {
		cout << "Déplacement d'Impala Jones : veuillez choisir entre 2 et 3" << endl;
		cin >> res;
		while (!(res == 2 || res == 3)) {
			cout << "Erreur! Veuillez choisir entre 2 et 3" << endl;
			cin >> res;
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones ne peut pas etre placé sur l'une des 3 cases suivantes -> recherche de la première prochaine case libre */
	else if (possibilite > 0) {
		cout
				<< "Déplacement d'Impala Jones : vous n'avez pas la possibilité de choisir sa position car les trois cases suivantes sont pleines"
				<< endl;
		cout << "---> Impala Jones est avancé de " << possibilite << " cases" << endl;
		cout << "======================================" << endl;
		return possibilite;
	} else {
		cout << "Erreur dans l'appel de la méthode possibiliteDeplacementImpalaJones" << endl;
		cout << "======================================" << endl;
		return -1;
	}
}

void AffichageConsole::afficheListAnimal(vector<Animal*> listAnimaux){
	int nbGazelle = 0;
	int nbLion = 0;
	int nbZebre = 0;
	int nbElephant = 0;
	int nbCrocodile = 0;
	int nbPion = listAnimaux.size();
	int i;
	for (i = 0; i < nbPion; i++) {
		if (dynamic_cast<Gazelle*>(listAnimaux[i]) != NULL) {
			nbGazelle++;
		} else if (dynamic_cast<Zebre*>(listAnimaux[i]) != NULL) {
			nbZebre++;
		} else if (dynamic_cast<Elephant*>(listAnimaux[i]) != NULL) {
			nbElephant++;
		} else if (dynamic_cast<Lion*>(listAnimaux[i]) != NULL) {
			nbLion++;
		} else if (dynamic_cast<Crocodile*>(listAnimaux[i]) != NULL) {
			nbCrocodile++;
		}
	}
	cout << "Vous avez : ";
	if (nbGazelle + nbZebre + nbElephant + nbLion + nbCrocodile == 0) {
		cout << "aucun pion" << endl;
	} else {
		bool precedent = false;
		if (nbGazelle > 0) {
			cout << nbGazelle << " gazelle";
			if (nbGazelle > 1) {
				cout << "s";
			}
			precedent = true;
		}
		if (nbZebre > 0) {
			if (precedent) {
				cout << ", ";
			}
			cout << nbZebre << " zèbre";
			if (nbZebre > 1) {
				cout << "s";
			}
			precedent = true;
		}
		if (nbElephant > 0) {
			if (precedent) {
				cout << ", ";
			}
			cout << nbElephant << " éléphant";
			if (nbElephant > 1) {
				cout << "s";
			}
			precedent = true;
		}
		if (nbLion > 0) {
			if (precedent) {
				cout << ", ";
			}
			cout << nbLion << " lion";
			if (nbLion > 1) {
				cout << "s";
			}
			precedent = true;
		}
		if (nbCrocodile > 0) {
			if (precedent) {
				cout << ", ";
			}
			cout << nbCrocodile << " crocodile";
			if (nbZebre > 1) {
				cout << "s";
			}
			precedent = true;
		}
		cout << "\n";
	}
}

int AffichageConsole::selectionnerAnimal(vector<Animal*> listAnimaux){
	if (listAnimaux.size() == 0) {
		cout << "Vous n'avez pas de pion disponible" << endl;
		return -1;
	}
	cout << "======================================" << endl;
	afficheListAnimal(listAnimaux);
	cout << "Veuillez entrer le nom d'un animal" << endl;
	string nomAnimal;
	cin >> nomAnimal;
	// on met en minuscule pour ne pas avoir de probleme
	for (unsigned int i = 0; i < nomAnimal.size(); i++) {
		if (nomAnimal[i] == 'é' || nomAnimal[i] == 'è') {
			nomAnimal[i] = 'e';
		} else {
			nomAnimal[i] = tolower(nomAnimal[i]);
		}
	}
	bool ok = false;
	int res;
	while (!ok) {
		if (nomAnimal.compare("gazelle") == 0) {
			res = 1;
			ok = true;
		} else if (nomAnimal.compare("zebre") == 0) {
			res = 2;
			ok = true;
		} else if (nomAnimal.compare("elephant") == 0) {
			res = 3;
			ok = true;
		} else if (nomAnimal.compare("lion") == 0) {
			res = 4;
			ok = true;
		} else if (nomAnimal.compare("crocodile") == 0) {
			res = 5;
			ok = true;
		} else {
			cout << "Erreur ! Le nom de l'animal est incorrect" << endl;
			cout << "Veuillez entrer le nom d'un animal" << endl;

			cin >> nomAnimal;
			// on met en minuscule pour ne pas avoir de probleme
			for (unsigned int i = 0; i < nomAnimal.size(); i++) {
				if (nomAnimal[i] == 'é' || nomAnimal[i] == 'è') {
					nomAnimal[i] = 'e';
				} else {
					nomAnimal[i] = tolower(nomAnimal[i]);
				}
			}
		}
	}
	cout << "======================================" << endl;
	return res;
}

int AffichageConsole::selectionnerPosition(int *x, int *y, Plateau p){
	cout << "======================================" << endl;
	cout << "Selectionnez une case (entrez x et y) " << endl;
	int i, j;
	cin >> i >> j;
	if (!(i >= 0 && i <= p.getTaillePlateauX() && j >= 0 && j <= p.getTaillePlateauY())) {
		cout << "Erreur ! x doit etre compris entre 0 et " << p.getTaillePlateauX()
				<< " et y doit etre compris entre 0 et " << p.getTaillePlateauY() << endl;
		return -1;
	}
	if (p.getCase(i, j)->getPion() == NULL) {
		cout << "Erreur ! la case (" << i << ", " << j << ") a deja un pion" << endl;
		return -1;
	}

	/* TODO : a vérifier */
	*x = i;
	*y = j;
	cout << "======================================" << endl;
	return 0;
}

/* Pas besoin */
void AffichageConsole::affichePion(Pion *p, Joueur *j){
	/* appel de print p et de l'id du joueur */
	cout << "(" << p->print() << ", " << j->getId() << ")" << endl;
}

/* Pas besoin */
void AffichageConsole::afficheImpalaJones(){
	cout << "(IJ)";
}

int AffichageConsole::menuJoueur(Joueur *j){
	/* Afficher le nom du joueur qui doit jouer + lui proposer de poser un pion, de regarder sa liste de pion, de sauvegarder
	 * 	ou de déclarer forfait
	 */
	cout << "======================================" << endl;
	cout << "Joueur : " << j->getNom() << "(J" << j->getId() << ") :" << endl;
	cout << "Que voulez-vous faire?" << endl;
	cout << "   1 - Afficher votre liste de pions" << endl;
	cout << "   2 - Jouer un pion sur le plateau" << endl;
	cout << "   3 - Sauvegarder la partie" << endl;
	cout << "   4 - Quitter la partie" << endl;
	int res;
	cin >> res;
	while (!(res >= 1 && res <= 4)) {
		cout << "Erreur ! Veuillez entrer un nombre entre 1 et 4" << endl;
		cout << "Que voulez-vous faire?" << endl;
		cout << "   1 - Afficher votre liste de pions" << endl;
		cout << "   2 - Jouer un pion sur le plateau" << endl;
		cout << "   3 - Sauvegarder la partie" << endl;
		cout << "   4 - Quitter la partie" << endl;
		cin >> res;
	}
	cout << "======================================" << endl;
	return res;
}

int AffichageConsole::demandeLigne(Plateau p, int colonne){
	cout << "======================================" << endl;
	cout << "Veuillez entrer la ligne ou vous souhaitez poser votre pion" << endl;
	int res;
	cin >> res;
	while (!(res >= 0 && res < p.getTaillePlateauY())) {
		cout << "Erreur ! Veuillez entrer un chiffre entre 0 et " << p.getTaillePlateauY() << endl;
		cin >> res;
	}
	while (p.getCase(colonne, res)->getPion() != NULL) {
		cout << "Erreur ! La case est occupée" << endl;
		cin >> res;
		while (!(res >= 0 && res < p.getTaillePlateauY())) {
			cout << "Erreur ! Veuillez entrer un chiffre entre 0 et " << p.getTaillePlateauY()
					<< endl;
			cin >> res;
		}
	}
	cout << "======================================" << endl;
	return res;
}

int AffichageConsole::demandeColonne(Plateau p, int ligne){
	cout << "======================================" << endl;
	cout << "Veuillez entrer la colonne ou vous souhaitez poser votre pion" << endl;
	int res;
	cin >> res;
	while (!(res >= 0 && res < p.getTaillePlateauX())) {
		cout << "Erreur ! Veuillez entrer un chiffre entre 0 et " << p.getTaillePlateauX() << endl;
		cin >> res;
	}
	while (p.getCase(res, ligne)->getPion() != NULL) {
		cout << "Erreur ! La case est occupée" << endl;
		cin >> res;
		while (!(res >= 0 && res < p.getTaillePlateauX())) {
			cout << "Erreur ! Veuillez entrer un chiffre entre 0 et " << p.getTaillePlateauX()
					<< endl;
			cin >> res;
		}
	}
	cout << "======================================" << endl;
	return res;
}

int AffichageConsole::demandeChoixActionCrocodile(vector<Gazelle*> voisin, Plateau p){
	// On a besoin d'afficher au joueur le plateau actuel avant de faire une action
	affichePlateau(p);


	int res;
	int nbVoisin = voisin.size();
	cout << "======================================" << endl;
	cout << "Vous pouvez échanger votre crocodile avec " << nbVoisin << " gazelle";
	if(nbVoisin>1){
		cout << "s";
	}
	cout << "\n";

	int i;
	cout << "Que souhaitez-vous faire?" << endl;
	for(i=0; i<nbVoisin; i++){
		cout << "   " << i+1 << " - échanger avec la gazelle placée en (" << voisin[i]->getX() << ", " << voisin[i]->getY() << ")" << endl;
	}
	cout << "   " << i+1 << " - ne rien faire" << endl;
	cout << "======================================" << endl;
	cin >> res;
	while(!(res>=1 && res<=nbVoisin+1)){
		cout << "Erreur ! le chiffre entré n'est pas compris entre 1 et " << nbVoisin+1 << endl;
		cout << "Que souhaitez-vous faire?" << endl;
		for(i=0; i<nbVoisin; i++){
			cout << "   " << i+1 << " - échanger avec la gazelle placée en (" << voisin[i]->getX() << ", " << voisin[i]->getY() << ")" << endl;
		}
		cout << "   " << i+1 << " - ne rien faire" << endl;
		cout << "======================================" << endl;
		cin >> res;
	}
	return res;
}

void AffichageConsole::demandePositionInitialeImpalaJones(ImpalaJones * ij){
	int inputX = 0;
	int inputY = 0;
	cout << "======================================" << endl;
	cout << "Ou souhaitez vous deposer ImpalaJones (position en x)" << endl;
	cin >> inputX;
	cout << "Veuillez maintenant saisir la position en y" << endl;
	cin >> inputY;

	while (((inputX != 0 && inputX != TAILLE_PLATEAU_X - 1)
			&& (inputY != 0 && inputY != TAILLE_PLATEAU_Y - 1))
			|| (inputX == 0 && inputY == 0)
			|| (inputX == 0 && inputY == TAILLE_PLATEAU_Y - 1)
			|| (inputX == TAILLE_PLATEAU_X - 1 && inputY == 0)
			|| (inputX == TAILLE_PLATEAU_X - 1 && inputY == TAILLE_PLATEAU_Y - 1)) {
		cout
				<< "Erreur, vous devez le placer a une extremité du plateau, excepté dans les quarts de virage"
				<< endl;
		cout << "Position en X" << endl;
		cin >> inputX;
		cout << "Position en Y" << endl;
		cin >> inputY;
	}
	ij->setX(inputX);
	ij->setY(inputY);
}
