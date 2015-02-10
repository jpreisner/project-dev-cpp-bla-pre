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
	}

	friend ostream& operator<<(ostream &strm, const Case &a) {
		strm << "Case" << endl;
		strm << "Secteur : " << a.secteur << endl;
		if (a.pion != NULL) {
			strm << "Pion sur la case : " << a.pion << endl;
		}
		return strm;
	}

	int ajouterPion(Pion &p);

	int supprimerPion();

	Pion* getPion() {
		return pion;
	}

	int getSecteur() const {
		return secteur;
	}

	void setSecteur(int secteur) {
		this->secteur = secteur;
	}
};

#endif /* CASE_H_ */
