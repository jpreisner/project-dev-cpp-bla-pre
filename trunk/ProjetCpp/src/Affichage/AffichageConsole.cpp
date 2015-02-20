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
#include <cstdlib>


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
#include "../Utils/SaisieSecure.h"

/**
 * Menu affiché au tout debut du programme (avant le lancement d'une partie)
 * Renvoie ce que l'utilisateur souhaite faire
 */
int AffichageConsole::menuDemarrage(){
	cout << "======================================" << endl;
	cout << "Bienvenue dans le jeu Droles de Zebres!" << endl;
	cout << "   1 - Jouer (Joueur vs Ordi)" << endl;
	cout << "   2 - Jouer (Joueur vs Joueur)" << endl;
	cout << "   3 - Regles" << endl;
	cout << "   4 - Charger une partie" << endl;
	cout << "   5 - Quitter" << endl;
	cout << "======================================" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
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
		SaisieSecure::saisieSecureInt(res);
	}
	return res;
}

/**
 * Affiche les règles présentes dans le fichiers Regles.txt
 */
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

	unsigned int res;
	cout << "======================================" << endl;
	cout << "Entrez 1 pour retourner au menu" << endl;
	SaisieSecure::saisieSecureInt(res);
	while (res != 1) {
		cout << "======================================" << endl;
		cout << "Erreur ! Veuillez entrer 1 pour retourner au menu" << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	return res;
}

/**
 * Demande le nom d'un joueur, et l'attribut au joueur passé en paramètre
 */
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

/**
 * Affiche le plateau sur la console
 */
