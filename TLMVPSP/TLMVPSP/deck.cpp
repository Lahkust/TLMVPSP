/* En-t�te du programme
====================
Programme :			deck.cpp
Auteur:				Guillaume Bergs
Date de derni�re modification :  2016/12/15
Description :		g�re la pile de question, permet de la m�langer et d'en donner une
To Do :				am�liorer le m�lange
*/
#include "deck.h"


deck::deck()
{
}


deck::~deck()
{
}


// M�lange le deck pour placer chaque question dedans dans un ordre al�atoire
void deck::melanger()
{
	//Les piles de questions temporaires
	std::stack<question> temp[6];

	//Initialiser le random stuff
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<uint32_t> rn(10, 50);
	std::uniform_int_distribution<uint32_t> rn2(2, 5);
	int nombreAleatoire = rn(mt);
	int nombreAleatoire2 = rn2(mt);

	//Un nombre al�atoire de fois
	for (auto i = 0; i < nombreAleatoire; ++i)
	{
		//D�piler dans un nombre al�atoire de piles
		nombreAleatoire2 = rn2(mt);

		while(_questions.size() !=0)
			for (auto j = 0; (j < nombreAleatoire2) && (_questions.size()!=0); ++j)
				temp[j].push(tirer());
		
		//Puis rempiler
		for (auto j = 0;
			!(	(temp[0].size() == 0) && 
				(temp[1].size() == 0) && 
				(temp[2].size() == 0) && 
				(temp[3].size() == 0) &&
				(temp[4].size() == 0) &&
				(temp[5].size() == 0)
			);
			++j) 
		{

			if (j > 5) j = 0;

			if (temp[j].size() > 0)
			{
				_questions.push(temp[j].top());
				temp[j].pop();
			}
		}
	}

}


// Tire la premi�re question du top du deck
question deck::tirer()
{
	question r = _questions.top();
	_questions.pop();
	return r;
}


// Initialise le deck � partir du fichier dont le nom est pass� en param�tre
void deck::init(std::string s)
{
	setlocale(LC_ALL, "fr-FR");
	ifstream entree;
	string questionReponses[6];
	question temp; //temporaire

	if (testFichierExiste(s)) {
		if (testFichierVide(s))				//Teste si le fichier existe et qu'il n'est pas vide avant tout
		{
			entree.open(s);					//Ouvrir le fichier
			std::string line;				//Une ligne du fichier
			std::getline(entree, line);		//Lire la premi�re ligne

			_nom = line;					//La premi�re ligne est le nom du deck
			while (!entree.eof())
			{
											//Les autres suivent le sh�ma...

				std::getline(entree, line);	//Question
				questionReponses[0] = line;

				std::getline(entree, line);	//Bonne r�ponse
				questionReponses[1] = line;

				std::getline(entree, line);	//Mauvaise r�ponse 1
				questionReponses[2] = line;
				std::getline(entree, line);	//Mauvaise r�ponse 2
				questionReponses[3] = line;
				std::getline(entree, line);	//Mauvaise r�ponse 3
				questionReponses[4] = line;
				std::getline(entree, line);	//Mauvaise r�ponse 4
				questionReponses[5] = line;

				temp.init(questionReponses);// On cr�e la carte de question avec ses r�ponses
				_questions.push(temp);		// Et on l'ajoute au deck
			}

			//Le fichier a �t� parcouru jusqu'au bout!

		}
		else //Si le fichier est vide
		{
			// "Le fichier " << s << " est vide!" << std::endl;
		}
	}
	else //Si le fichier n'existe pas
	{
		// "Le fichier " << s << " n'existe pas!" << std::endl;
	}

}
