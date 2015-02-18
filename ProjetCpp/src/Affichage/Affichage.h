/*
 * Affichage.h
 *
 *  Created on: 6 févr. 2015
 *      Author: Julien
 */

#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include <vector>

#include "../Pion/Animal/Peureux/Gazelle.h"
#include "../Pion/ImpalaJones.h"


class Joueur;
class Plateau;

using namespace std;

class Affichage {
public:
	Affichage(){};
	virtual ~Affichage(){};
	static int demandeTypeAffichage();
	virtual int menuDemarrage() = 0;
	virtual int afficheRegle() = 0;
	virtual void demandeNomJoueur(Joueur *j) = 0;
	virtual void affichePlateau(Plateau p) = 0;
	virtual int demandeDeplacerImpalaJones(Plateau p, ImpalaJones ij, int possibilite) = 0;
	virtual void afficheListAnimal(vector<Animal*> listAnimaux) = 0;
	virtual int selectionnerAnimal(vector<Animal*> listAnimaux) = 0;
	virtual void affichePion(Pion *p) = 0;
	virtual int menuJoueur(Joueur *j) = 0;
	virtual int demandeLigne(Plateau p, int colonne) = 0;
	virtual int demandeColonne(Plateau p, int ligne) = 0;
	virtual void afficheImpalaJones() = 0;
	virtual int demandeChoixActionCrocodile(vector<Gazelle*> voisin, Plateau p) = 0;
	virtual void demandePositionInitialeImpalaJones(ImpalaJones * ij)=0;
	virtual int pileOuFace(Joueur *j1, Joueur *j2, int typeJeu) = 0;
	virtual void messageDebutPartie(Joueur *j) = 0;
	virtual void afficheTour(Joueur *j) = 0;
	virtual int demandePlateau() = 0;
	virtual void afficherVainqueur(Joueur* j)=0;
	virtual void messageBonusInnauguration(const string& nomJoueur)=0;
	virtual void messagePlusDePion() = 0;
	virtual void messageInitImpalaOrdi(int x, int y) = 0;
	virtual void afficheCoupJoueOrdi(Animal *a) = 0;
	/* FIXME : mettre des "const" a chaque param ? sauf pour selectionnerPosition */
	/* A COMPLETER */
};

#endif /* AFFICHAGE_H_ */
