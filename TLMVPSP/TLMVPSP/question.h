/* En-t�te du programme
====================
Programme :			question.h
Auteur:				Guillaume Bergs
Date de derni�re modification :  2016/12/15
Description :		contient une question et ses r�ponses, peut v�rifier si une string donn�e est la bonne r�ponse et donner des r�ponses al�atoires
To Do :				am�liorer la donne al�atoire de r�ponses
*/

#pragma once
#include <random>
#include <string>
class question
{
private:
	std::string _question;
	std::string _reponses[5];
public:
	question();
	~question();
	void init(std::string s[6]);

	bool checkReponse(std::string s);	// V�rifie si le std::string donn� en param�tre est la bonne r�ponse	
	std::string getQuestion();			// Retourne la question,au sens de la phrase qui se termine par un "?"
	void getDuo(std::string s[2]);		// Retourne al�atoirement la bonne r�ponse et une mauvaise
	void getCarre(std::string s[4]);	// Retourne al�atoirement la bonne r�ponse et trois mauvaises

};

