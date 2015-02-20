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

/**
 * Action provoqué lorsque une gazelle est posée sur le plateau : elle se cache s'il y a un (ou plusieurs) lion sur les cases voisines
 */
void Gazelle::action(Plateau *p, Affichage *affichage){
	if((getX()<p->getTaillePlateauX()-1 && dynamic_cast<Lion*>(p->getCase(getX()+1, getY())->getPion())!=NULL)
	|| (getX()>0 && dynamic_cast<Lion*>(p->getCase(getX()-1, getY())->getPion())!=NULL)
	|| (getY()<p->getTaillePlateauY()-1 && dynamic_cast<Lion*>(p->getCase(getX(), getY()+1)->getPion())!=NULL)
	|| (getY()>0 && dynamic_cast<Lion*>(p->getCase(getX(), getY()-1)->getPion())!=NULL)){
		seCache();
	}
}

/**
 * Lorsqu'un lion est posé à côté d'une gazelle, celle-ci fuit et retourne dans les mains de son joueur
 */
void Gazelle::fuite(Plateau *p){
	p->getCase(getX(), getY())->supprimerPion();
	setX(-1);
	setY(-1);
	getJoueur()->getListAnimaux().push_back(this);
}
