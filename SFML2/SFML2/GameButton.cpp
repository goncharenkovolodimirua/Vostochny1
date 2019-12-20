#include "pch.h"
#include "GameButton.h"


GameButton::GameButton(int positionX, int positionY, sf::Font* font, int fontSize, std::string text, 
	int offsetVertical, int offsetHorizontal):
	SFML_TextGameObject(positionX, positionY, font, fontSize, text)
{
	this->offsetVertical = offsetVertical;
	this->offsetHorizontal = offsetHorizontal;

	this->rectangle = new sf::RectangleShape(sf::Vector2f(this->GetWidth()+offsetHorizontal, 
		this->GetHeight()+offsetVertical));

	rectangle->setPosition(this->GetSFMLText()->getGlobalBounds().left-offsetHorizontal/2,
		this->GetSFMLText()->getGlobalBounds().top-offsetVertical/2);

	

	rectangle->setFillColor(sf::Color(100, 250, 50));

}


GameButton::~GameButton()
{
}

void GameButton::DrawOnWindow(sf::RenderWindow *window)
{
	window->draw(*this->rectangle);
	window->draw(*this->GetSFMLText());

}
