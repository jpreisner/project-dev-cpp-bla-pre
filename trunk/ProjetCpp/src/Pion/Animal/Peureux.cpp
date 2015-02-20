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

/**
 * Lorsqu'un animal se cache
 */
void Peureux::seCache(){
	cache = true;
}
