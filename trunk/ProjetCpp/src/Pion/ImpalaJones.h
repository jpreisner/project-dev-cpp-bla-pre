/*
 * Personnage.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Julien
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "../Pion.h"

class ImpalaJones: public Pion {
public:
	ImpalaJones();
	virtual ~ImpalaJones();

	int deplacer(int x);
};

#endif /* PERSONNAGE_H_ */
