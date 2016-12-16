#include <iostream>
#include <string>
#include "gestionnaire.h"
#include "saisieSecurisee.h"


int main(int argc, const char **argv)
{
	setlocale(LC_ALL, "fr-FR");
	
	gestionnaire jeu;

	/******C0*******/
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
	//texte Le Throne D'En Faire
	sf::Text txtTitre("Le Throne D'En Faire", font, 70);
	txtTitre.setFillColor(sf::Color::Black);
	txtTitre.setPosition(sf::Vector2f(70, 200));

	//jeu.init();

	sf::VideoMode mode(800, 600, 32);
	sf::RenderWindow* screens[2];
	screens[0] = new sf::RenderWindow(mode, "Contrôle");
	screens[1] = new sf::RenderWindow(mode, "Projecteur");

	sf::Image* normal = new sf::Image;
	normal->create(10, 10, sf::Color(0, 0, 0, 255));
	sf::Texture* temp = new sf::Texture;
	sf::Sprite* temp2 = new sf::Sprite;
	temp->loadFromImage(*normal);
	temp2->setTexture(*temp);
	screens[0]->draw(*temp2);

	while (screens[0]->isOpen()) {						// Is the window still opened?
		sf::Event event;								// We create an event

		while (screens[0]->pollEvent(event)) {			// We fill the event from the window
			cout << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << endl;
			cout << butJouer.getPosition().x << " " << butJouer.getPosition().y << endl;
			switch (event.type)
			{
			case sf::Event::Closed :
				screens[0]->close();
				break;
			case sf::Event::MouseButtonPressed :
				if ((sf::Mouse::getPosition().x > butJouer.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butJouer.getGlobalBounds().left + butJouer.getGlobalBounds().width))) 
					if ((sf::Mouse::getPosition().y > butJouer.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butJouer.getGlobalBounds().top + butJouer.getGlobalBounds().height)))
					{
						//jeu.play(screens);
						cout << "allo allo" << endl;
					}
				if ((sf::Mouse::getPosition().x > butDemo.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butDemo.getGlobalBounds().left + butDemo.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butDemo.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butDemo.getGlobalBounds().top + butDemo.getGlobalBounds().height)))
					{
						jeu.play(screens);
						cout << "allo allo" << endl;
					}
				if ((sf::Mouse::getPosition().x > butInfo.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butInfo.getGlobalBounds().left + butInfo.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butInfo.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butInfo.getGlobalBounds().top + butInfo.getGlobalBounds().height)))
					{
						//jeu.play(screens);
						cout << "allo allo" << endl;
					}
				if ((sf::Mouse::getPosition().x > butQuitter.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butQuitter.getGlobalBounds().left + butQuitter.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butQuitter.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butQuitter.getGlobalBounds().top + butQuitter.getGlobalBounds().height)))
					{
						//jeu.play(screens);
						cout << "allo allo" << endl;
					}
					break;
			}
		}

		screens[0]->clear(sf::Color::White);							// This line clear the screen
		screens[1]->clear(sf::Color::White);

		screens[0]->draw(butJouer);
		screens[0]->draw(butDemo);
		screens[0]->draw(butInfo);
		screens[0]->draw(butQuitter);

		screens[0]->draw(txtJouer);
		screens[0]->draw(txtDemo);
		screens[0]->draw(txtInfo);
		screens[0]->draw(txtQuitter);
		screens[1]->draw(txtTitre);

		screens[0]->display();							// And we display the window
		screens[1]->display();
		
	}

	return 0;
}








