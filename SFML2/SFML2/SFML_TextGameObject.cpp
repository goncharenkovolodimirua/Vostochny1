#include "pch.h"
#include "SFML_TextGameObject.h"


sf::Text * SFML_TextGameObject::GetSFMLText()
{
	return this->SFMLText;
}

SFML_TextGameObject::SFML_TextGameObject(std::int16_t positionX,
	std::int16_t positionY,
	std::uint16_t width,
	std::uint16_t height,
	sf::Font* font,
	std::uint16_t fontSize):SFML_GameObject(positionX, positionY, width, height)
{
	this->SFMLFont = font;
	this->fontSize = fontSize;
	this->SFMLText = new sf::Text("", *this->SFMLFont, this->fontSize);
	
	this->SFMLText->setPosition(positionX, positionY);

	this->Resize(width, height);
}

SFML_TextGameObject::SFML_TextGameObject(std::int16_t positionX,
	std::int16_t positionY,
	std::uint16_t width,
	std::uint16_t height,
	sf::Font* font,
	std::uint16_t fontSize,
	std::string text) :SFML_GameObject(positionX, positionY, width, height)
{
	this->SFMLFont = font;
	this->fontSize = fontSize;
	this->SFMLText = new sf::Text("", *this->SFMLFont, this->fontSize);
	this->SFMLText->setString(text);

	this->SFMLText->setPosition(positionX, positionY);

	this->Resize(width, height);
}

SFML_TextGameObject::SFML_TextGameObject(std::int16_t positionX,
	std::int16_t positionY,
	sf::Font* font,
	std::uint16_t fontSize) :SFML_GameObject(positionX, positionY)
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

SFML_TextGameObject::SFML_TextGameObject(std::int16_t positionX,
	std::int16_t positionY,
	sf::Font* font,
	std::uint16_t fontSize,
	std::string text) :SFML_GameObject(positionX, positionY)
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

void SFML_TextGameObject::Resize(std::uint16_t width, std::uint16_t height) {
	float scaleX;
	float scaleY;

	this->SFMLText->setScale(1, 1);
	this->SetOriginalWidth(this->SFMLText->getGlobalBounds().width);
	this->SetOriginalHeight(this->SFMLText->getGlobalBounds().height);

	if ((width > 0)&(height > 0)) {
		scaleX = static_cast<float>(width / this->GetOriginalWidth());
		scaleY = static_cast<float>(height / this->GetOriginalHeight());

		this->SetWidth (width);
		this->SetHeight (height);

		this->SFMLText->setScale(scaleX, scaleY);
	}
}

void SFML_TextGameObject::DrawOnWindow(sf::RenderWindow * window)
{
	window->draw(*this->SFMLText);
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

void SFML_TextGameObject::SetFontSize(std::uint16_t fontSize)
{
	this->fontSize = fontSize;
	this->SFMLText->setCharacterSize(fontSize);
}

void SFML_TextGameObject::SetText(std::string text)
{
	this->text = text;
	this->SFMLText->setString(text);
	this->SetHeight(this->SFMLText->getGlobalBounds().height);
	this->SetWidth(this->SFMLText->getGlobalBounds().width);
}

void SFML_TextGameObject::SetTextPosition(std::int16_t positionX, std::int16_t positionY)
{
	this->SetPositionX(positionX);
	this->SetPositionY(positionY);
	this->SFMLText->setPosition(positionX, positionY);
}

void SFML_TextGameObject::SetTextColor(sf::Color color)
{
	this->SFMLText->setColor(color);
}