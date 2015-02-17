#include "Crocodile.h"

#include <vector>

#include "../../../Affichage/Affichage.h"
#include "../../../Pion.h"
#include "../../../Plateau/Case.h"
#include "../../../Plateau/Plateau.h"
#include "../Peureux/Gazelle.h"


/**
 * Renvoie 1 si le joueur ne veut pas faire d'action, 0 sinon
 */
int Crocodile::action(Plateau *p, Affichage *affichage) {
	int secteurCroco = p->getCase(getX(), getY())->getSecteur();
	// Ajouter les voisins dans une liste
	vector<Gazelle*> voisin(0);

	// Gazelle
	if (getX()<p->getTaillePlateauX()-1 && dynamic_cast<Gazelle*>(p->getCase(getX()+1, getY())->getPion())!= NULL
			&& secteurCroco != p->getCase(getX() + 1, getY())->getSecteur()) {
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX() + 1, getY())->getPion());
		voisin.push_back(g);
	}
	if (getX() > 0 && dynamic_cast<Gazelle*>(p->getCase(getX()-1, getY())->getPion()) != NULL
			&& secteurCroco != p->getCase(getX()-1, getY())->getSecteur()) {
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX() - 1, getY())->getPion());
		voisin.push_back(g);
	}
	if (getX() < p->getTaillePlateauY() - 1 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY() + 1)->getPion()) != NULL
			&& secteurCroco != p->getCase(getX(), getY()+1)->getSecteur()) {
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY() + 1)->getPion());
		voisin.push_back(g);
	}
	if (getX() > 0 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY() - 1)->getPion()) != NULL
			&& secteurCroco != p->getCase(getX(), getY()-1)->getSecteur()) {
		Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY() - 1)->getPion());
		voisin.push_back(g);
	}

	if (voisin.size() > 0) {
		// Appel d'une fonction d'affichage
		unsigned int choix = affichage->demandeChoixActionCrocodile(voisin, *p);
		// Echanges et suppression de la liste de voisin car il va falloir calculer les nouveaux voisins
		if (choix != voisin.size() + 1) {
			p->echangerAnimalCases(this, voisin[choix-1]);
			voisin.erase(voisin.begin(), voisin.end());	// A verifier
			return 0;
		}
	}
	// Le joueur ne veut rien faire ou aucune action possible
	return 1;
}

