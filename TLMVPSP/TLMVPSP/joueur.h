/* En-tête du programme
====================
Programme :	joueur.h
Auteur:	Christopher Brown
Date dernière modification :  2016/12/15
Description :	Classe joueur qui permet d'avoir des informations sur le joueur comme son nom, le nombre de bonnes réponses...
To Do :
*/

#pragma once
#include <string>

class joueur
{
private:
	std::string _nom;
	int _points;
	int _nbDuo;
	int _nbCarre;
	int _nbCash;
	int _nbReponses;
	int _nbBonnesReponses;

public:
	joueur();
	~joueur();

	void clear();					// Efface les données du joueur
	
	void setNom(std::string s);			// Identifier le nom du joueur
	std::string getNom()const;			// Retourne le nom du joueur

	int getPoints()const;			// Retourne le nombre de points du joueur
	void addPoints(int p);			// Ajouter des points au joueur
	void subPoints(int p);			// Enlever des points du joueur
	
	int getnbDuo()const;			// Retourne le nb de réponse duo
	void addDuo(int d);				// Ajouter des points au joueur
	void subDuo(int d);				// Enlever des points du joueur

	int getnbCarre()const;			// Retourne le nb de réponse carre
	void addCarre(int cr);			// Ajouter des points au joueur
	void subCarre(int cr);			// Enlever des points du joueur

	int getnbCash()const;			// Retourne le nb de réponse cash
	void addCash(int cs);			// Ajouter des points au joueur
	void subCash(int cs);			// Enlever des points du joueur

	int getNbReponses()const;				// Retourne le nb de réponse du joueur
	void addNbReponses(int r);				// Ajouter au nb de réponse au joueur
	void subNbReponses(int r);				// Enlever au nb de réponse du joueur

	int getNbBonnesReponses()const;			// Retourne le nb de bonne réponse du joueur
	void addNbBonnesReponses(int br);		// Ajouter au nb de bonne réponse au joueur
	void subNbBonnesReponses(int br);		// Enlever au nb de bonne réponse du joueur

	double getRatioBonnesReponses()const;		// Retourne le ratio de bonne réponse sur le nb de réponse du joueur
	double getRatioCash()const;					// Retourne le nb de réponses cash sur le nb de réponses du joueur
	double getRatioCarre()const;				// Retourne le ratio du nb de réponses carre sur le nb de réponses du joueur
	double getRatioDuo()const;					// Retourne le ratio du nb de réponses duo sur le nb de réponses du joueur
	double getRatioPtsParReponse()const;		// Ratio du nb de point obtenu par question

};

