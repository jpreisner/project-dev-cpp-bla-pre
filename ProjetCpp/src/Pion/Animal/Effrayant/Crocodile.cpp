#include "Crocodile.h"

#include <vector>

#include "../../../Affichage.h"
#include "../../../Pion.h"
#include "../../../Plateau/Case.h"
#include "../../../Plateau/Plateau.h"
#include "../Peureux/Gazelle.h"

void Crocodile::action(Plateau *p, Affichage *affichage){
	bool continuer = true;
	while(continuer){
		// Ajouter les voisins dans une liste
		vector<Gazelle*> voisin(0);

		// Gazelle
		if(getX()<p->getTaillePlateauX()-1 && dynamic_cast<Gazelle*>(p->getCase(getX()+1, getY())->getPion())!=NULL){
			Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX()+1, getY())->getPion());
			voisin.push_back(g);
		}
		else if(getX()>0 && dynamic_cast<Gazelle*>(p->getCase(getX()-1, getY())->getPion())!=NULL){
			Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX()-1, getY())->getPion());
			voisin.push_back(g);
		}
		else if(getX()<p->getTaillePlateauY()-1 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY()+1)->getPion())!=NULL){
			Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY()+1)->getPion());
			voisin.push_back(g);
		}
		else if(getX()>0 && dynamic_cast<Gazelle*>(p->getCase(getX(), getY()-1)->getPion())!=NULL){
			Gazelle* g = dynamic_cast<Gazelle*>(p->getCase(getX(), getY()-1)->getPion());
			voisin.push_back(g);
		}

		//
		if(voisin.size()>0){
			// Appel d'une fonction d'affichage
			unsigned int choix = affichage->demandeChoixActionCrocodile(voisin);
			// Echanges et suppression de la liste de voisin car il va falloir calculer les nouveaux voisins
			if(choix != voisin.size()+1){
				p->echangerAnimalCases(this, voisin[choix]);
				voisin.erase(voisin.begin(), voisin.end());	// A verifier
			}
			else{
				continuer = false;
			}
		}
		else{
			continuer = false;
		}
	}
}

