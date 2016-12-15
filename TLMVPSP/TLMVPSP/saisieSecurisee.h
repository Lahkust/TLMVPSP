/* En-t�te du programme
====================
Programme :			SaisieSecurisee.h
Auteur:				Guillaume Bergs
Date de cr�ation :  2016/02/12
Description :		Cette librairie permet d'interagir de mani�re s�curis�e avec un utilisateur
To Do :				RAS
*/
#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//D�claration de fonctions
int saisirInt(string = "");
int saisirIntPositif(string = "");
float saisirFloat(string = "");
float saisirFloatPositif(string = "");
char saisirCharValide(string = "");
string saisirStringNonVide(string = "");
char questionOuiNon(string = "");
void viderBuffer();
void pause(string = "");
void enter(string = "");
void ouvrirFichier(ifstream &fichier, string);
bool siFichierVide(string = "");
bool testFichierExiste(const std::string& nomFichier);
bool testFichierVide(const std::string& nomFichier);
