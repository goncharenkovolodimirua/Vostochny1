#include "pch.h"
#include "GameButton.h"

GameButton::GameButton(std::int16_t positionX, 
	std::int16_t positionY, 
	sf::Font* font, 
	std::uint16_t fontSize, 
	std::string text,
	std::int16_t offsetVertical, 
	std::int16_t offsetHorizontal):
	SFML_TextGameObject(positionX, positionY, font, fontSize, text)
{
	this->offsetVertical = offsetVertical;
	this->offsetHorizontal = offsetHorizontal;

	this->rectangle = new sf::RectangleShape(sf::Vector2f(this->GetWidth()+offsetHorizontal, 
		this->GetHeight()+offsetVertical));

	this->rectangle->setPosition(this->GetSFMLText()->getGlobalBounds().left-offsetHorizontal/2,
		this->GetSFMLText()->getGlobalBounds().top-offsetVertical/2);

	this->noMouseFillColor = sf::Color(255, 255, 255);
	this->mouseOverFillColor = sf::Color(255, 255, 255);
	this->pressedFillColor = sf::Color(255, 255, 255);

	rectangle->setFillColor(this->noMouseFillColor);

	this->window = nullptr;
	this->lastSatement = false;
}

GameButton::~GameButton()
{
	delete this->rectangle;
}

void GameButton::DrawOnWindow(sf::RenderWindow *window)
{
	window->draw(*this->rectangle);
	window->draw(*this->GetSFMLText());

	if (this->window != window) {
		this->window = window;
	}
}

void GameButton::SetBackgroundColorNoMouse(sf::Color color)
{
	this->noMouseFillColor = color;
	this->rectangle->setFillColor(color);
}

void GameButton::SetBackgroundColorMouseOver(sf::Color color)
{
	this->mouseOverFillColor = color;
}

void GameButton::SetBackgroundColorPressed(sf::Color color)
{
	this->pressedFillColor = color;
}

void GameButton::ChangeButtonPosition(std::int16_t positionX, std::int16_t positionY)
{
	this->SetTextPosition(positionX, positionY);
	this->rectangle->setPosition(this->GetSFMLText()->getGlobalBounds().left - this->offsetHorizontal / 2,
		this->GetSFMLText()->getGlobalBounds().top - this->offsetVertical / 2);
}

void GameButton::Resize(std::uint16_t width, std::uint16_t height)
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

bool GameButton::CheckButtonPressed()
{
	std::int16_t positionX;
	std::int16_t positionY;
	if (this->window != nullptr) {
		positionX=sf::Mouse::getPosition(*window).x;
		positionY = sf::Mouse::getPosition(*window).y;
		
		if ((positionX >= this->rectangle->getGlobalBounds().left) 
			and ((positionX <= this->rectangle->getGlobalBounds().left 
				+ this->rectangle->getGlobalBounds().width) 
			and (positionY >= this->rectangle->getGlobalBounds().top)
			and ((positionY <= this->rectangle->getGlobalBounds().top
				+ this->rectangle->getGlobalBounds().height)))) {
			
			this->rectangle->setFillColor(this->mouseOverFillColor);
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->rectangle->setFillColor(this->pressedFillColor);
				this->lastSatement = true;
				return false;
			}
			else {
				if (this->lastSatement == true) {
					this->lastSatement = false;
					return true;
				}
				return false;
			}
		}
		else {
			this->rectangle->setFillColor(this->noMouseFillColor);
			this->lastSatement = false;
			return false;
		}
	}
	else {
		this->lastSatement = false;
		return false;
	}
}
