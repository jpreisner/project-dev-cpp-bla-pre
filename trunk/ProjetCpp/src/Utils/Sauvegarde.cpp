/*
 * Sauvegarde.cpp
 *
 *  Created on: 14 févr. 2015
 *      Author: Guillaume
 */

#include "Sauvegarde.h"

#include <cstdlib>
#include <fstream>
#include <locale>
#include <vector>

#include "../Joueur/JoueurReel.h"
#include "../Joueur/Ordinateur.h"
#include "../Pion/Animal/Effrayant/Crocodile.h"
#include "../Pion/Animal/Effrayant/Lion.h"
#include "../Pion/Animal/Neutre/Elephant.h"
#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/Animal/Peureux/Zebre.h"
#include "../Pion/Animal/Peureux.h"
#include "../Pion/Animal.h"
#include "../Pion/ImpalaJones.h"
#include "../Plateau/Plateau.h"

using namespace std;

bool Sauvegarde::sauvegarderPartie(Partie p, string fileName, int idJoueur){
	ofstream fichier(fileName, ios::out | ios::trunc); // ouverture en écriture avec effacement du fichier ouvert
	if (fichier) {

		fichier << "TOUR DU JOUEUR :" << endl;
		fichier << idJoueur << endl;
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrireJoueur(p.getJoueurI(0), fichier);
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrireJoueur(p.getJoueurI(1), fichier);
		fichier << "--------------------------------" << endl;
		Sauvegarde::ecrirePlateau(*p.getPlateau(), fichier);

		fichier.close();
		return true;
	} else {
		cout << "Erreur en écrivant dans le fichier" << endl;
		return false;
	}
}

void Sauvegarde::ecrireJoueur(Joueur *j, ofstream& fichier){
	fichier << "JOUEUR" << endl;
	if (dynamic_cast<JoueurReel*>(j) != NULL) {
		fichier << "REEL" << endl;
	} else if (dynamic_cast<Ordinateur*>(j) != NULL) {
		fichier << "ORDINATEUR" << endl;
	}
	fichier << "ID : " << j->getId() << endl;
	fichier << "NOM : " << j->getNom() << endl;
	fichier << "POINTS : " << j->getNbPoints() << endl;

	int nbLions = 0;
	int nbGazelles = 0;
	int nbZebres = 0;
	int nbCrocodiles = 0;
	int nbElephant = 0;

	for (unsigned int i = 0; i < j->getListAnimaux().size(); i++) {
		if (dynamic_cast<Gazelle*>(j->getAnimal(i)) != NULL) {
			nbGazelles++;
		} else if (dynamic_cast<Zebre*>(j->getAnimal(i)) != NULL) {
			nbZebres++;
		} else if (dynamic_cast<Elephant*>(j->getAnimal(i)) != NULL) {
			nbElephant++;
		} else if (dynamic_cast<Lion*>(j->getAnimal(i)) != NULL) {
			nbLions++;
		} else if (dynamic_cast<Crocodile*>(j->getAnimal(i)) != NULL) {
			nbCrocodiles++;
		}
	}

	fichier << "-LIONS : " << nbLions << endl;
	fichier << "-GAZELLES : " << nbGazelles << endl;
	fichier << "-ZEBRES : " << nbZebres << endl;
	fichier << "-CROCODILES : " << nbCrocodiles << endl;
	fichier << "-ELEPHANT : " << nbElephant << endl;
}

void Sauvegarde::ecrirePlateau(Plateau p, ofstream& fichier){
	fichier << "PLATEAU :" << endl;
	fichier << p.getTypePlateau() << endl;
	if(p.getbonusInauguration()){
		fichier << "true" << endl;
	}else{
		fichier << "false" << endl;
	}
	for (int i = 0; i < TAILLE_PLATEAU_X; i++) {
		for (int j = 0; j < TAILLE_PLATEAU_Y; j++) {
			fichier << "-Case : (" << i << "," << j << ")" << endl;
			if (p.getCase(i, j)->getPion() != NULL) {
				Sauvegarde::ecrirePion(p.getCase(i, j)->getPion(), fichier);
			}
			fichier << "-------------" << endl;
		}
	}
}

