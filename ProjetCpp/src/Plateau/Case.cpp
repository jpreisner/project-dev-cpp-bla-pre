/*
 * Case.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Case.h"

/**
 * Ajoute un pion passé en paramètre si aucun pion n'est présent
 */
int Case::ajouterPion(Pion* p){
	// ajout possible
	if(getPion()==NULL){
		pion = p;
		return 0;
	}
	// un pion est present sur la case : probleme !
	else{
		cout << "Echec! Un pion est deja present sur la case\n" << endl;
		return -1;
	}
}

/**
 * Supprime le pion de la case, s'il y en a un
 */
int Case::supprimerPion(){
	if(getPion()!=NULL){
		pion = NULL;
		return 0;
	}
	else{
		cout << "Il n'y a aucun pion a supprimer sur cette case\n" << endl;
		return -1;
	}
}
