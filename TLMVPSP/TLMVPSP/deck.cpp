#include "deck.h"


deck::deck()
{
}


deck::~deck()
{
}


// Mélange le deck pour placer chaque question dedans dans un ordre aléatoire
void deck::melanger()
{
	//Un nombre aléatoire de fois

	//Dépiler dans un nombre aléatoire de piles

	//Puis rempiler
}


// Tire la première question du top du deck
question deck::tirer()
{
	question r = _questions.top;
	_questions.pop;
	return r;
}


// Initialise le deck à partir du fichier dont le nom est passé en paramètre
void deck::init(std::string s)
{
}
