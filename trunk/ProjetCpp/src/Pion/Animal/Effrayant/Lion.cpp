/*
 * Lion.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#include "Lion.h"

#include "../../../Pion.h"
#include "../../../Plateau/Case.h"
#include "../../../Plateau/Plateau.h"
#include "../Peureux/Gazelle.h"
#include "../Peureux/Zebre.h"

int Lion::action(Plateau *p, Affichage *affichage){

	// Gazelle
	if(getX()<p->getTaillePlateauX()-1 && dynamic_cast<Gazelle*>(p->getCase(getX()+1, getY())->getPion())!=NULL){
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX()+1, getY())->getPion());
		g->fuite(p);
	}
	else if(getX()>0 && dynamic_cast<Gazelle*>(p->getCase(getX()-1, getY())->getPion())!=NULL){
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX()-1, getY())->getPion());
		g->fuite(p);
	}
	else if(getX()<p->getTaillePlateauY()-1 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY()+1)->getPion())!=NULL){
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY()+1)->getPion());
		g->fuite(p);
	}
	else if(getX()>0 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY()-1)->getPion())!=NULL){
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY()-1)->getPion());
		g->fuite(p);
	}

	// Zebre
	if(getX()<p->getTaillePlateauX()-1 && dynamic_cast<Zebre*>(p->getCase(getX()+1, getY())->getPion())!=NULL){
		Zebre* z = dynamic_cast<Zebre*>(p->getCase(getX()+1, getY())->getPion());
		z->seCache();
	}
	else if(getX()>0 && dynamic_cast<Zebre*>(p->getCase(getX()-1, getY())->getPion())!=NULL){
		Zebre* z = dynamic_cast<Zebre*>(p->getCase(getX()-1, getY())->getPion());
		z->seCache();
	}
	else if(getX()<p->getTaillePlateauY()-1 && dynamic_cast<Zebre*>(p->getCase(getX(), getY()+1)->getPion())!=NULL){
		Zebre* z = dynamic_cast<Zebre*>(p->getCase(getX(), getY()+1)->getPion());
		z->seCache();
	}
	else if(getX()>0 && dynamic_cast<Zebre*>(p->getCase(getX(), getY()-1)->getPion())!=NULL){
		Zebre* z = dynamic_cast<Zebre*>(p->getCase(getX(), getY()-1)->getPion());
		z->seCache();
	}
	return 1;
}
