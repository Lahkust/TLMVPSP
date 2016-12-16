/* En-t�te du programme
====================
Programme :			gestionnaire.h
Auteurs:			Christopher Brown, Guillaume Bergs
Date de derni�re modification :  2016/12/15
Description :		g�re le d�roulement des parties
To Do :				coder une partie compl�te
*/
#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "deck.h"
#include "manche.h"
#include "button.h"
#include <SFML\Audio.hpp>


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
	// Joue la d�mo, 0: contr�le 1: projecteur
	void demo(sf::RenderWindow* screen[2]);
};

