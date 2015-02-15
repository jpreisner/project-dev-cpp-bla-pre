/*
 * Case.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#include "Case.h"

int Case::ajouterPion(Pion* p){
	cout << "Dans ajouterPion (Case.cpp), print = " << p->print();
	// ajout possible
	if(getPion()==NULL){
		cout << "On rentre dans le if" << endl;
		pion = p;	// voir si c'est ok, car pointeur sur pion
		cout << "print du pion de la case = " << pion->print();
		return 0;
	}
	// un pion est present sur la case : probleme !
	else{
		cout << "Echec! Un pion est deja present sur la case\n" << endl;
		return -1;
	}
}

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
