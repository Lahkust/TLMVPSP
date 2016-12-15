#include <iostream>
#include <string>
#include "gestionnaire.h"
#include "saisieSecurisee.h"


int main(int argc, const char **argv)
{
	setlocale(LC_ALL, "fr-FR");
	
	gestionnaire jeu;

	jeu.init();

	sf::VideoMode mode(1080, 720, 32);
	sf::RenderWindow* screens[2];
	screens[0] = new sf::RenderWindow(mode, "Contrôle");
	screens[1] = new sf::RenderWindow(mode, "Projecteur");

	while (screens[0]->isOpen()) {						// Is the window still opened?
		sf::Event event;								// We create an event
		while (screens[0]->pollEvent(event)) {			// We fill the event from the window
			if (event.type == sf::Event::Closed)		// If the event is close window
				screens[0]->close();					// We close it ;)
		}

		screens[0]->clear();							// This line clear the screen
		screens[0]->display();							// And we display the window
		screens[1]->clear();
		screens[1]->display();


		jeu.play(screens);


	}

	pause("Tout est OK!");
	return 0;
}








