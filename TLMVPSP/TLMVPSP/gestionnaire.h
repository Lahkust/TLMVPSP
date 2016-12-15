#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "deck.h"
#include "manche.h"

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
	void play();
};

