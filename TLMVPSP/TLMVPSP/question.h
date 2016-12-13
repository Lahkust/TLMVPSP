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

	bool checkReponse(std::string s);	// Vérifie si le std::string donné en paramètre est la bonne réponse	
	std::string getQuestion();			// Retourne la question,au sens de la phrase qui se termine par un "?"
	void getDuo(std::string s[2]);		// Retourne aléatoirement la bonne réponse et une mauvaise
	void getCarre(std::string s[4]);	// Retourne aléatoirement la bonne réponse et trois mauvaises

};

