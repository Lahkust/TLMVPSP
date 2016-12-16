#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "deck.h"
#include "manche.h"
#include "button.h"

class gestionnaire
{
public:
	gestionnaire();
	~gestionnaire();
private:
	int _actuelle;
	manche _manche[3];
	deck _deck[3];
public:
	// Initialisation
	void init();
	// lance une partie
	void play(sf::RenderWindow* screen[2]);
	// Joue la démo, 0: contrôle 1: projecteur
	void demo(sf::RenderWindow* screen[2]);
};

