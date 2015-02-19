/*
 * Joueur.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <iostream>
#include <string>
#include <vector>

#include "Pion/Animal.h"

class Affichage;
class ImpalaJones;
class Plateau;
class Partie;
class Gazelle;

using namespace std;

/**
 * Classe abstraite, car contient une méthode virtuelle pure (=0) pour ne pas l'instancier.
 */

class Animal;

static int idStatic = 1;

class Joueur {
private:
	int nbPoints;
	string nom;
	vector<Animal*> listAnimaux;
	int id;

	/**
	 * Permet d'initialiser tous les pions d'un joueur
	 * 6 gazelles
	 * 5 zebres
	 * 1 elephant
	 * 1 lion
	 * 2 crocos
	 */
	void initListPions(int nbGazelles = 6, int nbZebres = 5, int nbElephants = 1, int nbLions = 1,
			int nbCrocos = 2);

public:
	/* FIXME : J'aurai aimé ne pas mettre "=1" à id_j car je veux qu'il soit obligatoire. Problème : si j'enlève le =1, il m'envoi une erreur car cet argument n'a pas de valeur par défaut */
	/* DONE j'ai ajouté un idStatic qui s'incrémenta a chaque fois comme ça leidJoueur est forcément unique */
	Joueur(int nbPoints = 0, string nom = "", int nbGazelles = 6, int nbZebres = 5,
			int nbElephants = 1, int nbLions = 1, int nbCrocos = 2) :
			nbPoints(nbPoints), nom(nom), listAnimaux(0), id(idStatic){
		initListPions(nbGazelles, nbZebres, nbElephants, nbLions, nbCrocos);
		idStatic++;
	}

	virtual ~Joueur(){};

	int getNbPoints() const{
		return nbPoints;
	}

	const string& getNom() const{
		return nom;
	}

	void setNbPoints(int nbPoints){
		this->nbPoints = nbPoints;
	}

	friend ostream& operator<<(ostream &strm, const Joueur &a){
		strm << "Joueur(" << a.nom << ", " << a.id << ") : " << a.nbPoints << "." << endl;
		return strm;
	}

	/**
	 * Ajoute l'animal sur la case x/y
	 * 1 = gazelle,
	 * 2 = zebre
	 * 3 = elephant
	 * 4 = lion
	 * 5 = croco
	 * renvoie vrai si l'ajout a ete fait.
	 */
	virtual bool jouer(Plateau* plateau, Affichage * affiche) = 0;

	virtual bool jouerCase(int xPion, int yPion, Plateau* plateau, Affichage * affiche) = 0;

	virtual int jouerTour(Plateau* p, Affichage* affichage, Partie partie) = 0;

	vector<Animal*>& getListAnimaux(){
		return listAnimaux;
	}

	void setListAnimaux(const vector<Animal*>& listAnimaux){
		this->listAnimaux = listAnimaux;
	}

	Animal* getAnimal(const int i){
		return listAnimaux[i];
	}

	void setNom(const string& nom){
		this->nom = nom;
	}

	int getId() const{
		return id;
	}

	friend bool operator==(const Joueur& j1, const Joueur& j2){
		return j1.getId() == j1.getId();
	}

	/**
	 *  Ajoute le nombre de points passé en parametre
	 */
	void ajouterPoints(int nb);

	virtual int deplacementImpalaJones(Plateau p, ImpalaJones ij, Affichage *affichage) = 0;
	virtual void joueurInitImpala(Plateau *p, Affichage *affichage) = 0;
	virtual int choixActionCrocodile(vector<Gazelle*> voisin, Plateau p, Affichage *affichage) = 0;
};

#endif /* JOUEUR_H_ */
