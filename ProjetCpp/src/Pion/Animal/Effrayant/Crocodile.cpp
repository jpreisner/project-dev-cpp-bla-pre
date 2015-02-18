#include "Crocodile.h"

#include <set>

#include "../../../Affichage/Affichage.h"
#include "../../../Pion.h"
#include "../../../Plateau/Case.h"
#include "../../../Plateau/Plateau.h"
#include "../Peureux/Gazelle.h"

/**
 * Renvoie 1 si le joueur ne veut pas faire d'action, 0 sinon
 */
void Crocodile::action(Plateau *p, Affichage *affichage) {
	set<Gazelle*> gazellesEchangees;
	bool continuer = true;
	while(continuer){
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
		if (getY() < p->getTaillePlateauY() - 1 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY() + 1)->getPion()) != NULL
				&& secteurCroco != p->getCase(getX(), getY()+1)->getSecteur()) {
			Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY() + 1)->getPion());
			voisin.push_back(g);
		}
		if (getY() > 0 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY() - 1)->getPion()) != NULL
				&& secteurCroco != p->getCase(getX(), getY()-1)->getSecteur()) {
			Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY() - 1)->getPion());
			voisin.push_back(g);
		}

		if (voisin.size() > 0) {
			// Appel d'une fonction d'affichage
			unsigned int choix = affichage->demandeChoixActionCrocodile(voisin, *p);
			// Echanges et suppression de la liste de voisin car il va falloir calculer les nouveaux voisins
			if (choix != voisin.size() + 1) {
				gazellesEchangees.insert(voisin[choix-1]);	// Gérer les doublons
				p->echangerAnimalCases(this, voisin[choix-1]);
				voisin.erase(voisin.begin(), voisin.end());	// A verifier
			}
			// Le joueur ne veut appliquer aucune action
			else{
				continuer = false;
			}
		}
		// Le joueur ne peut faire aucune action
		else{
			continuer = false;
		}
	}
	/**
	 * Faire l'appel des actions des gazelles échangées
	 */
	set<Gazelle*>::iterator it;
	for(it=gazellesEchangees.begin(); it!=gazellesEchangees.end(); it++){
		(*it)->action(p, affichage);
	}
}

