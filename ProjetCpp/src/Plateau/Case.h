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

	Pion* getPion() {
		return pion;
	}

	int getSecteur() const {
		return secteur;
	}

	void setSecteur(int secteur) {
		this->secteur = secteur;
	}

	/**
	 * Ajoute le pion en parametr ea la case
	 */
	int ajouterPion(Pion* p);

	/**
	 * Enlever le pion de la case
	 */
	int supprimerPion();
};

#endif /* CASE_H_ */
