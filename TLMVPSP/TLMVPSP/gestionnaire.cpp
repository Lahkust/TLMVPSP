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
void gestionnaire::play()

{
	sf::VideoMode mode(1080, 720,32);
	sf::RenderWindow window(mode,"foobar");
	//sf::RenderWindow window;

	sf::RenderWindow window2(mode, "foobar");

	while (window.isOpen()) {						// Is the window still opened?
		sf::Event event;							// We create an event
		while (window.pollEvent(event)) {			// We fill the event from the window
			if (event.type == sf::Event::Closed)	// If the event is close window
				window.close();                     // We close it ;)
		}

		window.clear();								// This line clear the screen
		window.display();							// And we display the window
		window2.clear();
		window2.display();





	}




	for (_actuelle = 0; _actuelle < 3; ++_actuelle)
	{
		_manche[_actuelle] = manche(_actuelle);


	}

}
