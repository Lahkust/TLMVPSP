#include "gestionnaire.h"



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
	demo(screen);
	////C0
	////button jouer
	//sf::RectangleShape butHist(sf::Vector2f(150, 100));
	//butHist.setFillColor(sf::Color(50, 125, 200));
	//butHist.setPosition(sf::Vector2f(500, 50));

	////button démo
	//sf::RectangleShape butGeo(sf::Vector2f(150, 100));
	//butGeo.setFillColor(sf::Color(50, 125, 200));
	//butGeo.setPosition(sf::Vector2f(500, 200));

	////button info
	//sf::RectangleShape butDL(sf::Vector2f(150, 100));
	//butDL.setFillColor(sf::Color(50, 125, 200));
	//butDL.setPosition(sf::Vector2f(500, 350));

	////button quitter
	//sf::RectangleShape butDR(sf::Vector2f(150, 100));
	//butDR.setFillColor(sf::Color(50, 125, 200));
	//butDR.setPosition(sf::Vector2f(500, 500));

	////load font
	//sf::Font font;
	//if (!font.loadFromFile("arial.ttf"))
	//{
	//	// error...
	//}

	//// texte jouer
	//sf::Text txtHist("Jouer", font, 50);
	//txtHist.setFillColor(sf::Color::Black);
	//txtHist.setPosition(sf::Vector2f(500, 50));
	//// texte démo
	//sf::Text txtGeo("Démo", font, 50);
	//txtGeo.setFillColor(sf::Color::Black);
	//txtGeo.setPosition(sf::Vector2f(500, 200));
	//// texte info
	//sf::Text txtDL("Info", font, 50);
	//txtDL.setFillColor(sf::Color::Black);
	//txtDL.setPosition(sf::Vector2f(500, 350));
	//// texte quitter
	//sf::Text txtDR("Quitter", font, 50);
	//txtDR.setFillColor(sf::Color::Black);
	//txtDR.setPosition(sf::Vector2f(500, 500));

	sf::Image* normal = new sf::Image;
	normal->create(10, 10, sf::Color(0, 0, 0, 255));
	
	sf::Image* clicked = new sf::Image;
	clicked->create(10, 10, sf::Color(0, 0, 255, 255));

	std::string words = "t";
	sf::Vector2f location;
	location.x = 10;
	location.y = 10;
	Button b(normal,clicked, words, location);
	sf::Texture* temp = new sf::Texture;
	sf::Sprite* temp2 = new sf::Sprite;
	while (screen[0]->isOpen()) 
	{                 // Is the window still opened?
		sf::Event event;                        // We create an event
		while (screen[0]->pollEvent(event)) 
		{       // We fill the event from the window
			if (event.type == sf::Event::Closed)  // If the event is close window
				screen[0]->close();                     // We close it ;)
		}



		screen[0]->clear(sf::Color::White);							// This line clear the screen

		/*window.draw(butHist);
		window.draw(butGeo);
		window.draw(butDL);
		window.draw(butDR);

		window.draw(txtHist);
		window.draw(txtGeo);
		window.draw(txtDL);
		window.draw(txtDR);*/

		screen[0]->draw(*b.getSprite());
		temp->loadFromImage(*normal);
		temp2->setTexture(*temp);
		//screen[0]->draw(*temp2);
		screen[0]->display();                       // And we display the window
	}


	/*for (_actuelle = 0; _actuelle < 3; ++_actuelle)
	{
		_manche[_actuelle] = manche(_actuelle);


	}*/

}


