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
	// Mélange le deck pour placer chaque question dedans dans un ordre aléatoire
	void melanger();
	// Tire la première question du top du deck
	question tirer();
	// Initialise le deck à partir du fichier dont le nom est passé en paramètre
	void init(std::string s);
};

