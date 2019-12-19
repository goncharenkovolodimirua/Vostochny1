#ifndef __SFML_TextGameObject__
#define __SFML_TextGameObject__

#include "SFML_GameObject.h"
#include <string>

#pragma warning(disable : 4996)

class SFML_TextGameObject :
	public SFML_GameObject
{
private:
	sf::Font* SFMLFont;
	int fontSize;
	sf::Text* SFMLText;
	std::string text;


public:
	SFML_TextGameObject(int positionX, int positionY, int width, int height, sf::Font* font, int fontSize);
	SFML_TextGameObject(int positionX, int positionY, int width, int height, sf::Font* font, int fontSize, std::string text);

	SFML_TextGameObject(int positionX, int positionY, sf::Font* font, int fontSize);
	SFML_TextGameObject(int positionX, int positionY, sf::Font* font, int fontSize, std::string text);
	
	virtual ~SFML_TextGameObject();

	void SetFont(sf::Font * font);
	void SetFontSize(int fontSize);
	void SetText(std::string text);
	void SetTextPosition(int positionX, int positionY);

	void SetTextColor(sf::Color color);


	int GetFontSize();
	std::string GetText();

	virtual void ResizeDefault();
	virtual void Resize(int width, int height);

	virtual void DrawOnWindow(sf::RenderWindow *window);
};


#endif