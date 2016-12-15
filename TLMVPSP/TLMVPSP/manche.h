#pragma once
#include "joueur.h"
#include "list.h"
#include "question.h"

class manche
{
private:
	list<joueur> _joueur;
	list<joueur>::iterator it;

public:
	manche();
	~manche();

	manche(int m);						// Manche initialiser 
	manche(int m, list<joueur> j);		// Manche initialiser avec une liste de joueurs
	
	double getRatioGroupCash();			// Retourne la moyenne des ratio cash des joueurs
	double getRatioGroupCarre();		// Retourne la moyenne des ratio carre des joueurs
	double getRatioGroupDuo();			// Retourne la moyenne des ratio duo des joueurs

	list<joueur> bonsJoueurs(int i);			// 
	void poserQuestion(int i, question q);		// Question qui va être poser au joueur

};

