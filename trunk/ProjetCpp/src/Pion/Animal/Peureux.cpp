/*
 * Peureux.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#include "Peureux.h"

#include "../../Joueur.h"
#include "../../Pion.h"
#include "../../Plateau/Case.h"
#include "../../Plateau/Plateau.h"

void Peureux::seCache(){
	cache = true;
}

void Peureux::fuite(Plateau *p){
	p->getCase(getX(), getY())->supprimerPion();
	setX(-1);
	setY(-1);
	getJoueur()->getListAnimaux().push_back(this);
}
