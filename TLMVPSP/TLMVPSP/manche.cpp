#include "manche.h"



manche::manche()
{
	
}


manche::~manche()
{
	_joueur.clear();
}


manche::manche(int m)
{
	_it = _joueur.begin();
	switch (m)
	{
		case 0: while (_it != _joueur.end())
		{
			//while (question < 2)
			//{

			//	Afficher C3, P1
			sf::RectangleShape butJouer(sf::Vector2f(150, 100));
			butJouer.setFillColor(sf::Color(50, 125, 200));
			butJouer.setPosition(sf::Vector2f(500, 50));




			//	Afficher C4, P2
			//	Afficher C5, P3 / 6 / none
			//	Afficher C6, P4 / 6 / 7

			//}
		}
		case 1 : while (_it != _joueur.end())
		{

			//	Afficher C7, P9
			//	Afficher P10 / 2
			//	Afficher none / 11

		}
		case 2 : while (_it != _joueur.end())
		{
			//while (question < 5)
			//{

			//	Afficher C3, P1
			//	Afficher C4, P2
			//	Afficher C5, P3 / 6 / none
			//	Afficher C6, P4 / 6 / 7

			//}
		}
	}
}


manche::manche(int m, list<joueur> j)
{

}


// Retourne la moyenne des ratio cash des joueurs
double manche::getRatioGroupCash()
{
	double moyenne = 0.0;
	int i = 0;
	for (_it = _joueur.begin(); _it != _joueur.end(); _it++)
	{
		moyenne += _it.operator*().getRatioCash();
		i++;
	}
	return moyenne / i;
}


// Retourne la moyenne des ratio carre des joueurs
double manche::getRatioGroupCarre()
{
	double moyenne = 0.0;
	int i = 0;
	for (_it = _joueur.begin(); _it != _joueur.end(); _it++)
	{
		moyenne += _it.operator*().getRatioCarre();
		i++;
	}
	return moyenne / i;
}


// Retourne la moyenne des ratio duo des joueurs
double manche::getRatioGroupDuo()
{
	double moyenne = 0.0;
	int i = 0;
	for (_it = _joueur.begin(); _it != _joueur.end(); _it++)
	{
		moyenne += _it.operator*().getRatioDuo();
		i++;
	}
	return moyenne / i;
}


list<joueur> manche::bonsJoueurs(int i)
{
	return _joueur;
}


void manche::poserQuestion(int i, question q)
{

}
