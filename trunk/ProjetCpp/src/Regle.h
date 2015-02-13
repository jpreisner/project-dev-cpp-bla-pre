/*
 * Regle.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef REGLE_H_
#define REGLE_H_
class Plateau;

class Regle {
public:
	Regle(){};
	virtual ~Regle(){};
	bool colonneRempli(Plateau p, int colonne);
	bool ligneRempli(Plateau p, int ligne);

	/* Par rapport au déplacement de Impala Jones */

	/* Par rapport aux effraiments */

	/* Détection de fin de partie */

	/* Comptage des points */


};

#endif /* REGLE_H_ */
