#ifndef __SFML_ScoreCounterObject__
#define __SFML_ScoreCounterObject__

#define TIME_COEF 100
#define MAX_COEF 0.0001

#include "SFML_TextGameObject.h"
#include <string>
#include <cstdint>

#pragma warning(disable : 4996)

class SFML_ScoreCounterObject :
	public SFML_TextGameObject
{
private:
	float coef;
	std::int16_t score;

public:
	SFML_ScoreCounterObject(std::int16_t positionX, std::int16_t positionY, sf::Font* font, std::uint16_t fontSize);

	void AddWithTime(float deltaTime);
	void AddWithNumber(std::int16_t score);
	void SubstractWithNumber(std::int16_t score);
	void SetScore(std::int16_t score);
	void SetCoef(float coef);
	std::int16_t GetScore();
	float GetCoef();
};


#endif