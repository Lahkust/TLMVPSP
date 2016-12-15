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

}


manche::manche(int m, list<joueur> j)
{

}


// Retourne la moyenne des ratio cash des joueurs
double manche::getRatioGroupCash()
{
	double moyenne;
	for (it = _joueur.begin(); it != _joueur.end(); it++)
	{
		//moyenne += _joueur. getRatioCash();
	}
	return 0.0;
}


// Retourne la moyenne des ratio carre des joueurs
double manche::getRatioGroupCarre()
{
	return 0.0;
}


// Retourne la moyenne des ratio duo des joueurs
double manche::getRatioGroupDuo()
{
	return 0.0;
}


list<joueur> manche::bonsJoueurs(int i)
{
	return _joueur;
}


void manche::poserQuestion(int i, question q)
{

}
