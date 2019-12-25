#ifndef __GAME_BUTTON__
#define __GAME_BUTTON__
#include "SFML_TextGameObject.h"

#include <cstdint>

class GameButton :
	public SFML_TextGameObject
{
private:
	sf::RectangleShape* rectangle;
	sf::RenderWindow *window;

	std::int16_t offsetVertical;
	std::int16_t offsetHorizontal;

	bool lastSatement;

	sf::Color noMouseFillColor;
	sf::Color mouseOverFillColor;
	sf::Color pressedFillColor;

public:
	GameButton(std::int16_t positionX, 
		std::int16_t positionY,
		sf::Font* font,
		std::uint16_t fontSize, 
		std::string text, 
		std::int16_t offsetVertical, 
		std::int16_t offsetHorizontal);
	virtual ~GameButton();

	virtual void DrawOnWindow(sf::RenderWindow *window);

	void SetBackgroundColorNoMouse(sf::Color color);
	void SetBackgroundColorMouseOver(sf::Color color);
	void SetBackgroundColorPressed(sf::Color color);

	virtual void ChangeButtonPosition(int positionX, int positionY);
	virtual void Resize(std::uint16_t width, std::uint16_t height);

	bool CheckButtonPressed();

};
#endif

