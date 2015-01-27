/*
 * Case.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef CASE_H_
#define CASE_H_

#include <iostream>

using namespace std;

class Case {
private:
	int secteur;
	Animal a;
public:
	Case(int secteur) :
			a(NULL),secteur(secteur) {
	}
	virtual ~Case();

	friend ostream& operator<<(ostream &strm, const Case &a) {
		return strm << "Case" << endl;
	}

	int ajouterPion(Pion p);

	int supprimerPion(Pion p);
};

#endif /* CASE_H_ */
