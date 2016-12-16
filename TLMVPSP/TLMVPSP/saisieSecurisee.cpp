/* En-tête du programme
====================
Programme :			SaisieSecurisee.cpp
Auteur:				Guillaume Bergs
Date de création :  2016/02/12
Description :		Cette librairie permet d'interagir de manière sécurisée avec un utilisateur
To Do :				RAS
*/


/* Directives du préprocesseur
===============================*/
#include <fstream>
#include <iostream>
#include "saisieSecurisee.h"

using namespace std;


//
int saisirInt(string demande)
{
	int valide = 0;
	string input;
	bool flag = true;
	
	do{
		flag = false;
		// demande << endl << "(Nombre entier)" << endl;
		viderBuffer();
		cin >> input;
		//Vérifie que le premier caractère est un - ou un chiffre:
		if (!((input[0] == '-') || ((input[0] >= '0')&&(input[0] <= '9')))){ flag = true; }
		//Pour chaque autre caractère, vérifie que c'est un chiffre:
		for (char &c : input.substr(1,input.length())) { flag += !isdigit(c); }
		}while (flag);
	
	//convertit l'entree (string) en int
	valide = stoi(input);
	return valide;
}


//
int saisirIntPositif(string demande )
{
	int valide = 0;
	string input;
	bool flag = true;
	do{do{
		flag = false;
		// demande << endl << "(Nombre entier positif)" << endl;
		viderBuffer();
		cin >> input;
		//Pour chaque caractère, vérifie que c'est un chiffre:
		for (char &c : input) { flag += !isdigit(c); }
	} while (flag);}while(stoi(input)==0);

	//convertit l'entree (string) en int
	valide = stoi(input);
	return valide;
}

float saisirFloat(string demande )
{
	float valide = 0;
	string input;
	bool flag = true;
	int nbPoints = 0;
	do{
		nbPoints = 0;
		flag = false;
		// demande << endl << "(Nombre reel)" << endl;
		viderBuffer();
		cin >> input;
		//Vérifie que le premier caractère est un - ou un chiffre:
		if (!((input[0] == '-') || ((input[0] >= '0') && (input[0] <= '9')))){ flag = true; }
		//Pour chaque autre caractère, vérifie que c'est un chiffre ou UN point:
		for (char &c : input.substr(1,input.length())) {
			if ((!isdigit(c)) && (c != '.')){ flag = true; }
			if (c == '.'){ nbPoints++; }
		}
	} while ((flag) || (nbPoints>1));
	//convertit l'entree (string) en float
	valide = stof(input);
	return valide;

}

float saisirFloatPositif(string demande )
{
	float valide = 0;
	string input;
	bool flag = true;
	int nbPoints = 0;
	do{do{
		nbPoints = 0;
		flag = false;
		// demande << endl << "(Nombre reel positif)" << endl;
		viderBuffer();
		cin >> input;
		//Pour chaque caractère, vérifie que c'est un chiffre ou UN point:
		for (char &c : input) {
			if ((!isdigit(c)) && (c != '.')){ flag = true; }
			if (c == '.'){ nbPoints++; }
		}
	} while ((flag) || (nbPoints>1));}while(stof(input)==0);
	//convertit l'entree (string) en float
	valide = stof(input);
	return valide;

}

char saisirCharValide(string demande )
{
	string valide = "";
	do{
		// demande << endl;
		viderBuffer();
		cin >> valide;
	} while (valide.length() != 1);
	return valide[0];
}

string saisirStringNonVide(string demande )
{
	string nonVide ;
	do{
		// demande << endl;
		viderBuffer();
		cin >> nonVide;
	} while (nonVide.empty());
	return nonVide;
}

char questionOuiNon(string demande )
{
	char continuer;
	do
	{
		//Afficher demande
		// demande << " (o/n)" << endl;
		//Entrer réponse
		viderBuffer();
		cin >> continuer;
		continuer = toupper(continuer);

	} while (!((continuer == 'O') || (continuer == 'N')));
	return continuer;
}

void viderBuffer()
{
	cin.clear();
	cin.seekg(0, ios::end);
	if (!cin.fail())//Le flux est valide, donc le buffer est non vide
		cin.ignore(numeric_limits<streamsize>::max());
	else//Le flux est invalide, donc le buffer est vide
		cin.clear(); // Le flux est dans un état invalide donc on le remet en état valide
}

//vide le buffer et fait un ignore d’un buffer vide, donc fait une pause
void pause(string demande)
{ 
	// demande << endl;
	viderBuffer();
	cin.ignore();
}

void enter(string demande)
{
	do{
		// demande << endl;
		viderBuffer();
	} while (cin.get() != '\n');
}

void ouvrirFichier(ifstream &fichier, string cheminFichier)
{
  fichier.open(cheminFichier);
  if (fichier.fail())
  {
    // "Fichier introuvable";
  }
}

bool siFichierVide(string nomFichier )
{
	bool sortie = false; //variable de sortie
	ifstream fichier(nomFichier); //ouvrir le fichier
	fichier.seekg(0, fichier.end); //aller a la fin
	if (fichier.tellg() > 0) sortie = true; // si le nb de caractères est superieur a zero, retourner vrai
	fichier.close(); //fermer le fichier
	return sortie;
}
bool testFichierExiste(const std::string& nomFichier)
{
	ifstream fichier(nomFichier);
	if (fichier.good()) { fichier.close(); return true; }
	else { fichier.close(); return false; }
}

bool testFichierVide(const std::string& nomFichier)
{
	bool sortie = false;					//variable de sortie
	ifstream fichier(nomFichier);			//ouvrir le fichier
	fichier.seekg(0, fichier.end);			//aller a la fin
	if (fichier.tellg() > 0) sortie = true; // si le nb de caractères est superieur a zero, retourner vrai
	fichier.close();						//fermer le fichier
	return sortie;
}