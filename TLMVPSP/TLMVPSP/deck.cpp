#include "deck.h"


deck::deck()
{
}


deck::~deck()
{
}


// M�lange le deck pour placer chaque question dedans dans un ordre al�atoire
void deck::melanger()
{
	//Un nombre al�atoire de fois

	//D�piler dans un nombre al�atoire de piles

	//Puis rempiler
}


// Tire la premi�re question du top du deck
question deck::tirer()
{
	question r = _questions.top;
	_questions.pop;
	return r;
}


// Initialise le deck � partir du fichier dont le nom est pass� en param�tre
void deck::init(std::string s)
{
}
