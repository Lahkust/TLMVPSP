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
	//Les piles de questions temporaires
	std::stack<question> temp[5];

	//Initialiser le random stuff
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<uint32_t> rn(1, 5);
	int nombreAleatoire = rn(mt);

	//Un nombre aléatoire de fois

	for (auto i = 0; i < nombreAleatoire; ++i)
	{
		//Dépiler dans un nombre aléatoire de piles
		nombreAleatoire = rn(mt);
		while(_questions.size() !=0)
			for (auto i = 0; i < nombreAleatoire; ++i)
				temp[i].push(tirer());
		
		//Puis rempiler
		for (auto i = 0;
			!(	(temp[0].size() == 0) && 
				(temp[1].size() == 0) && 
				(temp[2].size() == 0) && 
				(temp[3].size() == 0) && 
				(temp[4].size() == 0)
			);
			++i) {
			if (i > nombreAleatoire) i = 0;
			if (temp[i].size() > 0)
			{
				_questions.push(temp[i].top());
				temp[i].pop();
			}
		}
	}

}


// Tire la première question du top du deck
question deck::tirer()
{
	question r = _questions.top();
	_questions.pop();
	return r;
}


// Initialise le deck à partir du fichier dont le nom est passé en paramètre
void deck::init(std::string s)
{
}
