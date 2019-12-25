#include "pch.h"
#include "PlayerShip.h"
#include <string>


void PlayerShip::Shoot()
{
	if (this->bulletTexture != nullptr) {
		std::int16_t positionX = this->GetPositionX() + int(this->GetWidth() / 2)-int(this->bulletWidth/2);
		std::int16_t positionY = this->GetPositionY() + 1 + this->bulletHeight;
		Bullet* bullet = new Bullet(positionX, positionY, this->bulletWidth, this->bulletHeight, this->bulletTexture, 0, 0, 
			this->bulletTexture->getSize().x, this->bulletTexture->getSize().y, 0, BULLET_SPEED, this->bulletBoundXMin,
			this->bulletBoundXMax, this->bulletBoundYMin, this->bulletBoundYMax, BULLET_COST, this);
		this->bulletsList->push_back(bullet);
	}
}

PlayerShip::PlayerShip(
	std::int16_t positionX,
	std::int16_t positionY,
	std::uint16_t width,
	std::uint16_t height,
    sf::Image* textureImage,
	std::int16_t positionXinTexture,
	std::int16_t positionYInTexture,
	std::uint16_t widthInTexture,
	std::uint16_t heightInTexture,
	std::int16_t controlWidthMin,
	std::int16_t controlWidthMax,
	std::int16_t cotrolHeightMin,
	std::int16_t controlHeightMax,
    std::list<PhysicalGameObject*>* bulletsList):SFML_GraphicalGameObject
	(
        positionX,
        positionY,
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

	this->bulletTexture = nullptr;
	this->bulletBoundXMax = 0;
	this->bulletBoundXMin = 0;
	this->bulletBoundYMax = 0;
	this->bulletBoundYMin = 0;

	this->bulletWidth = 0;
	this->bulletHeight = 0;


	this->needToShot = 0;
	this->lastShotTime = BULLET_TIMEOUT;
	this->lastSpaceStatement = false;
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (this->lastSpaceStatement == false) {
			this->needToShot += 1;
		}
		this->lastSpaceStatement = true;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->lastSpaceStatement = false;
	}

	this->lastShotTime += time;

	if (this->needToShot > 0) {
		if (this->lastShotTime >= BULLET_TIMEOUT) {
			
			this->Shoot();
			this->lastShotTime = 0;
			this->needToShot -= 1;
		}
	}
}

bool PlayerShip::CheckCollisionsWithMeteors(std::list<PhysicalGameObject*>* meteors)
{
	std::list<PhysicalGameObject*>::iterator k;
	bool collision = false;

	for (k = meteors->begin(); k != meteors->end();) {
		if ((*k)->CheckPxCollision(this, MIN_ALPHA_VAL)) {
			collision = true;
			++k;
		}
		else {
			++k;
		}
	}
	return collision;
}

void PlayerShip::SetBulletTextureImage(sf::Image * bulletTexture)
{
	this->bulletTexture = bulletTexture;
}

void PlayerShip::SetBulletBoundXMax(std::int16_t bulletBoundXMax)
{
	this->bulletBoundXMax = bulletBoundXMax;
}

void PlayerShip::SetBulletBoundYMax(std::int16_t bulletBoundYMax)
{
	this->bulletBoundYMax = bulletBoundYMax;
}

void PlayerShip::SetBulletBoundXMin(std::int16_t bulletBoundXMin)
{
	this->bulletBoundXMin = bulletBoundXMin;
}

void PlayerShip::SetBulletBoundYMin(std::int16_t bulletBoundYMin)
{
	this->bulletBoundYMin = bulletBoundYMin;
}

void PlayerShip::SetBulletWidth(std::uint16_t bulletWidth)
{
	this->bulletWidth = bulletWidth;
}

void PlayerShip::SetBulletHeight(std::uint16_t bulletHeight)
{
	this->bulletHeight = bulletHeight;
}
