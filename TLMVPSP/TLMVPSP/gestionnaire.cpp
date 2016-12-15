#include "gestionnaire.h"
#include "button.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

gestionnaire::gestionnaire()
{
	_actuelle = 0;
}


gestionnaire::~gestionnaire()
{
}


// Initialisation
void gestionnaire::init()
{
	setlocale(LC_ALL, "fr-FR");
	//déclarations
	string nomFichier;			//le nom du fichier
	question quest;
	string reponses[4];

	nomFichier = saisirStringNonVide("Veuillez entrer le nom du fichier dans lequel se trouve le premier deck.");
	nomFichier = "\questions\\" + nomFichier + ".deck";
	_deck[0].init(nomFichier);
	_deck[0].melanger();

	nomFichier = saisirStringNonVide("Veuillez entrer le nom du fichier dans lequel se trouve le second deck.");
	nomFichier = "\questions\\" + nomFichier + ".deck";
	_deck[1].init(nomFichier);
	_deck[1].melanger();	
	
	nomFichier = saisirStringNonVide("Veuillez entrer le nom du fichier dans lequel se trouve le troisième deck.");
	nomFichier = "\questions\\" + nomFichier + ".deck";
	_deck[2].init(nomFichier);
	_deck[2].melanger();

}



// lance une partie
void gestionnaire::play(sf::RenderWindow* screen[2])

{

	sf::Image* blank = new sf::Image;
	blank->create(50, 50, sf::Color(255, 255, 255));
	sf::Image* grey = new sf::Image;
	grey->create(50, 50, sf::Color(255, 255, 255));

	sf::String text = "T";

	sf::Vector2f place;
	place.x = 128;
	place.y = 128;

	Button b(blank,grey,text,place);
	std::cout << "bHJHJKBJ";
	screen[0]->draw(*b.getSprite());

	for (_actuelle = 0; _actuelle < 3; ++_actuelle)
	{
		_manche[_actuelle] = manche(_actuelle);


	}

}


// Joue la démo, 0: contrôle 1: projecteur
void gestionnaire::demo(sf::RenderWindow* screen[2])
{
}
