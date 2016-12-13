#pragma once
#include <random>
#include <string>
class question
{
private:
	std::string _question;
	std::string _reponses[4];
public:
	question();
	~question();
	void init(std::string s[6]);

	bool checkReponse(std::string s);	// V�rifie si le std::string donn� en param�tre est la bonne r�ponse	
	std::string getQuestion();			// Retourne la question,au sens de la phrase qui se termine par un "?"
	void getDuo(std::string s[2]);		// Retourne al�atoirement la bonne r�ponse et une mauvaise
	void getCarre(std::string s[4]);	// Retourne al�atoirement la bonne r�ponse et trois mauvaises

};

