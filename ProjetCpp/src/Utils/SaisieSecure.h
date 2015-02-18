/*
 * saisieSecure.h
 *
 *  Created on: 18 févr. 2015
 *      Author: Guillaume
 */

#ifndef SAISIESECURE_H_
#define SAISIESECURE_H_
#include <limits>

using namespace std;
class SaisieSecure {
public:
	static void viderBuffer(){
		cin.clear();
		cin.seekg(0, ios::end);

		if (!cin.fail()) {
			cin.ignore(numeric_limits<streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
		}

		else {
			cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
		}
	}

	static bool saisieSecureInt(unsigned int &variable){
		string temp;
		while (true) {
			cin >> temp;

			if (cin.bad() || cin.eof()) {
				cerr << "Une erreur interne est survenue" << endl;
				if (cin.eof()) {
					return false;
				}

				viderBuffer();
				continue;

			} else if (cin.fail() || temp.find_first_not_of("0123456789") != string::npos) {
				cerr << "Erreur, saisie incorrecte." << endl;
				viderBuffer();
				continue;
			}

			viderBuffer();

			istringstream stream(temp);
			stream >> variable;

			if (stream.fail() || !stream.eof()) {
				cerr << "Erreur, saisie incorrecte." << endl;
			} else {
				return true;
			}
		}
		return false;
	}

	static bool saisieSecureChar(char &variable){
		string temp;

		while (true) {
			cin >> temp;

			if (cin.bad() || cin.eof()) {
				cerr << "Une erreur interne est survenue" << endl;
				if (cin.eof()) {
					return false;
				}

				viderBuffer();

				continue;
			}

			else if (cin.fail() || temp.length() != 1) {
				cerr << "Erreur, saisie incorrecte." << endl;
				viderBuffer();
				continue;
			}

			viderBuffer();
			variable = temp.at(0);
			return true;
		}
		return false;
	}
};
#endif /* SAISIESECURE_H_ */
