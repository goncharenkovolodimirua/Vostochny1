#include "pch.h"
#include "SFML_ScoreCounterObject.h"


SFML_ScoreCounterObject::SFML_ScoreCounterObject(int positionX, int positionY, sf::Font* font, int fontSize, std::string text) :SFML_TextGameObject(positionX, positionY, font, fontSize, text)
{
	this->coef = 1;
	this->score = 0;
}



void SFML_ScoreCounterObject::AddWithTime(float deltaTime)
{

	this->coef = coef + TIME_COEF * deltaTime;
	this->score = score + deltaTime * coef;
	this->SetText("SCORE:" + std::to_string(score));
}
