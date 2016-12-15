#include <iostream>
#include <string>
#include "question.h"
#include "deck.h"
#include "saisieSecurisee.h"



void main()
{

	setlocale(LC_ALL, "fr-FR");
	//déclarations
	string nomFichier;			//le nom du fichier
	deck questions;
	question quest;
	string reponses[4];

	nomFichier = saisirStringNonVide("Veuillez entrer le nom du fichier dans lequel se trouve le deck.");
	nomFichier = "\questions\\" + nomFichier + ".deck";


	questions.init(nomFichier);
	questions.melanger();
	quest = questions.tirer();

	cout << quest.getQuestion()<<endl;
	quest.getCarre(reponses);
	cout << reponses[0] << endl
		<< reponses[1] << endl
		<< reponses[2] << endl
		<< reponses[3] <<endl<<endl;



	pause("Tout est OK!");
}








