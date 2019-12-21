#include "pch.h"
#include "SFML_GraphicalGameObject.h"

#include <iostream>



SFML_GraphicalGameObject::SFML_GraphicalGameObject(
    std::int16_t positionX, 
    std::int16_t positionY, 
    std::uint16_t width, 
    std::uint16_t height,
    sf::Image * textureImage, 
    std::int16_t positionXInTexture, 
    std::int16_t positionYInTexture, 
    std::uint16_t widthInTexture, 
    std::uint16_t heightInTexture
):SFML_GameObject(positionX, positionY, width, height)
{
    if ((textureImage != nullptr) && (width > 0) && (height > 0)) {

        this->textureImage = textureImage;
        this->positionXInTexture = positionXInTexture;
        this->positionYInTexture = positionYInTexture;
        this->SetOriginalWidth(widthInTexture);
        this->SetOriginalHeight(heightInTexture);
        

        this->texture = new sf::Texture;
        this->sprite = new sf::Sprite;

        this->texture->loadFromImage(*this->textureImage);
        this->sprite->setTexture(*this->texture);
        this->sprite->setTextureRect(
            sf::IntRect(
                positionXInTexture,
                positionYInTexture,
                widthInTexture,
                heightInTexture
            )
        );
        this->sprite->setPosition(positionX, positionY);
        this->Resize(width, height);
    }

}

SFML_GraphicalGameObject::~SFML_GraphicalGameObject()
{
    if (this->texture) {
        delete this->texture;
    }
    if (this->sprite) {
        delete this->sprite;
    }
}
void SFML_GraphicalGameObject::SetPosition(int16_t x, int16_t y)
{
    this->SetPositionX(x);
    this->SetPositionY(y);

    this->sprite->setPosition(x, y);
}

double SFML_GraphicalGameObject::GetScaleX()
{
	return this->scaleX;
}

double SFML_GraphicalGameObject::GetScaleY()
{
	return this->scaleY;
}

sf::IntRect SFML_GraphicalGameObject::GetTextureRect()
{
	return sf::IntRect(sf::Vector2i(this->positionXInTexture, this->positionYInTexture), 
		sf::Vector2i(this->GetOriginalWidth(), this->GetOriginalHeight()));
}

sf::Color SFML_GraphicalGameObject::GetPxColorLocal(int positionX, int positionY)
{
	sf::Image img;

	int positionXInTexture;
	int positionYInTexture;

	if ((positionX < 0) or (positionX > this->GetWidth()) or 
		(positionY<0) or positionY>this->GetHeight()) {
		return sf::Color(0, 0, 0, 0);
	}
	else {

		positionXInTexture = this->positionXInTexture + int(positionX * (1/this->scaleX));
		positionYInTexture = this->positionYInTexture + int(positionY * (1/this->scaleY));

		return this->textureImage->getPixel(positionXInTexture, positionYInTexture);
	}
}

sf::Color SFML_GraphicalGameObject::GetPxColorGlobal(int positionX, int positionY)
{
	int positionXInSprite;
	int positionYInSprite;
	
	positionXInSprite = positionX - this->GetPositionX();
	positionYInSprite = positionY - this->GetPositionY();

	return this->GetPxColorLocal(positionXInSprite, positionYInSprite);
}



void SFML_GraphicalGameObject::ResizeDefault()
{
    this->sprite->setScale(1, 1);
	this->scaleX = 1;
	this->scaleY = 1;
	this->SetWidth(this->GetOriginalWidth());
	this->SetHeight(this->GetOriginalHeight());
}

void SFML_GraphicalGameObject::DrawOnWindow(sf::RenderWindow * window)
{
    window->draw(*this->sprite);
}


void SFML_GraphicalGameObject::Resize(uint16_t width, uint16_t height)
{
    if (uint16_t originalWidth = this->GetOriginalWidth())
    {
        this->scaleX = (double) width / originalWidth;
    } else {
        return;
    }

    if (uint16_t originalHeight = this->GetOriginalHeight())
    {
        this->scaleY = (double) height / originalHeight;
    } else {
        return;
    }

    this->SetWidth(width);
    this->SetHeight(height);
    this->sprite->setScale(scaleX, scaleY);

}

int SFML_GraphicalGameObject::localXPositionToPositionInTexture(int positionX)
{
	return this->positionXInTexture + int(positionX * (1 / this->scaleX));
}

int SFML_GraphicalGameObject::localYPositionToPositionInTexture(int positionY)
{
	return this->positionYInTexture + int(positionY * (1 / this->scaleY));
}

int SFML_GraphicalGameObject::GlobalXPositionToLocalPosition(int positionX)
{
	return positionX - this->GetPositionX();
}

int SFML_GraphicalGameObject::GlobalYPositionToLocalPosition(int positionY)
{
	return positionY - this->GetPositionY();
}

int SFML_GraphicalGameObject::GlobalXPositionToPositionInTexture(int positionX)
{
	return this->localXPositionToPositionInTexture(this->GlobalXPositionToLocalPosition(positionX));
}

int SFML_GraphicalGameObject::GlobalYPositionToPositionInTexture(int positionY)
{
	return this->localYPositionToPositionInTexture(this->GlobalYPositionToLocalPosition(positionY));
}



void SFML_GraphicalGameObject::ChangeTextureRectangle(
    int16_t positionXInTexture,
    int16_t positionYInTexture,
    uint16_t widthInTexture,
    uint16_t heightInTexture
)
{
    this->positionXInTexture = positionXInTexture;
    this->positionYInTexture = positionYInTexture;
    this->SetOriginalWidth(widthInTexture);
    this->SetOriginalHeight(heightInTexture);

    this->sprite->setTextureRect(sf::IntRect(positionXInTexture,
        positionYInTexture, widthInTexture,
        heightInTexture));
    this->sprite->setScale(1, 1);
    this->Resize(this->GetWidth(), this->GetHeight());
}

sf::Sprite * SFML_GraphicalGameObject::GetSpriteAddress()
{
    return this->sprite;
}

sf::Image * SFML_GraphicalGameObject::GetTextureAddress()
{
	return this->textureImage;
}


