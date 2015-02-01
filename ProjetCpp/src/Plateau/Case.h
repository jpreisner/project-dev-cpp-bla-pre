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
	Case(int secteur = 0) :
			secteur(secteur), pion(NULL) {
	}
	virtual ~Case() {
		delete pion;
	}

	friend ostream& operator<<(ostream &strm, const Case &a) {
		return strm << "Case" << endl;
	}

	int ajouterPion(Pion p) {
		if (getPion() == NULL) {
			return -1;
		} else {
			pion = &p;
			return 0;
		}
	}

	int supprimerPion() {
		if (getPion() == NULL) {
			return -1;
		} else {
			pion = NULL;
			return 0;
		}
	}

	Pion* getPion(){
		return pion;
	}
};

#endif /* CASE_H_ */