void Sauvegarde::ecrirePion(Pion *p, ofstream& fichier){
	if (dynamic_cast<ImpalaJones*>(p) != NULL) {
		/* ImpalaJones*/
		fichier << "ImpalaJones" << endl;
	} else {
		/* un Animal*/
		if (dynamic_cast<Gazelle*>(p) != NULL) {
			Gazelle* g = dynamic_cast<Gazelle*>(p);
			fichier << "Gazelle";
			if (g->isCache()) {
				fichier << " Cachee" << endl;
			} else {
				fichier << endl;
			}
		} else if (dynamic_cast<Zebre*>(p) != NULL) {
			Zebre* z = dynamic_cast<Zebre*>(p);
			fichier << "Zebre";
			if (z->isCache()) {
				fichier << " Cachee" << endl;
			} else {
				fichier << endl;
			}
		} else if (dynamic_cast<Elephant*>(p) != NULL) {
			fichier << "Elephant" << endl;
		} else if (dynamic_cast<Lion*>(p) != NULL) {
			fichier << "Lion" << endl;
		} else if (dynamic_cast<Crocodile*>(p) != NULL) {
			fichier << "Crocodile" << endl;
		}
		Animal* a = dynamic_cast<Animal*>(p);
		fichier << a->getJoueur()->getId() << endl;
	}
}

