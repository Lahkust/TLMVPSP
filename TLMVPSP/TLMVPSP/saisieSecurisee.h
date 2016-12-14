/* En-tête du programme
====================
Programme :			SaisieSecurisee.h
Auteur:				Guillaume Bergs
Date de création :  2016/02/12
Description :		Cette librairie permet d'interagir de manière sécurisée avec un utilisateur
To Do :				RAS
*/
#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Déclaration de fonctions
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
