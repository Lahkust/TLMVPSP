#include <iostream>
#include <string>
#include "gestionnaire.h"
#include "saisieSecurisee.h"



int main(int argc, const char **argv)
{
	setlocale(LC_ALL, "fr-FR");
	
	gestionnaire jeu;

	jeu.init();
	jeu.play();

	pause("Tout est OK!");
	return 0;
}








