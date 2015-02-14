/*
 * Regle.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef REGLE_H_
#define REGLE_H_

#include "Pion/ImpalaJones.h"

class Plateau;

class Regle {
public:
	Regle(){};
	virtual ~Regle(){};

	bool colonneRempli(Plateau p, int colonne);
	bool ligneRempli(Plateau p, int ligne);
	bool finPartie(Plateau p);

	/* Par rapport au déplacement de Impala Jones */
	int possibiliteDeplacementImpalaJones(Plateau p, ImpalaJones ij);
	bool testDeplacementImpalaJones(Plateau p, int x, int y, int nbCases);

	/* Par rapport aux effraiments */

	/* Comptage des points */


};

#endif /* REGLE_H_ */
