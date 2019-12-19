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

int SFML_TextGameObject::GetFontSize()
{
	return this->fontSize;
}

std::string SFML_TextGameObject::GetText()
{
	return this->text;
}

void SFML_TextGameObject::SetFont(sf::Font * font)
{
	this->SFMLFont = font;
	this->SFMLText->setFont(*font);
}

void SFML_TextGameObject::SetFontSize(int fontSize)
{
	this->fontSize = fontSize;
	this->SFMLText->setCharacterSize(fontSize);
}

void SFML_TextGameObject::SetText(std::string text)
{
	this->text = text;
	this->SFMLText->setString(text);
}

void SFML_TextGameObject::SetTextPosition(int positionX, int positionY)
{
	this->SetPositionX(positionX);
	this->SetPositionY(positionY);
	this->SFMLText->setPosition(positionX, positionY);
}

void SFML_TextGameObject::SetTextColor(sf::Color color)
{
	this->SFMLText->setColor(color);
}