#include "question.h"



question::question()
{
}


question::~question()
{
}


void question::init(std::string s[6])
{
	_question = s[0];
	_reponses[0] = s[1];
	_reponses[1] = s[2];
	_reponses[2] = s[3];
	_reponses[3] = s[4];
	_reponses[4] = s[5];

}


// Retourne al�atoirement la bonne r�ponse et une mauvaise
void question::getDuo(std::string s[2])
{
	//Initialiser le random stuff
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<uint32_t> m(2, 2);		//choisit une mauvaise r�ponse
	int mauvaise = m(mt);
	std::uniform_int_distribution<uint32_t> b(0, 1);	//indique si la bonne r�ponse ira � la place 0 ou 1
	int bonnePlace = b(mt);

	//Mettre la bonne r�ponse quelque part
	s[bonnePlace] = _reponses[0];
	//Mettre la mauvaise r�ponse autre part
	s[1 - bonnePlace] = _reponses[mauvaise];

}


// Retourne al�atoirement la bonne r�ponse et trois mauvaises
void question::getCarre(std::string s[4])
{

	//Placer quatre mauvaises r�ponses dans la sortie

	s[0] = _reponses[2];
	s[1] = _reponses[3];
	s[2] = _reponses[4];
	s[3] = _reponses[5];

	//Initialiser le random stuff
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<uint32_t> b(0, 3);	//indique la place o� ira la bonne r�ponse
	int bonnePlace = b(mt);

	//Mettre la bonne r�ponse quelque part
	s[bonnePlace] = _reponses[0];

}


// V�rifie si le std::string donn� en param�tre est la bonne r�ponse
bool question::checkReponse(std::string s)
{
	return s == _question;
}


// Retourne la question,au sens de la phrase qui se termine par un "?"
std::string question::getQuestion()
{
	return _question;
}
