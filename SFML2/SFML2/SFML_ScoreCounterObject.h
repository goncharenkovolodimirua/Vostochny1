#ifndef __SFML_ScoreCounterObject__
#define __SFML_ScoreCounterObject__

#define TIME_COEF 100

#include "SFML_TextGameObject.h"
#include <string>

#pragma warning(disable : 4996)

class SFML_ScoreCounterObject :
	public SFML_TextGameObject
{
private:
	float coef;
	int score;

public:
	SFML_ScoreCounterObject(int positionX, int positionY, sf::Font* font, int fontSize, std::string text);

	void AddWithTime(float deltaTime);
};


#endif