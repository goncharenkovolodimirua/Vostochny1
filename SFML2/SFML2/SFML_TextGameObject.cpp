#include "pch.h"
#include "SFML_TextGameObject.h"


SFML_TextGameObject::SFML_TextGameObject(int positionX, int positionY, int width, int height, 
	sf::Font * font, int fontSize):SFML_GameObject(positionX, positionY, width, height)
{
	this->SFMLFont = font;
	this->fontSize = fontSize;
	this->SFMLText = new sf::Text("", *this->SFMLFont, this->fontSize);
	
	this->SFMLText->setPosition(positionX, positionY);

	this->Resize(width, height);
}

SFML_TextGameObject::SFML_TextGameObject(int positionX, int positionY, int width, 
	int height, sf::Font * font, int fontSize, std::string text) :SFML_GameObject(positionX, positionY, width, height)
{
	this->SFMLFont = font;
	this->fontSize = fontSize;
	this->SFMLText = new sf::Text("", *this->SFMLFont, this->fontSize);
	this->SFMLText->setString(text);

	this->SFMLText->setPosition(positionX, positionY);

	this->Resize(width, height);
}

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

void SFML_TextGameObject::ResizeDefault()
{
	this->SFMLText->setScale(1, 1);
}

void SFML_TextGameObject::Resize(int width, int height) {
	float scaleX;
	float scaleY;

	this->SFMLText->setScale(1, 1);
	this->SetOriginalWidth(this->SFMLText->getGlobalBounds().width);
	this->SetOriginalHeight(this->SFMLText->getGlobalBounds().height);

	if ((width > 0)&(height > 0)) {
		scaleX = (float)width / this->GetOriginalWidth();
		scaleY = (float)height / this->GetOriginalHeight();

		this->SetWidth (width);
		this->SetHeight (height);

		this->SFMLText->setScale(scaleX, scaleY);
	}
}