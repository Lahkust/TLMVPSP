#include "joueur.h"



joueur::joueur()
{
	_points = 0;
	_nbDuo = 0;
	_nbCarre = 0;
	_nbCash = 0;
	_nbReponses = 0;
	_nbBonnesReponses = 0;
}


joueur::~joueur()
{
	clear();
}


// Efface les données du joueur
void joueur::clear()
{
	_points = 0;
	_nbDuo = 0;
	_nbCarre = 0;
	_nbCash = 0;
	_nbReponses = 0;
	_nbBonnesReponses = 0;
}


// Identifier le nom du joueur
void joueur::setNom(std::string s)
{
	_nom = s;
}


// Retourne le nom du joueur
std::string joueur::getNom()const
{
	return _nom;
}

// Retourne le nombre de points du joueur
int joueur::getPoints()const
{
	return _points;
}

//Ajouter des points au joueur
void joueur::addPoints(int p)
{
	_points += p;
}


// Enlever des points du joueur
void joueur::subPoints(int p)
{
	_points -= p;
}


// Retourne le nb de réponse duo
int joueur::getnbDuo()const
{
	return _nbDuo;
}


// Ajouter des points au joueur
void joueur::addDuo(int d)
{
	_nbDuo += d;
}


// Enlever des points du joueur
void joueur::subDuo(int d)
{
	_nbDuo -= d;
}


// Retourne le nb de réponse carre
int joueur::getnbCarre()const
{
	return _nbCarre;
}


// Ajouter des points au joueur
void joueur::addCarre(int cr)
{
	_nbCarre += cr;
}


// Enlever des points du joueur
void joueur::subCarre(int cr)
{
	_nbCarre -= cr;
}


// Retourne le nb de réponse cash
int joueur::getnbCash()const
{
	return _nbCash;
}


// Ajouter des points au joueur
void joueur::addCash(int cs)
{
	_nbCash += cs;
}


// Enlever des points du joueur
void joueur::subCash(int cs)
{
	_nbCash -= cs;
}


// Retourne le nb de réponse du joueur
int joueur::getNbReponses()const
{
	return _nbReponses;
}


// Ajouter au nb de réponse au joueur
void joueur::addNbReponses(int r)
{
	_nbReponses += r;
}


// Enlever au nb de réponse du joueur
void joueur::subNbReponses(int r)
{
	_nbReponses -= r;
}


// Retourne le nb de bonne réponse du joueur
int joueur::getNbBonnesReponses()const
{
	return _nbBonnesReponses;
}


// Ajouter au nb de bonne réponse au joueur
void joueur::addNbBonnesReponses(int br)
{
	_nbBonnesReponses += br;
}


// Enlever au nb de bonne réponse du joueur
void joueur::subNbBonnesReponses(int br)
{
	_nbBonnesReponses -= br;
}


// Retourne le ratio de bonne réponse sur le nb de réponse du joueur
double joueur::getRatioBonnesReponses()const
{
	return 100 * (_nbBonnesReponses/_nbReponses);
}


// Retourne le nb de réponses cash sur le nb de réponses du joueur
double joueur::getRatioCash()const
{
	return 100 * (_nbCash / _nbReponses);
}


// Retourne le ratio du nb de réponses carre sur le nb de réponses du joueur
double joueur::getRatioCarre()const
{
	return 100 * (_nbCarre / _nbReponses);
}


// Retourne le ratio du nb de réponses duo sur le nb de réponses du joueur
double joueur::getRatioDuo()const
{
	return 100 * (_nbDuo / _nbReponses);
}


// Ratio du nb de point obtenu par question
double joueur::getRatioPtsParReponse()const
{
	return 100 * (_points / _nbReponses);
}
		