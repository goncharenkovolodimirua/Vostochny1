#include "pch.h"
#include "SFML_ScoreCounterObject.h"


SFML_ScoreCounterObject::SFML_ScoreCounterObject(std::int16_t positionX,
	std::int16_t positionY,
	sf::Font* font,
	std::uint16_t fontSize) :SFML_TextGameObject(positionX, positionY, font, fontSize, "SCORE: ")
{
	this->coef = 1;
	this->score = 0;
}

SFML_ScoreCounterObject::~SFML_ScoreCounterObject()
{
}

void SFML_ScoreCounterObject::AddWithTime(float deltaTime)
{
	if (this->coef<MAX_COEF)
	{
		this->coef = this->coef + TIME_COEF * deltaTime;
	}
	this->score = this->score + static_cast<std::int32_t>(deltaTime * this->coef);
	this->SetText("SCORE:" + std::to_string(this->score));
	
}

void SFML_ScoreCounterObject::AddWithNumber(std::int32_t score)
{
	this->score += score;
	this->SetText("SCORE:" + std::to_string(this->score));
}

void  SFML_ScoreCounterObject::SubstractWithNumber(std::int32_t score)
{
	this->score -= score;
	this->SetText("SCORE:" + std::to_string(this->score));
}
void SFML_ScoreCounterObject::SetScore(std::int32_t score)
{
	this->score = score;
}
void SFML_ScoreCounterObject::SetCoef(float coef)
{
	this->coef = coef;
}
std::int32_t SFML_ScoreCounterObject::GetScore()
{
	return this->score;
}
float SFML_ScoreCounterObject::GetCoef()
{
	return this->coef;
}