#pragma once
#include <stack>
#include <string>
#include "question.h"

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

