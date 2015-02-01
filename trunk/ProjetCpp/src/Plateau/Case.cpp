/*
 * Case.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Case.h"

int Case::ajouterPion(Pion p){
	// ajout possible
	if(getPion()!=NULL){
		pion = &p;	// voir si c'est ok, car pointeur sur pion
		return 0;
	}
	// un pion est present sur la case : probleme !
	else{
		cout << "Echec! Un pion est deja present sur la case" << endl;
		return -1;
	}
}

int Case::supprimerPion(){
	if(getPion()!=NULL){
		pion = NULL;	// appeler delete car pointeur?
		return 0;
	}
	else{
		cout << "Il n'y a aucun pion a supprimer sur cette case" << endl;
		return -1;
	}
}
