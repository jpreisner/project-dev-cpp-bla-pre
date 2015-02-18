/*
 * Personnage.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#include "ImpalaJones.h"

#include <iostream>

#include "../Plateau/Plateau.h"

int ImpalaJones::deplacer(int nbCases, Plateau *plateau){
	if(nbCases<0){
		cout << "Erreur ! nbCases doit etre supérieur à 0" << endl;
		return -1;
	}

	/**
	 * Gerer le cas où le joueur peut pas poser le pion pour nbCases (car toutes les cases sont prises)?
	 */

	int ancien_x = getX();
	int ancien_y = getY();

	// Cas ou ImpalaJones est sur la ligne horizontale du haut
	if(getY()==0){
		if(getX()+nbCases>=TAILLE_PLATEAU_X-1){
			nbCases-=(TAILLE_PLATEAU_X-1-getX());
			setX(TAILLE_PLATEAU_X-1);
			setY(1 + nbCases);
		}
		else{
			setX(getX()+nbCases);
		}
	}
	// Cas ou ImpalaJones est sur la ligne horizontale du bas
	else if(getY()==TAILLE_PLATEAU_Y-1){
		if(getX()-nbCases<=0){
			nbCases-=getX();
			setX(0);
			setY(TAILLE_PLATEAU_Y-2 - nbCases);
		}
		else{
			setX(getX()-nbCases);
		}
	}
	// Cas ou ImpalaJones est sur la ligne verticale du haut
	else if(getX() == 0){
		if(getY()-nbCases<=0){
			nbCases-=getY();
			setY(0);
			setX(1 + nbCases);
		}
		else{
			setY(getY()-nbCases);
		}
	}
	// Cas ou ImpalaJones est sur la ligne verticale du bas
	else if (getX() == TAILLE_PLATEAU_X-1){
		if(getY()+nbCases>=TAILLE_PLATEAU_Y-1){
			nbCases-=(TAILLE_PLATEAU_Y-1-getY());
			setY(TAILLE_PLATEAU_Y-1);
			setX(TAILLE_PLATEAU_X-2-nbCases);
		}
		else{
			setY(getY()+nbCases);
		}
	}
	else{
		cout << "Erreur! Impala Jones n'était pas bien positionné" << endl;
		return -1;
	}

	/* suppression d'Impalajones de son ancienne position */
	plateau->getCase(ancien_x, ancien_y)->supprimerPion();

	/* ajout d'impalaJones a sa nouvelle position */
	plateau->getCase(getX(), getY())->ajouterPion(this);




	return 0;
}
