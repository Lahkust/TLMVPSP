/* En-tête du programme
====================
Programme :			deck.h
Auteur:				Guillaume Bergs
Date de dernière modification :  2016/12/15
Description :		gère la pile de question, permet de la mélanger et d'en donner une
To Do :				améliorer le mélange
*/
#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "question.h"
#include "saisieSecurisee.h"
class deck
{
private:
	std::stack<question> _questions;
	std::string _nom;
public:
	deck();
	~deck();
	// Mélange le deck pour placer chaque question dedans dans un ordre aléatoire
	void melanger();
	// Tire la première question du top du deck
	question tirer();
	// Initialise le deck à partir du fichier dont le nom est passé en paramètre
	void init(std::string s);
};