int Sauvegarde::chargementPartie(string fileName,unsigned int& tourJoueur, Partie* partie){
	Plateau *plateau;

	vector<Joueur*> vectJoueur;
	Joueur * joueur;
	Pion* pion;

	ifstream fichier(fileName, ios::in); // ouverture en écriture avec effacement du fichier ouvert
	string nom, buf;
	string::size_type sz;
	locale loc;
	int idTourJoueur = 0;

	if (fichier) {
		string ligne;
		while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
			if (ligne.compare("TOUR DU JOUEUR :") == 0) {
				getline(fichier, buf);
				if (isdigit(buf[0], loc)) {
					idTourJoueur = atoi(buf.c_str());
				}
			}

			if (ligne.compare("JOUEUR") == 0) {
				string nom;
				int i_id, i_points, i_lions, i_gazelles, i_zebres, i_crocodiles, i_elephants;
				bool jreel = false;

				getline(fichier, buf);
				if (buf.compare("REEL") == 0) {
					jreel = true;
				}

				/* ID */
				getline(fichier, buf);
				if (isdigit(buf[5], loc)) {
					i_id = atoi(buf.substr(5).c_str());
				}

				/* NOM */
				getline(fichier, nom);
				nom = nom.substr(6);

				/* POINTS */
				getline(fichier, buf);
				if (isdigit(buf[9], loc)) {
					i_points = atoi(buf.substr(9).c_str());
				}

				/* NBLIONS */
				getline(fichier, buf);
				if (isdigit(buf[9], loc)) {
					i_lions = atoi(buf.substr(9).c_str());
				}

				/* NBGAZELLE */
				getline(fichier, buf);
				if (isdigit(buf[12], loc)) {
					i_gazelles = atoi(buf.substr(12).c_str());
				}

				/* NBZEBRES */
				getline(fichier, buf);
				if (isdigit(buf[10], loc)) {
					i_zebres = atoi(buf.substr(10).c_str());
				}

				/* NBCROCODILES */
				getline(fichier, buf);
				if (isdigit(buf[14], loc)) {
					i_crocodiles = atoi(buf.substr(14).c_str());
				}

				/* NBELEPHANTS */
				getline(fichier, buf);
				if (isdigit(buf[12], loc)) {
					i_elephants = atoi(buf.substr(12).c_str());
				}

				if (jreel) {
					joueur = new JoueurReel(i_points, nom, i_gazelles, i_zebres, i_elephants,
							i_lions, i_crocodiles);
				} else {
					joueur = new Ordinateur(i_points, nom, i_gazelles, i_zebres, i_elephants,
							i_lions, i_crocodiles);

				}
				/* creer joueur */
				vectJoueur.push_back(joueur);

			} else if (ligne.compare("PLATEAU :") == 0) {
				int plateauId;
				int joueurIdPion;
				bool bonusInnauguration;
				int xCase;
				int yCase;
				getline(fichier, buf);
				if (isdigit(buf[0], loc)) {
					plateauId = atoi(buf.c_str());
				}

				plateau = new Plateau(plateauId);

				/* bonus innauguration*/
				getline(fichier, buf);

				if (buf.compare("true") == 0) {
					bonusInnauguration = true;
				}else{
					bonusInnauguration = false;
				}

				plateau = new Plateau(plateauId,bonusInnauguration);
				/* parcours des cases */

				for (int i = 0; i < TAILLE_PLATEAU_X; i++) {
					for (int j = 0; j < TAILLE_PLATEAU_Y; j++) {
						getline(fichier, buf);
						//cerr<<buf<<endl;
						if (buf.compare("-------------") == 0) {
							getline(fichier, buf);

						}

						string strCase("-Case : ");

						// on recupere les positions de x et x
						if (buf.find(strCase) != string::npos) {
							if (isdigit(buf[9], loc)) {
								xCase = atoi(buf.substr(9).c_str());
							}
							if (isdigit(buf[11], loc)) {
								yCase = atoi(buf.substr(11).c_str());
							}
						}

						getline(fichier, buf);

						// Il y a un pion dans la case
						if (buf.compare("-------------") != 0) {
							//IMPALA JONES
							if (buf.compare("ImpalaJones") == 0) {
								pion = new ImpalaJones(xCase, yCase);
								/* Ajouter Impala */
								pion->setX(xCase);
								pion->setY(yCase);
							//	cout<<"INIT IMPALA"<<endl;
								plateau->initImpalaJones(dynamic_cast<ImpalaJones*>(pion));

							} else {
								//ANIMAL

								string G = "Gazelle";
								string Z = "Zebre";
								string E = "Elephant";
								string L = "Lion";
								string C = "Crocodile";

								if (buf.find(G) != string::npos) {
								//	cout<<"Gazelle"<<endl;
									pion = new Gazelle();
									/*Cachée */
									if (buf.find("Cachee") != string::npos) {
										Peureux * p = dynamic_cast<Peureux*>(pion);
										p->setCache(true);
									}
								} else if (buf.find(Z) != string::npos) {
								//	cout<<"Zebre"<<endl;

									pion = new Zebre();
									/*Cachée */
									if (buf.find("Cachee") != string::npos) {
										Peureux * p = dynamic_cast<Peureux*>(pion);
										p->setCache(true);
									}
								} else if (buf.compare(E)==0) {
								//	cout<<"Elephant"<<endl;
									pion = new Elephant();

								} else if (buf.compare(L)==0) {
								//	cout<<"Lion"<<endl;
									pion = new Lion();

								} else if (buf.compare(C)==0) {
								//	cout<<"Crocodile"<<endl;
									pion = new Crocodile();
								}
								/* ID JOUEUR*/
								getline(fichier, buf);
								if (isdigit(buf[0], loc)) {
									joueurIdPion = atoi(buf.substr(0).c_str());
									Animal * a = dynamic_cast<Animal*>(pion);
									for (unsigned int i = 0; i < vectJoueur.size(); i++) {
										if (joueurIdPion == vectJoueur[i]->getId()) {
											a->setJoueur(vectJoueur[i]);
										}
									}
								}

							}
							/* AjouterPion */
							pion->setX(xCase);
							pion->setY(yCase);
							plateau->getCase(xCase, yCase)->ajouterPion(pion);
						}
					}
				}
			}
		}
	} else {
		cerr << "problème dans l'ouverture du fichier de sauvegarde" << endl;
		return -1;
	}

	/*TODO Ajouter, et gerer bonus innaurugation a ne pas donner 2 fois */
	partie = new Partie(vectJoueur, plateau);

	for(unsigned int i=0;i<vectJoueur.size();i++){
		if(idTourJoueur == vectJoueur[i]->getId()){
			tourJoueur = i;
		}
	}
	return 0;
}
