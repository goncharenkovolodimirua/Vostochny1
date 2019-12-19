#include "pch.h"
#include "SFML_TextGameObject.h"

SFML_TextGameObject::SFML_TextGameObject(int positionX, int positionY, 
	sf::Font * font, int fontSize) :SFML_GameObject(positionX, positionY)
{
	this->SFMLFont = font;
	this->fontSize = fontSize;
	this->SFMLText = new sf::Text("", *this->SFMLFont, this->fontSize);

	this->SFMLText->setPosition(positionX, positionY);

	this->SFMLText->setScale(1, 1);
	this->SetOriginalWidth(this->SFMLText->getGlobalBounds().width);
	this->SetOriginalHeight(this->SFMLText->getGlobalBounds().height);
	this->SetWidth(this->SFMLText->getGlobalBounds().width);
	this->SetHeight(this->SFMLText->getGlobalBounds().height);

}

SFML_TextGameObject::SFML_TextGameObject(int positionX, int positionY, sf::Font * font, int fontSize, std::string text) :SFML_GameObject(positionX, positionY)
{
	this->SFMLFont = font;
	this->fontSize = fontSize;
	this->SFMLText = new sf::Text("", *this->SFMLFont, this->fontSize);

	this->SFMLText->setString(text);

	this->SFMLText->setPosition(positionX, positionY);

	this->SFMLText->setScale(1, 1);
	this->SetOriginalWidth(this->SFMLText->getGlobalBounds().width);
	this->SetOriginalHeight(this->SFMLText->getGlobalBounds().height);
	this->SetWidth(this->SFMLText->getGlobalBounds().width);
	this->SetHeight(this->SFMLText->getGlobalBounds().height);
}

SFML_TextGameObject::~SFML_TextGameObject()
{
	delete this->SFMLText;
}