/*
 * Affichage.cpp
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#include "Affichage.h"

#include <iostream>

int Affichage::demandeTypeAffichage(){
	cout << "======================================" << endl;
	cout << "Quel type d'affichage souhaitez-vous?" << endl;
	cout << "    1 - Affichage sur console" << endl;
	cout << "    2 - Autres (?)" << endl;
	cout << "======================================" << endl;
	int res;
	cin >> res;
	while(res!=1){
		cout << "Erreur ! Veuillez entrer un numéro compris entre 1 et 1" << endl;
		cout << "======================================" << endl;
		cout << "Quel type d'affichage souhaitez-vous?" << endl;
		cout << "    1 - Affichage sur console" << endl;
		cout << "    2 - Autres (?)" << endl;
		cout << "======================================" << endl;
		int res;
		cin >> res;
	}
	return res;
}
