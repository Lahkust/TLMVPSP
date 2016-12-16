/* En-tête du programme
====================
Programme :	manche.h
Auteur:	Christopher Brown
Date dernière modification :  2016/12/15
Description :	Classe manche qui permet au gestionnaire de jouer selon la manche.
To Do :
*/

#pragma once
#include "joueur.h"
#include "list.h"
#include "question.h"
#include <SFML\Graphics.hpp>

class manche
{
private:
	list<joueur> _joueur;
	list<joueur>::iterator _it;

public:
	manche();
	~manche();

	manche(int m);						// Manche à initialiser 
	manche(int m, list<joueur> j);		// Manche à initialiser avec une liste de joueurs
	
	double getRatioGroupCash();			// Retourne la moyenne des ratio cash des joueurs
	double getRatioGroupCarre();		// Retourne la moyenne des ratio carre des joueurs
	double getRatioGroupDuo();			// Retourne la moyenne des ratio duo des joueurs

	list<joueur> bonsJoueurs(int i);			// Garder les meilleurs joueurs pour la prochaine ronde
	void poserQuestion(int i, question q);		// Question qui va être poser au joueur

};

