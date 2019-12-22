#ifndef __SFML_ScoreCounterObject__
#define __SFML_ScoreCounterObject__

#define TIME_COEF 100
#define MAX_COEF 1

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
	SFML_ScoreCounterObject(int positionX, int positionY, sf::Font* font, int fontSize);

	void AddWithTime(float deltaTime);
	void AddWithNumber(int score);
	void SubstractWithNumber(int score);
	void SetScore(int score);
	void SetCoef(float coef);
	int GetScore();
	float GetCoef();
};


#endif