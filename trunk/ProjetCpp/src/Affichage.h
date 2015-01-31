/*
 * Affichage.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Guillaume
 */

#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include <iostream>
#include <string>

#include "Joueur/JoueurReel.h"
#include "Joueur/Ordinateur.h"
#include "Joueur.h"
#include "Pion/Animal/Effrayant.h"
#include "Pion/Animal/Neutre.h"
#include "Pion/Animal/Peureux.h"
#include "Plateau/Case.h"
class Plateau;

using namespace std;

class Affichage {
public:

	/*friend ostream& operator<<(ostream &strm, const Animal &a) {
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Effrayant &a) {
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Neutre &a) {
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Peureux &a) {
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Plateau &a) {
		strm << "Plateau" << endl;
		//TODO affichage ASCII/COULEUR DU PLATEAU
		return strm;

	}

	friend ostream& operator<<(ostream &strm, const Partie &a) {
		strm << "Partie" << endl;
		strm << "\t Pions Joueur 1 : " << endl;
		for (int i = 0; i < a.getJoueur1().getNbPoints(); i++) {
			strm << "\t Pion " << i << " : " << a.getJoueur1().getListAnimaux()[i]
					<< endl;
		}

		strm << "\t Pions Joueur 2 : " << endl;
		for (int i = 0; i < a.getJoueur2().getNbPoints(); i++) {
			strm << "\t Pion " << i << " : " << a.getJoueur2().getListAnimaux()[i]
					<< endl;
		}

		strm << "__________________________" << endl;
		strm << "__________PLATEAU_________" << endl;
		strm << a.getPlateau() << endl;
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Case &a) {
		return strm << "Case" << endl;
	}


	friend ostream& operator<<(ostream &strm, const Pion &a) {
		return strm << "Pion" << endl;
	}

	friend ostream& operator<<(ostream &strm, const JoueurReel &a) {
		strm << "Joueur Reel : " << a.getNom() << endl;
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Ordinateur &a) {
		strm << "Ordinateur : " << a.getNom() << endl;
		return strm;
	}

	friend ostream& operator<<(ostream &strm, const Crocodile &a) {
		return strm << "Crocodile" << endl;
	}

	friend ostream& operator<<(ostream &strm, const Lion &a) {
		return strm << "Lion" << endl;
	}

	friend ostream& operator<<(ostream &strm, const Elephant &a) {
		return strm << "Elephant" << endl;
	}

	friend ostream& operator<<(ostream &strm, const Gazelle &a) {
		return strm << "Gazelle" << endl;
	}

	friend ostream& operator<<(ostream &strm, const Zebre &a) {
		return strm << "Zebre" << endl;
	}
*/
};

#endif /* AFFICHAGE_H_ */
