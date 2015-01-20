/*
 * Personnage.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "../Pion.h"

class Personnage: public Pion {
public:
	Personnage();
	virtual ~Personnage();
};

#endif /* PERSONNAGE_H_ */
