/*
 * Regle.cpp
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#include "Regle.h"

#include "Plateau/Plateau.h"

bool Regle::colonneRempli(Plateau p, int colonne){
	int i;
	for(i=0; i<p.getTaillePlateauY(); i++){
		if(p.getCase(colonne, i).getPion() == NULL){
			return false;
		}
	}
	return true;
}

bool Regle::ligneRempli(Plateau p, int ligne){
	int i;
	for(i=0; i<p.getTaillePlateauX(); i++){
		if(p.getCase(i, ligne).getPion() == NULL){
			return false;
		}
	}
	return true;
}
