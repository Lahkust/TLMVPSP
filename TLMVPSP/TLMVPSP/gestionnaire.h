#pragma once
class gestionnaire
{
public:
	gestionnaire();
	~gestionnaire();
private:
	int _actuelle;
	int _manche[3];
	deck _deck;
public:
	// Initialisation
	void init();
	// lance une partie
	void play();
};

