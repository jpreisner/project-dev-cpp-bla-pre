/*
 * JoueurReel.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef JOUEURREEL_H_
#define JOUEURREEL_H_

#include <string>

#include "../Joueur.h"

class JoueurReel: public Joueur {
public:
	JoueurReel(string nom) :
			Joueur(0, nom) {
	}
	virtual ~JoueurReel();

	friend ostream& operator<<(ostream &strm, const JoueurReel &a) {
		strm << "Joueur Reel : " << a.getNom() << endl;
		return strm;
	}
};


#endif /* JOUEURREEL_H_ */
