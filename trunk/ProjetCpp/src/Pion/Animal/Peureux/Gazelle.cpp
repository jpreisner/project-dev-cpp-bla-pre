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
	|| (getX()<p->getTaillePlateauY()-1 && dynamic_cast<Lion*>(p->getCase(getX(), getY()+1)->getPion())!=NULL)
	|| (getX()>0 && dynamic_cast<Lion*>(p->getCase(getX(), getY()-1)->getPion())!=NULL)){
		seCache();
	}
}
