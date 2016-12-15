#include <iostream>
#include <string>
#include "gestionnaire.h"
#include "saisieSecurisee.h"



int main(int argc, const char **argv)
{
	setlocale(LC_ALL, "fr-FR");
	
	gestionnaire jeu;

	sf::VideoMode mode(800, 600, 32);
	sf::RenderWindow windowC(mode, "Control");

	sf::RenderWindow windowP(mode, "Projection");

	//C0
	//button jouer
	sf::RectangleShape butJouer(sf::Vector2f(150, 100));
	butJouer.setFillColor(sf::Color(50, 125, 200));
	butJouer.setPosition(sf::Vector2f(325, 25));

	//button démo
	sf::RectangleShape butDemo(sf::Vector2f(150, 100));
	butDemo.setFillColor(sf::Color(50, 125, 200));
	butDemo.setPosition(sf::Vector2f(325, 175));

	//button info
	sf::RectangleShape butInfo(sf::Vector2f(150, 100));
	butInfo.setFillColor(sf::Color(50, 125, 200));
	butInfo.setPosition(sf::Vector2f(325, 325));

	//button quitter
	sf::RectangleShape butQuitter(sf::Vector2f(150, 100));
	butQuitter.setFillColor(sf::Color(50, 125, 200));
	butQuitter.setPosition(sf::Vector2f(325, 475));

	//load font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	// texte jouer
	sf::Text txtJouer("Jouer", font, 50);
	txtJouer.setFillColor(sf::Color::Black);
	txtJouer.setPosition(sf::Vector2f(325, 25));
	// texte démo
	sf::Text txtDemo("Démo", font, 50);
	txtDemo.setFillColor(sf::Color::Black);
	txtDemo.setPosition(sf::Vector2f(325, 175));
	// texte info
	sf::Text txtInfo("Info", font, 50);
	txtInfo.setFillColor(sf::Color::Black);
	txtInfo.setPosition(sf::Vector2f(325, 325));
	// texte quitter
	sf::Text txtQuitter("Quitter", font, 50);
	txtQuitter.setFillColor(sf::Color::Black);
	txtQuitter.setPosition(sf::Vector2f(325, 475));

	//jeu.init();		//initialise le decks

	while (windowC.isOpen()) {                 // Is the window still opened?
		sf::Event event;                        // We create an event
		while (windowC.pollEvent(event)) {       // We fill the event from the window
			if (event.type == sf::Event::Closed)  // If the event is close window
				windowC.close();                     // We close it ;)


			/*if (event.type == sf::Event::MouseButtonPressed)
			{
				jeu.demo();

			}*/

		}



		windowC.clear(sf::Color::White);			// Clear control
		windowP.clear(sf::Color::White);			// Clear projection

		windowC.draw(butJouer);
		windowC.draw(butDemo);
		windowC.draw(butInfo);
		windowC.draw(butQuitter);

		windowC.draw(txtJouer);
		windowC.draw(txtDemo);
		windowC.draw(txtInfo);
		windowC.draw(txtQuitter);

		windowC.display();                      // display control
		windowP.display();						// display projection
	}

	return 0;
}








