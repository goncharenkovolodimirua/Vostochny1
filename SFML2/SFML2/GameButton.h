#ifndef __GAME_BUTTON__
#define __GAME_BUTTON__
#include "SFML_TextGameObject.h"
class GameButton :
	public SFML_TextGameObject
{
private:
	sf::RectangleShape* rectangle;
	sf::RenderWindow *window;

	int offsetVertical;
	int offsetHorizontal;

	sf::Color noMouseFillColor;
	sf::Color mouseOverFillColor;
	sf::Color pressedFillColor;

public:
	GameButton(int positionX, int positionY, sf::Font* font, 
		int fontSize, std::string text, int offsetVertical, int offsetHorizontal);
	virtual ~GameButton();

	virtual void DrawOnWindow(sf::RenderWindow *window);

	void SetBackgroundColorNoMouse(sf::Color *color);
	void SetBackgroundColorMouseOver(sf::Color *color);
	void SetBackgroundColorPressed(sf::Color *color);

	virtual void ChangeButtonPosition(int positionX, int positionY);
	virtual void Resize(uint16_t width, uint16_t height);

	bool CheckButtonPressed();

};
#endif

