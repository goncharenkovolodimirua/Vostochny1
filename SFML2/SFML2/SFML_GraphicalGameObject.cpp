#include "pch.h"
#include "SFML_GraphicalGameObject.h"

SFML_GraphicalGameObject::SFML_GraphicalGameObject(
    std::int16_t positionX, 
    std::int16_t positionY, 
    std::uint16_t width, 
    std::uint16_t height,
    sf::Image * textureImage, 
    std::int16_t positionXInTexture, 
    std::int16_t positionYInTexture, 
    std::int16_t widthInTexture, 
    std::int16_t heightInTexture
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
void SFML_GraphicalGameObject::SetPosition(std::int16_t x, std::int16_t y)
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

sf::Image * SFML_GraphicalGameObject::GetTextureCopy()
{
	sf::Image* copy = new sf::Image(*this->textureImage);
	return copy;
}

sf::Color SFML_GraphicalGameObject::GetPxColorLocal(std::int16_t positionX, std::int16_t positionY)
{
	sf::Image img;

	int positionXInTexture;
	int positionYInTexture;

	if ((positionX < 0) or (positionX > this->GetWidth()) or 
		(positionY<0) or positionY>this->GetHeight()) {
		return sf::Color(0, 0, 0, 0);
	}
	else {

		positionXInTexture = this->positionXInTexture + static_cast<std::int16_t>(positionX * (1/this->scaleX));
		positionYInTexture = this->positionYInTexture + static_cast<std::int16_t>(positionY * (1/this->scaleY));

		return this->textureImage->getPixel(positionXInTexture, positionYInTexture);
	}
}

sf::Color SFML_GraphicalGameObject::GetPxColorGlobal(std::int16_t positionX, std::int16_t positionY)
{
	std::int16_t positionXInSprite;
	std::int16_t positionYInSprite;
	
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


void SFML_GraphicalGameObject::Resize(std::uint16_t width, std::uint16_t height)
{
    if (std::uint16_t originalWidth = this->GetOriginalWidth())
    {
        this->scaleX = (double) width / originalWidth;
    } else {
        return;
    }

    if (std::uint16_t originalHeight = this->GetOriginalHeight())
    {
        this->scaleY = (double) height / originalHeight;
    } else {
        return;
    }

    this->SetWidth(width);
    this->SetHeight(height);
    this->sprite->setScale(scaleX, scaleY);
}

std::int16_t SFML_GraphicalGameObject::localXPositionToPositionInTexture(std::int16_t positionX)
{
	return this->positionXInTexture + static_cast<std::int16_t>(positionX * (1 / this->scaleX));
}

std::int16_t SFML_GraphicalGameObject::localYPositionToPositionInTexture(std::int16_t positionY)
{
	return this->positionYInTexture + static_cast<std::int16_t>(positionY * (1 / this->scaleY));
}

std::int16_t SFML_GraphicalGameObject::GlobalXPositionToLocalPosition(std::int16_t positionX)
{
	return positionX - this->GetPositionX();
}

std::int16_t SFML_GraphicalGameObject::GlobalYPositionToLocalPosition(std::int16_t positionY)
{
	return positionY - this->GetPositionY();
}

std::int16_t SFML_GraphicalGameObject::GlobalXPositionToPositionInTexture(std::int16_t positionX)
{
	return this->localXPositionToPositionInTexture(this->GlobalXPositionToLocalPosition(positionX));
}

std::int16_t SFML_GraphicalGameObject::GlobalYPositionToPositionInTexture(std::int16_t positionY)
{
	return this->localYPositionToPositionInTexture(this->GlobalYPositionToLocalPosition(positionY));
}


void SFML_GraphicalGameObject::ChangeTextureRectangle(
	std::int16_t positionXInTexture,
	std::int16_t positionYInTexture,
	std::int16_t widthInTexture,
	std::int16_t heightInTexture
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


bool SFML_GraphicalGameObject::CheckPxCollision(SFML_GraphicalGameObject * graphicalGameObject, std::int16_t alphaChanelMinValue)
{
	sf::IntRect intersection;
	sf::Image *secondObjectTexture=nullptr; 

	if (this->CheckSpriteColision(graphicalGameObject, &intersection)) {
		secondObjectTexture = graphicalGameObject->GetTextureCopy();
		//For each string in intersection 
		for (std::int16_t i = intersection.top; i < intersection.top + intersection.height; i++) {
			//For each column in intersection 
			for (std::int16_t j = intersection.left; j < intersection.left + intersection.width; j += 1) {

				//If in this sprite alpha chanel is greater or equal min value 
				//(that means there is an object part)
				if (this->textureImage->getPixel(this->GlobalXPositionToPositionInTexture(j), 
					this->GlobalYPositionToPositionInTexture(i)).a >= alphaChanelMinValue) {

					//If in sprite of second object alpha chanel is greater or equal min value 
					//(that means there is an object part)
					if (secondObjectTexture->getPixel(graphicalGameObject->GlobalXPositionToPositionInTexture(j),
						graphicalGameObject->GlobalYPositionToPositionInTexture(i)).a >= alphaChanelMinValue) {
						
						//It's a collision
						delete secondObjectTexture;
						return true;
					}
				}
			}
		}
		if (secondObjectTexture != nullptr) {
			delete secondObjectTexture;
		}
		return false;
	}
	else {
		return false;
	}
}