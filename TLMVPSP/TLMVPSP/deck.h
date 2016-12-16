/* En-t�te du programme
====================
Programme :			deck.h
Auteur:				Guillaume Bergs
Date de derni�re modification :  2016/12/15
Description :		g�re la pile de question, permet de la m�langer et d'en donner une
To Do :				am�liorer le m�lange
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
	// M�lange le deck pour placer chaque question dedans dans un ordre al�atoire
	void melanger();
	// Tire la premi�re question du top du deck
	question tirer();
	// Initialise le deck � partir du fichier dont le nom est pass� en param�tre
	void init(std::string s);
};

