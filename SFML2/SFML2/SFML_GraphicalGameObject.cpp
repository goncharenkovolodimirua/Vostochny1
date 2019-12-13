#include "SFML_GraphicalGameObject.h"

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