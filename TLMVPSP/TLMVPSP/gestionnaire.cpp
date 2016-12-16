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
	//sf::RectangleShape butJouer(sf::Vector2f(150, 100));
	//butJouer.setFillColor(sf::Color(50, 125, 200));
	//butJouer.setPosition(sf::Vector2f(500, 50));

	////button démo
	//sf::RectangleShape butDemo(sf::Vector2f(150, 100));
	//butDemo.setFillColor(sf::Color(50, 125, 200));
	//butDemo.setPosition(sf::Vector2f(500, 200));

	////button info
	//sf::RectangleShape butInfo(sf::Vector2f(150, 100));
	//butInfo.setFillColor(sf::Color(50, 125, 200));
	//butInfo.setPosition(sf::Vector2f(500, 350));

	////button quitter
	//sf::RectangleShape butQuitter(sf::Vector2f(150, 100));
	//butQuitter.setFillColor(sf::Color(50, 125, 200));
	//butQuitter.setPosition(sf::Vector2f(500, 500));

	////load font
	//sf::Font font;
	//if (!font.loadFromFile("arial.ttf"))
	//{
	//	// error...
	//}

	//// texte jouer
	//sf::Text txtJouer("Jouer", font, 50);
	//txtJouer.setFillColor(sf::Color::Black);
	//txtJouer.setPosition(sf::Vector2f(500, 50));
	//// texte démo
	//sf::Text txtDemo("Démo", font, 50);
	//txtDemo.setFillColor(sf::Color::Black);
	//txtDemo.setPosition(sf::Vector2f(500, 200));
	//// texte info
	//sf::Text txtInfo("Info", font, 50);
	//txtInfo.setFillColor(sf::Color::Black);
	//txtInfo.setPosition(sf::Vector2f(500, 350));
	//// texte quitter
	//sf::Text txtQuitter("Quitter", font, 50);
	//txtQuitter.setFillColor(sf::Color::Black);
	//txtQuitter.setPosition(sf::Vector2f(500, 500));

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

		/*window.draw(butJouer);
		window.draw(butDemo);
		window.draw(butInfo);
		window.draw(butQuitter);

		window.draw(txtJouer);
		window.draw(txtDemo);
		window.draw(txtInfo);
		window.draw(txtQuitter);*/

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



}