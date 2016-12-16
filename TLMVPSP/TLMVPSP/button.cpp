#pragma once
#include "button.h"

Button::Button(sf::Image* normal, sf::Image* clicked, std::string words, sf::Vector2f location) {

	sf::Texture temp;
	temp.loadFromImage(*normal);
	this->normal.setTexture(temp);
	temp.loadFromImage(*clicked);
	this->clicked.setTexture(temp);
	this->currentSpr = &this->normal;
	current = false;
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	String = words;
	//String.setPosition(location.x + 3, location.y + 3);
	//String.SetSize(14);
}


void Button::checkClick(sf::Vector2f mousePos) {
	if (mousePos.x>currentSpr->getPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->getScale().x)) {
		if (mousePos.y>currentSpr->getPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->getScale().y)) {
			setState(!current);
		}
	}
}

void Button::setState(bool which) {
	current = which;
	if (current) {
		currentSpr = &clicked;
		return;
	}
	currentSpr = &normal;
}

void Button::setText(std::string words) {
	String = words;
}

bool Button::getVar() {
	return current;
}

sf::Sprite* Button::getSprite() {
	return currentSpr;
}

sf::String * Button::getText() {
	return &String;
}