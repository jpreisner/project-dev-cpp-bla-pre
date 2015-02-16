/*
 * Joueur.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Guillaume
 */

#include "Joueur.h"

#include "Pion/Animal/Effrayant/Crocodile.h"
#include "Pion/Animal/Effrayant/Lion.h"
#include "Pion/Animal/Neutre/Elephant.h"
#include "Pion/Animal/Peureux/Gazelle.h"
#include "Pion/Animal/Peureux/Zebre.h"

void Joueur::initListPions(int nbGazelles, int nbZebres, int nbElephants, int nbLions,
		int nbCrocos){
	int i;

	// 6 gazelles
	for (i = 0; i < nbGazelles; i++) {
		listAnimaux.push_back((new Gazelle(this)));
	}
	// 5 zebres
	for (i = 0; i < nbZebres; i++) {
		listAnimaux.push_back((new Zebre(this)));
	}
	// 1 elephant
	for (i = 0; i < nbElephants; i++) {
		listAnimaux.push_back((new Elephant(this)));
	}
	// 1 lion
	for (i = 0; i < nbLions; i++) {
		listAnimaux.push_back((new Lion(this)));
	}
	// 2 crocodiles
	for (i = 0; i < nbCrocos; i++) {
		listAnimaux.push_back((new Crocodile(this)));
	}
}


int Joueur::placementAnimal(Animal a, int x, int y){
	return 0;
}

void Joueur::ajouterPoints(int nb){
	setNbPoints(getNbPoints() + nb);
}


/*
Animal* Joueur::selectAnimal(Affichage affichage){
	int id_animal = affichage.selectionnerAnimal(getListAnimaux());
	int nbPion = getListAnimaux().size();
	int pos = 0;
	bool ok = false;
	while(!ok){
		// Gazelle
		if(id_animal == 1){
			while(pos<nbPion){
				if(dynamic_cast<Gazelle*>(listAnimaux[pos]) == NULL){
					pos++;
				}
				else{
					Gazelle* gazelle = listAnimaux[pos];

				}
			}
			if(pos == nbPion){
				cout << "Erreur ! Vous n'avez pas de gazelle dans votre liste de pion" << endl;
			}
		}
		// Zebre
		else if(id_animal == 2){

		}
		// Lion
		else if(id_animal == 3){

		}
		// Elephant
		else if(id_animal == 4){

		}
		// Crocodile
		else if(id_animal == 5){

		}
		else{
			cout << "Probleme dans la fonction selectAnimal dans Joueur.cpp : l'id de l'animal choisi renvoy� par la fonction selectionnerAnimal n'est pas connu" << endl;
		}
	}
}
*/