// Joue la démo, 0: contrôle 1: projecteur
void gestionnaire::demo(sf::RenderWindow* screen[2])
{

	///////Décision de deck


	deck _deck;
	question _question;
	bool choice = false;

	//button histoire
	sf::RectangleShape butHist(sf::Vector2f(250, 750));
	butHist.setFillColor(sf::Color(255, 150, 50));
	butHist.setPosition(sf::Vector2f(0, 25));

	//button géo
	sf::RectangleShape butGeo(sf::Vector2f(250, 750));
	butGeo.setFillColor(sf::Color(255, 50, 50));
	butGeo.setPosition(sf::Vector2f(0, 325));

	//load font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	// texte histoire
	sf::Text txtHist("Histoire", font, 50);
	txtHist.setFillColor(sf::Color::Black);
	txtHist.setPosition(sf::Vector2f(200, 125));
	// texte géo
	sf::Text txtGeo("Géographie", font, 50);
	txtGeo.setFillColor(sf::Color::Black);
	txtGeo.setPosition(sf::Vector2f(200, 425));

	while (screen[0]->isOpen() && (!choice)) {						// Is the window still opened?
		sf::Event event;								// We create an event

		while (screen[0]->pollEvent(event)) 
		{			// We fill the event from the window
			cout << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << endl;
			cout << butHist.getPosition().x << " " << butHist.getPosition().y << endl;
			switch (event.type)
			{
			case sf::Event::Closed:
				screen[0]->close();
				break;
			case sf::Event::MouseButtonPressed:
				if ((sf::Mouse::getPosition().x > butHist.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butHist.getGlobalBounds().left + butHist.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butHist.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butHist.getGlobalBounds().top + butHist.getGlobalBounds().height)))
					{
						//Histoire
						//cout << "allo allo" << endl;
						_deck.init("questions\\H.deck");
						choice = true;

					}
				if ((sf::Mouse::getPosition().x > butGeo.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butGeo.getGlobalBounds().left + butGeo.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butGeo.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butGeo.getGlobalBounds().top + butGeo.getGlobalBounds().height)))
					{
						//Géo
						//cout << "allo allo" << endl;
						_deck.init("questions\\G.deck");
						choice = true;
					}
				break;
			}
		}

		screen[0]->clear(sf::Color::White);							// This line clear the screen
		screen[1]->clear(sf::Color::White);


		screen[0]->draw(butHist);
		screen[0]->draw(butGeo);
		screen[0]->draw(txtHist);
		screen[0]->draw(txtGeo);

		screen[1]->draw(butHist);
		screen[1]->draw(butGeo);
		screen[1]->draw(txtHist);
		screen[1]->draw(txtGeo);


		screen[0]->display();							// And we display the window
		screen[1]->display();


	}


	//////// Jeu

	//button UL
	sf::RectangleShape butUL(sf::Vector2f(380, 150));
	butUL.setFillColor(sf::Color(200, 200, 200));
	butUL.setPosition(sf::Vector2f(10, 70));

	//button UR
	sf::RectangleShape butUR(sf::Vector2f(380, 150));
	butUR.setFillColor(sf::Color(200, 200, 200));
	butUR.setPosition(sf::Vector2f(410, 70));

	//button DL
	sf::RectangleShape butDL(sf::Vector2f(380, 150));
	butDL.setFillColor(sf::Color(200, 200, 200));
	butDL.setPosition(sf::Vector2f(10, 230));

	//button DR
	sf::RectangleShape butDR(sf::Vector2f(380, 150));
	butDR.setFillColor(sf::Color(200, 200, 200));
	butDR.setPosition(sf::Vector2f(410, 230));


	// texte UL
	sf::Text txtUL("UL", font, 50);
	txtUL.setFillColor(sf::Color::Black);
	txtUL.setPosition(sf::Vector2f(10, 10));
	// texte UR
	sf::Text txtUR("UR", font, 50);
	txtUR.setFillColor(sf::Color::Black);
	txtUR.setPosition(sf::Vector2f(410, 10));
	// texte DL
	sf::Text txtDL("DL", font, 50);
	txtDL.setFillColor(sf::Color::Black);
	txtDL.setPosition(sf::Vector2f(10, 160));
	// texte DR
	sf::Text txtDR("DR", font, 50);
	txtDR.setFillColor(sf::Color::Black);
	txtDR.setPosition(sf::Vector2f(410, 160));

	_deck.melanger();
	_question = _deck.tirer();

	choice = false;

	while (screen[0]->isOpen()) 
	{						// Is the window still opened?
		sf::Event event;								// We create an event

		while (screen[0]->pollEvent(event))
		{			// We fill the event from the window
			cout << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << endl;
			cout << butUL.getPosition().x << " " << butUL.getPosition().y << endl;
			switch (event.type)
			{
			case sf::Event::Closed:
				screen[0]->close();
				break;
			case sf::Event::MouseButtonPressed:
				if ((sf::Mouse::getPosition().x > butUL.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butUL.getGlobalBounds().left + butUL.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butUL.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butUL.getGlobalBounds().top + butUL.getGlobalBounds().height)))
					{
						//Réponse UL
						cout << "allo allo" << endl;
					}
				if ((sf::Mouse::getPosition().x > butUR.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butUR.getGlobalBounds().left + butUR.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butUR.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butUR.getGlobalBounds().top + butUR.getGlobalBounds().height)))
					{
						//Réponse UR
						cout << "allo allo" << endl;
					}
				if ((sf::Mouse::getPosition().x > butDL.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butDL.getGlobalBounds().left + butDL.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butDL.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butDL.getGlobalBounds().top + butDL.getGlobalBounds().height)))
					{
						//Réponse DL
						cout << "allo allo" << endl;
					}
				if ((sf::Mouse::getPosition().x > butDR.getGlobalBounds().left) &&
					(sf::Mouse::getPosition().x < (butDR.getGlobalBounds().left + butDR.getGlobalBounds().width)))
					if ((sf::Mouse::getPosition().y > butDR.getGlobalBounds().top) &&
						(sf::Mouse::getPosition().y < (butDR.getGlobalBounds().top + butDR.getGlobalBounds().height)))
					{
						//Réponse DR
						cout << "allo allo" << endl;
					}
				break;
			}
		}

		screen[0]->clear(sf::Color::White);							// This line clear the screen
		screen[1]->clear(sf::Color::White);

		screen[0]->draw(butUL);
		screen[0]->draw(butUR);
		screen[0]->draw(butDL);
		screen[0]->draw(butDR);

		screen[0]->draw(txtUL);
		screen[0]->draw(txtUR);
		screen[0]->draw(txtDL);
		screen[0]->draw(txtDR);

		screen[1]->draw(butUL);
		screen[1]->draw(butUR);
		screen[1]->draw(butDL);
		screen[1]->draw(butDR);

		screen[1]->draw(txtUL);
		screen[1]->draw(txtUR);
		screen[1]->draw(txtDL);
		screen[1]->draw(txtDR);


		screen[0]->display();							// And we display the window
		screen[1]->display();
	}
}