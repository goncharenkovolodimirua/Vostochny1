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

	this->rectangle->setPosition(this->GetSFMLText()->getGlobalBounds().left-offsetHorizontal/2,
		this->GetSFMLText()->getGlobalBounds().top-offsetVertical/2);

	this->noMouseFillColor = sf::Color(255, 255, 255);
	rectangle->setFillColor(this->noMouseFillColor);

}


GameButton::~GameButton()
{
	delete this->rectangle;
}

void GameButton::DrawOnWindow(sf::RenderWindow *window)
{
	window->draw(*this->rectangle);
	window->draw(*this->GetSFMLText());

}

void GameButton::SetBackgroundColorNoMouse(sf::Color * color)
{
	this->noMouseFillColor = *color;
	this->rectangle->setFillColor(*color);
}

void GameButton::SetBackgroundColorMouseOver(sf::Color * color)
{
	this->mouseOverFillColor = *color;
}

void GameButton::SetBackgroundColorPressed(sf::Color * color)
{
	this->pressedFillColor = *color;

}

void GameButton::ChangeButtonPosition(int positionX, int positionY)
{
	this->SetTextPosition(positionX, positionY);
	this->rectangle->setPosition(this->GetSFMLText()->getGlobalBounds().left - this->offsetHorizontal / 2,
		this->GetSFMLText()->getGlobalBounds().top - this->offsetVertical / 2);
}

void GameButton::Resize(uint16_t width, uint16_t height)
{
	float scaleX;
	float scaleY;

	this->GetSFMLText()->setScale(1, 1);
	this->SetOriginalWidth(this->GetSFMLText()->getGlobalBounds().width);
	this->SetOriginalHeight(this->GetSFMLText()->getGlobalBounds().height);

	if ((width > 0)&(height > 0)) {
		scaleX = ((float)width - this->offsetHorizontal)/ this->GetOriginalWidth();
		scaleY = ((float)height - this->offsetVertical)/ this->GetOriginalHeight();

		this->SetWidth(width);
		this->SetHeight(height);

		this->GetSFMLText()->setScale(scaleX, scaleY);
	}
	this->rectangle->setSize(sf::Vector2f(this->GetWidth() + this->offsetHorizontal,
		this->GetHeight() + this->offsetVertical));

	this->rectangle->setPosition(this->GetSFMLText()->getGlobalBounds().left - this->offsetHorizontal / 2,
		this->GetSFMLText()->getGlobalBounds().top - this->offsetVertical / 2);
}
