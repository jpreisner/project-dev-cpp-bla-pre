/*
 * Case.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef CASE_H_
#define CASE_H_

#include <stddef.h>
#include <iostream>

#include "../Pion.h"

class Pion;

using namespace std;

class Case {
private:
	int secteur;
	Pion* pion;
public:
	Case(int secteur=0) :
			secteur(secteur), pion(NULL) {
	}
	virtual ~Case();

	friend ostream& operator<<(ostream &strm, const Case &a) {
		return strm << "Case" << endl;
	}

	int ajouterPion(Pion p);

	int supprimerPion(Pion p);
};

#endif /* CASE_H_ */
