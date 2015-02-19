/*
 * AffichageConsole.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef AFFICHAGECONSOLE_H_
#define AFFICHAGECONSOLE_H_

#include <vector>

#include "Affichage.h"
#include "../Pion/Animal.h"
#include "../Pion/ImpalaJones.h"

class Animal;

class AffichageConsole: public Affichage {
public:
	AffichageConsole(){};
	virtual ~AffichageConsole(){};
	int menuDemarrage();
	int afficheRegle();
	void demandeNomJoueur(Joueur *j);
	void affichePlateau(Plateau p);
	int demandeDeplacerImpalaJones(Plateau p, ImpalaJones ij, int possibilite);
	void afficheListAnimal(vector<Animal*> listAnimaux);
	int selectionnerAnimal(vector<Animal*> listAnimaux);
	void affichePion(Pion *p);
	int menuJoueur(Joueur *j);
	int demandeLigne(Plateau p, int colonne);
	int demandeColonne(Plateau p, int ligne);
	void afficheImpalaJones();
	int demandeChoixActionCrocodile(vector<Gazelle*> voisin, Plateau p);
	void demandePositionInitialeImpalaJones(ImpalaJones * ij);
	int pileOuFace(Joueur *j1, Joueur *j2, int typeJeu);
	void messageDebutPartie(Joueur *j);
	void afficheTour(Joueur *j);
	int demandePlateau();
	void afficherVainqueur(Joueur* j);
	void messageBonusInnauguration(const string& nomJoueur);
	void messagePlusDePion();
	void messageInitImpalaOrdi(int x, int y);
	void afficheCoupJoueOrdi(Animal *a);
	void scoreFinal(Joueur *j1, Joueur *j2);
	bool retourMenuPrincipal();
	void finProgramme();
	/* A COMPLETER */
};

#endif /* AFFICHAGECONSOLE_H_ */