void AffichageConsole::affichePlateau(Plateau p){
	unsigned int i, j;

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
				affichePion(p.getCase(i, j)->getPion());
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

/**
 * Demande à l'utilisateur d'entrer le nombre de case qu'il souhaite déplacer Impala Jones, si cela est possible
 * Interprète l'entier possibilite qui résulte de l'appel de la fonction possibiliteDeplacementImpalaJones dans Regle.cpp
 */
int AffichageConsole::demandeDeplacerImpalaJones(Plateau p, ImpalaJones ij, int possibilite){
	cout << "======================================" << endl;
	unsigned int res;
	if (possibilite == 0) {
		cout << "Fin du jeu !" << endl;
		cout << "======================================" << endl;
		return -1;
	}
	/* Impala Jones peut etre placé sur l'une des 3 cases suivantes */
	else if (possibilite == -1) {
		cout << "Déplacement d'Impala Jones : veuillez choisir un nombre compris entre 1 et 3"<< endl;
		SaisieSecure::saisieSecureInt(res);
		while (!(res >= 1 && res <= 3)) {
			cout << "Erreur! Veuillez choisir un nombre compris entre 1, 2 et 3" << endl;
			SaisieSecure::saisieSecureInt(res);
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones peut etre placé soit sur la prochaine case, soit sur la suivante */
	else if (possibilite == -2) {
		cout << "Déplacement d'Impala Jones : veuillez choisir entre 1 et 2" << endl;
		SaisieSecure::saisieSecureInt(res);
		while (!(res == 1 || res == 2)) {
			cout << "Erreur! Veuillez choisir entre 1 et 2" << endl;
			SaisieSecure::saisieSecureInt(res);
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones peut etre placé soit sur la prochaine case, soit celle plus loin de 2 cases (+3)*/
	else if (possibilite == -3) {
		cout << "Déplacement d'Impala Jones : veuillez choisir entre 1 et 3" << endl;
		SaisieSecure::saisieSecureInt(res);
		while (!(res == 1 || res == 3)) {
			cout << "Erreur! Veuillez choisir entre 1 et 3" << endl;
			SaisieSecure::saisieSecureInt(res);
		}
		cout << "======================================" << endl;
		return res;
	}
	/* Impala Jones peut etre placé soit sur la 2ème case suivante, soit sur la 3ème case suivante */
	else if (possibilite == -4) {
		cout << "Déplacement d'Impala Jones : veuillez choisir entre 2 et 3" << endl;
		SaisieSecure::saisieSecureInt(res);
		while (!(res == 2 || res == 3)) {
			cout << "Erreur! Veuillez choisir entre 2 et 3" << endl;
			SaisieSecure::saisieSecureInt(res);
		}
		cout << "======================================" << endl;
		return res;
	}


	/* Impala Jones ne peut pas etre placé que a la case +1  */
	else if (possibilite == -5) {
		cout << "Déplacement d'Impala Jones : vous n'avez pas la possibilité de choisir sa position car les cases (+2) et (+3) sont pleines"<< endl;
		cout << "---> Impala Jones est avancé de 1 case" << endl;
		cout << "======================================" << endl;
		return 1;
	}
	/* Impala Jones ne peut pas etre placé que a la case +2  */
	else if (possibilite == -6) {
		cout << "Déplacement d'Impala Jones : vous n'avez pas la possibilité de choisir sa position car les cases (+1) et (+3) sont pleines"<< endl;
		cout << "---> Impala Jones est avancé de 2 cases" << endl;
		cout << "======================================" << endl;
		return 2;
	}
	/* Impala Jones ne peut pas etre placé que a la case +3  */
	else if (possibilite == -7) {
		cout << "Déplacement d'Impala Jones : vous n'avez pas la possibilité de choisir sa position car les cases (+2) et (+3) sont pleines"<< endl;
		cout << "---> Impala Jones est avancé de 3 cases" << endl;
		cout << "======================================" << endl;
		return 3;
	}
	/* Impala Jones ne peut pas etre placé sur l'une des 3 cases suivantes -> recherche de la première prochaine case libre */
	else if (possibilite > 0) {
		cout << "Déplacement d'Impala Jones : vous n'avez pas la possibilité de choisir sa position car les trois cases suivantes sont pleines"<< endl;
		cout << "---> Impala Jones est avancé de " << possibilite << " cases" << endl;
		cout << "======================================" << endl;
		return possibilite;
	}
	else {
		cout << "Erreur dans l'appel de la méthode possibiliteDeplacementImpalaJones" << endl;
		cout << "======================================" << endl;
		return -1;
	}
}

/**
 * Affiche une liste d'animaux
 */
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
			if (nbCrocodile > 1) {
				cout << "s";
			}
			precedent = true;
		}
		cout << "\n";
	}
}

/**
 * Demande au joueur d'entrer le nom d'un animal et renvoie un entier :
 *  1 = gazelle
 *  2 = zebre
 *  3 = elephant
 *  4 = lion
 *  5 = crocodile
 */
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
	unsigned int res;
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

/**
 * Affichage d'un pion : gère le cas d'un animal caché
 */
void AffichageConsole::affichePion(Pion *p){
	/* appel de print p et de l'id du joueur */
	if(dynamic_cast<Animal*> (p) != NULL){
		Peureux* peureux = dynamic_cast<Peureux*>(p);
		if(peureux != NULL && peureux->isCache()){
			cout << " (-," << peureux->getJoueur()->getId() << ") ";
		}
		else{
			cout << " " << p->print() << " ";
		}
	}
	else{
		afficheImpalaJones();
	}
}

/**
 * Affichage d'Impala Jones
 */
void AffichageConsole::afficheImpalaJones(){
	cout << " (I.J) ";
}

/*
 * Affiche le nom du joueur qui doit jouer + lui proposer de poser un pion, de regarder sa liste de pion, de sauvegarder
 * 	ou de déclarer forfait
 */
int AffichageConsole::menuJoueur(Joueur *j){
	cout << "======================================" << endl;
	cout << "Joueur : " << j->getNom() << "(J" << j->getId() << ") :" << endl;
	cout << "Que voulez-vous faire?" << endl;
	cout << "   1 - Afficher votre liste de pions" << endl;
	cout << "   2 - Jouer un pion sur le plateau" << endl;
	cout << "   3 - Sauvegarder la partie" << endl;
	cout << "   4 - Quitter la partie" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
	while (!(res >= 1 && res <= 4)) {
		cout << "Erreur ! Veuillez entrer un nombre entre 1 et 4" << endl;
		cout << "Que voulez-vous faire?" << endl;
		cout << "   1 - Afficher votre liste de pions" << endl;
		cout << "   2 - Jouer un pion sur le plateau" << endl;
		cout << "   3 - Sauvegarder la partie" << endl;
		cout << "   4 - Quitter la partie" << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	cout << "======================================" << endl;
	return res;
}

/**
 * Demande au joueur de selectionner une ligne disponible dans le plateau, lorsque Impala Jones est positionné à la colonne
 * passée en paramètre
 */
int AffichageConsole::demandeLigne(Plateau p, int colonne){
	cout << "======================================" << endl;
	cout << "Veuillez entrer la ligne ou vous souhaitez poser votre pion" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
	while (!(res >= 1 && res <= p.getTaillePlateauY()-2)) {
		cout << "Erreur ! Veuillez entrer un chiffre entre 1 et " << p.getTaillePlateauY()-2 << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	while (p.getCase(colonne, res)->getPion() != NULL) {
		cout << "Erreur ! La case est occupée" << endl;
		SaisieSecure::saisieSecureInt(res);
		while (!(res >= 1 && res <= p.getTaillePlateauY()-2)) {
			cout << "Erreur ! Veuillez entrer un chiffre entre 1 et " << p.getTaillePlateauY()-2 << endl;
			SaisieSecure::saisieSecureInt(res);
		}
	}
	cout << "======================================" << endl;
	return res;
}

/**
 * Demande au joueur de selectionner une colonne disponible dans le plateau, lorsque Impala Jones est positionné à la ligne
 * passée en paramètre
 */
int AffichageConsole::demandeColonne(Plateau p, int ligne){
	cout << "======================================" << endl;
	cout << "Veuillez entrer la colonne ou vous souhaitez poser votre pion" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
	while (!(res >= 1 && res <= p.getTaillePlateauX()-2)) {
		cout << "Erreur ! Veuillez entrer un chiffre entre 1 et " << p.getTaillePlateauX()-2 << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	while (p.getCase(res, ligne)->getPion() != NULL) {
		cout << "Erreur ! La case est occupée" << endl;
		SaisieSecure::saisieSecureInt(res);
		while (!(res >= 1 && res <= p.getTaillePlateauX()-2)) {
			cout << "Erreur ! Veuillez entrer un chiffre entre 0 et " << p.getTaillePlateauX()-2 << endl;
			SaisieSecure::saisieSecureInt(res);
		}
	}
	cout << "======================================" << endl;
	return res;
}

/**
 * Demande au joueur ce qu'il souhaite faire lorsque l'action du crocodile est "activée"
 * (soit quand il y a possibilité d'échanger avec une gazelle)
 */
int AffichageConsole::demandeChoixActionCrocodile(vector<Gazelle*> voisin, Plateau p){
	// On a besoin d'afficher au joueur le plateau actuel avant de faire une action
	affichePlateau(p);

	unsigned int res;
	unsigned int nbVoisin = voisin.size();
	cout << "======================================" << endl;
	cout << "Vous pouvez échanger votre crocodile avec " << nbVoisin << " gazelle";
	if(nbVoisin>1){
		cout << "s";
	}
	cout << "\n";

	unsigned int i;
	cout << "Que souhaitez-vous faire?" << endl;
	for(i=0; i<nbVoisin; i++){
		cout << "   " << i+1 << " - échanger avec la gazelle placée en (" << voisin[i]->getX() << ", " << voisin[i]->getY() << ")" << endl;
	}
	cout << "   " << i+1 << " - ne rien faire" << endl;
	cout << "======================================" << endl;
	SaisieSecure::saisieSecureInt(res);
	while(!(res>=1 && res<=nbVoisin+1)){
		cout << "Erreur ! le chiffre entré n'est pas compris entre 1 et " << nbVoisin+1 << endl;
		cout << "Que souhaitez-vous faire?" << endl;
		for(i=0; i<nbVoisin; i++){
			cout << "   " << i+1 << " - échanger avec la gazelle placée en (" << voisin[i]->getX() << ", " << voisin[i]->getY() << ")" << endl;
		}
		cout << "   " << i+1 << " - ne rien faire" << endl;
		cout << "======================================" << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	return res;
}

/**
 * Demande au joueur qui joue en 1er de positionner Impala Jones
 *  ==> modifie x et y de Impala Jones, le positionnement dans le Plateau s'effectuera dans Plateau
 */
void AffichageConsole::demandePositionInitialeImpalaJones(ImpalaJones * ij){
	unsigned int inputX = 0;
	unsigned int inputY = 0;
	cout << "======================================" << endl;
	cout << "Ou souhaitez vous deposer ImpalaJones (position en x)" << endl;
	SaisieSecure::saisieSecureInt(inputX);
	cout << "Veuillez maintenant saisir la position en y" << endl;
	SaisieSecure::saisieSecureInt(inputY);

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
		SaisieSecure::saisieSecureInt(inputX);
		cout << "Position en Y" << endl;
		SaisieSecure::saisieSecureInt(inputY);
	}
	ij->setX(inputX);
	ij->setY(inputY);
}

/**
 * Implémentation du jeu "pile ou face" : renvoie un entier correspondant au joueur qui doit jouer en premier
 * 0 : joueur 1 joue en 1er
 * 1 : joueur 2 joue en 1er
 */
int AffichageConsole::pileOuFace(Joueur *j1, Joueur *j2, int typeJeu){
	cout << "======================================" << endl;
	cout << "Tirage au sort pour déterminer le 1er qui joue (Pile ou Face) : ";
	int random;
	if(typeJeu == 1){
		random = 0;
	}
	else{
		random = rand()%2;
	}

	if(random == 0){
		cout << j1->getNom();
	}
	else{
		cout << j2->getNom();
	}
	cout << ", choisissez pile (P) ou face (F)" << endl;
	char res;
	SaisieSecure::saisieSecureChar(res);
	res = tolower(res);
	while(res != 'p' && res != 'f' ){
		cout << "Erreur ! Veuillez entrez P (pour pile) ou F (pour face)" << endl;
		SaisieSecure::saisieSecureChar(res);
		res = tolower(res);
	}

	int random_pile_face = rand()%2;	// 0 = pile, 1 = face
	if(random_pile_face == 0){
		cout << "Pile ! ";
	}
	else{
		cout << "Face ! ";
	}
	if((random_pile_face == 0 && res == 'p') || (random_pile_face == 1 && res == 'f')){
		// Le joueur n°(random) a gagné
		if(random == 0){
			cout << j1->getNom() << ", vous avez gagné !" << endl;
		}
		else{
			cout << j2->getNom() << ", vous avez gagné !" << endl;
		}
		return random;
	}
	else{
		// Le joueur n°(random) a perdu
		if(random == 1){
			cout << j1->getNom() << ", vous avez gagné !" << endl;
			return 0;
		}
		cout << j2->getNom() << ", vous avez gagné !" << endl;
		return 1;
	}
}

/**
 * Message indiquant au joueur passé en paramètre qu'il doit jouer en 1er
 */
void AffichageConsole::messageDebutPartie(Joueur *j){
	cout << j->getNom() << " : à vous de commencer !" << endl;
}

/**
 * Message indiquant qui doit jouer
 */
void AffichageConsole::afficheTour(Joueur *j){
	cout<< "======================================"<<endl;
	cout<< "\t Tour du joueur n°" << j->getId() << " : "<<j->getNom()<<endl;
}

/**
 * Message au début du jeu avant le lancement d'une partie
 * Demande aux joueurs sur quels plateaux souhaitent-ils jouer
 */
int AffichageConsole::demandePlateau(){
	cout<< "======================================"<<endl;
	cout << "Choisissez un plateau :" << endl;
	cout << "   1 - Plateau normal" << endl;
	cout << "   2 - Réserve du Président" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
	while(res!=1 && res!=2){
		cout << "Erreur ! Veuillez choisir un nombre compris entre 1 et 2" << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	cout<< "======================================"<<endl;
	return res;
}

/**
 * Affiche le vainqueur (passé en paramètre)
 */
void AffichageConsole::afficherVainqueur(Joueur* j){
	cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout << "FELICITATIONS " << j->getNom()<<", vous remportez la partie"<< endl;
	cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
}

/**
 * Affiche qui a obtenu le bonus d'inauguration
 */
void AffichageConsole::messageBonusInauguration(const string& nomJoueur){
	cout<< "-----------------------"<<endl;
	cout << "FELICITATIONS " << nomJoueur<<", vous obtenez le bonus inauguration (+5)"<< endl;
	cout<< "-----------------------"<<endl;
}

/**
 * Affiche un message comme quoi le joueur n'a plus de pion dans sa main
 */
void AffichageConsole::messagePlusDePion(){
	cout<< "======================================"<<endl;
	cout << "Vous n'avez plus de pion, vous ne pouvez donc pas jouer !" << endl;
	cout<< "======================================"<<endl;
}

/**
 * Message indiquant que l'ordinateur a poser Impala Jones en (x,y)
 */
void AffichageConsole::messageInitImpalaOrdi(int x, int y){
	cout<< "======================================"<<endl;
	cout << "L'ordinateur a positionné Impala Jones en (" << x << ", " << y << ")" << endl;
	cout<< "======================================"<<endl;
}

/**
 * Message indiquant ce qu'a jouer l'ordinateur en (x,y)
 */
void AffichageConsole::afficheCoupJoueOrdi(Animal *a){
	cout<< "======================================"<<endl;
	cout << "L'ordinateur a joué" << a->print() << " en (" << a->getX() << ", " << a->getY() << ")" << endl;
	cout<< "======================================"<<endl;
}

/**
 * Message indiquant que la sauvegarde a correctement été effectuée
 */
void AffichageConsole::afficheSauvegarde(){
	cout << "Sauvegarde bien effectuée dans le fichier save.txt" << endl;
}

/**
 * Affiche le score final des 2 joueurs
 */
void AffichageConsole::scoreFinal(Joueur *j1, Joueur *j2){
	cout << "Score final : " << j1->getNom() << " : " << j1->getNbPoints() << " points, et  " << j2->getNom() << " : " << j2->getNbPoints() << "points" << endl;
}

/**
 * Message affiché en fin de partie, propose à l'utilisateur s'il souhaite retourner au menu principal ou quitter
 * 1 = oui, il souhaite retourner au menu principal
 * 2 = non
 */
bool AffichageConsole::retourMenuPrincipal(){
	cout<< "======================================"<<endl;
	cout << "Voulez-vous revenir au menu principal ?"<< endl;
	cout << "   1 - Oui" << endl;
	cout << "   2 - Non" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
	while(res!=1 && res!=2){
		cout << "Erreur ! Veuillez choisir un nombre compris entre 1 et 2" << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	cout<< "======================================"<<endl;
	if(res == 1){
		return true;
	}
	return false;
}

/**
 * Message d'au revoir, lorsque le joueur sort du programme après avoir décider qu'il ne souhaitait pas retourner au menu principal
 * (méthode précédente)
 */
void AffichageConsole::finProgramme(){
	cout<< "======================================"<<endl;
	cout << "A bientot !" << endl;
	cout<< "======================================"<<endl;
}
