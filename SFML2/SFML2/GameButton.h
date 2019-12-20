#ifndef __GAME_BUTTON__
#define __GAME_BUTTON__
#include "SFML_TextGameObject.h"
class GameButton :
	public SFML_TextGameObject
{
private:
	sf::RectangleShape* rectangle;
	int offsetVertical;
	int offsetHorizontal;

public:
	GameButton(int positionX, int positionY, sf::Font* font, 
		int fontSize, std::string text, int offsetVertical, int offsetHorizontal);
	virtual ~GameButton();

	virtual void DrawOnWindow(sf::RenderWindow *window);

	void SetBackgroundColor(sf::Color *color);

	void ChangeButtonPosition();


};
#endif

