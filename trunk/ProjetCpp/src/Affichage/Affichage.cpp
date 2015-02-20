/*
 * Affichage.cpp
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#include "Affichage.h"
#include <iostream>
#include "../Utils/SaisieSecure.h"

/**
 * Demande à l'utilisateur quel type d'affichage souhaite-t-il avoir
 * Pour le moment, seul l'affichage par console a été implémenté
 *
 *  Méthode statique
 */
int Affichage::demandeTypeAffichage(){
	cout << "======================================" << endl;
	cout << "Quel type d'affichage souhaitez-vous?" << endl;
	cout << "    1 - Affichage sur console" << endl;
	cout << "======================================" << endl;
	unsigned int res;
	SaisieSecure::saisieSecureInt(res);
	while(res!=1){
		cout << "Erreur ! Veuillez entrer un numéro compris entre 1 et 1" << endl;
		cout << "======================================" << endl;
		cout << "Quel type d'affichage souhaitez-vous?" << endl;
		cout << "    1 - Affichage sur console" << endl;
		cout << "======================================" << endl;
		SaisieSecure::saisieSecureInt(res);
	}
	return res;
}
