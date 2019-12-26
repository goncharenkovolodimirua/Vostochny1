#include "pch.h"
#include "HighScore.h"

HighScore::HighScore(std::int16_t positionX, 
	std::int16_t positionY, 
	sf::Font * font, 
	std::uint16_t fontSize):SFML_TextGameObject(positionX, positionY, font, fontSize, "HIGHSCORE: 0")
{
	this->fileIn.open(HIGHSCORE_FILENAME, std::ios::binary);
	if (this->fileIn.is_open()) {
		this->fileIn.read((char*)&this->highscore, sizeof(std::int32_t));
		if (this->highscore != 0) {
			this->SetText("HIGHSCORE: " + std::to_string(this->highscore));
		}
		this->fileIn.close();
	}
	else {
		this->highscore = 0;
	}
}

HighScore::~HighScore()
{
}

void HighScore::NewScore(std::int32_t score)
{
	if (this->highscore < score) {
		this->highscore = score;
		this->fileOut.open(HIGHSCORE_FILENAME, std::ios::binary);
		if (this->fileOut.is_open()) {
			this->fileOut.write((char*)&this->highscore, sizeof(std::int32_t));
			this->SetText("HIGHSCORE: " + std::to_string(this->highscore));
			this->fileOut.close();
		}
	}
}
