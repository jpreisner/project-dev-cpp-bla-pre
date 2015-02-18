/*
 * Gazelle.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#include "Gazelle.h"

#include "../../../Pion.h"
#include "../../../Plateau/Case.h"
#include "../../../Plateau/Plateau.h"
#include "../Effrayant/Lion.h"

void Gazelle::action(Plateau *p, Affichage *affichage){
	if((getX()<p->getTaillePlateauX()-1 && dynamic_cast<Lion*>(p->getCase(getX()+1, getY())->getPion())!=NULL)
	|| (getX()>0 && dynamic_cast<Lion*>(p->getCase(getX()-1, getY())->getPion())!=NULL)
	|| (getY()<p->getTaillePlateauY()-1 && dynamic_cast<Lion*>(p->getCase(getX(), getY()+1)->getPion())!=NULL)
	|| (getY()>0 && dynamic_cast<Lion*>(p->getCase(getX(), getY()-1)->getPion())!=NULL)){
		seCache();
	}
}

void Gazelle::fuite(Plateau *p){
	p->getCase(getX(), getY())->supprimerPion();
	setX(-1);
	setY(-1);
	getJoueur()->getListAnimaux().push_back(this);
}
