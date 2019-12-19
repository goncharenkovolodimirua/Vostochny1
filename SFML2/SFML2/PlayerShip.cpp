#include "pch.h"
#include "PlayerShip.h"
#include <string>


PlayerShip::PlayerShip(
    int posX,
    int posY,
    int width,
    int height,
    sf::Image* textureImage,
    int positionXinTexture,
    int positionYInTexture,
    int widthInTexture,
    int heightInTexture,
    int controlWidthMin,
    int controlWidthMax,
    int cotrolHeightMin,
    int controlHeightMax,
    std::list<PhysicalGameObject*>* bulletsList
): SFML_GraphicalGameObject(
        posX,
        posY,
        width,
        height,
        textureImage,
        positionXinTexture,
        positionYInTexture,
        widthInTexture,
        heightInTexture
    )
{
    this->controlWidthMin = controlWidthMin;
    this->controlWidthMax = controlWidthMax;
    this->controlHeightMin = cotrolHeightMin;
    this->controlHeightMax = controlHeightMax;
    this->bulletsList = bulletsList;
}


PlayerShip::~PlayerShip()
{
}

void PlayerShip::Control(float time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if ((this->GetSpriteAddress()->getPosition().x - 0.5 * time) > this->controlWidthMin) {
            this->GetSpriteAddress()->move(-0.5 * time, 0);
            this->SetPositionX(this->GetSpriteAddress()->getPosition().x);
            this->SetPositionY(this->GetSpriteAddress()->getPosition().y);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if ((this->GetSpriteAddress()->getPosition().x + 0.5 * time) < this->controlWidthMax - this->GetWidth()) {
            this->GetSpriteAddress()->move(0.5 * time, 0);
            this->SetPositionX(this->GetSpriteAddress()->getPosition().x);
            this->SetPositionY(this->GetSpriteAddress()->getPosition().y);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if ((this->GetSpriteAddress()->getPosition().y - 0.5 * time) > this->controlHeightMin) {
            this->GetSpriteAddress()->move(0, -0.5 * time);
            this->SetPositionX(this->GetSpriteAddress()->getPosition().x);
            this->SetPositionY(this->GetSpriteAddress()->getPosition().y);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if ((this->GetSpriteAddress()->getPosition().y + 0.5 * time) < this->controlHeightMax - this->GetHeight()) {
            this->GetSpriteAddress()->move(0, 0.5 * time);
            this->SetPositionX(this->GetSpriteAddress()->getPosition().x);
            this->SetPositionY(this->GetSpriteAddress()->getPosition().y);
        }
    }
}
