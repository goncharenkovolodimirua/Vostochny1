#include "pch.h"
#include "Bullet.h"

Bullet::Bullet(std::int16_t positionX,
	std::int16_t positionY,
	std::uint16_t width,
	std::uint16_t height,
	sf::Image* textureImage, 
	std::int16_t positionXinTexture,
	std::int16_t positionYInTexture,
	std::int16_t widthInTexture,
	std::int16_t heightInTexture,
	float Vx, 
	float Vy,
	std::int16_t boundXMin,
	std::int16_t boundXMax,
	std::int16_t boundYMin,
	std::int16_t boundYMax,
	std::int16_t cost,
	SFML_GraphicalGameObject* ovner)
	:PhysicalGameObject(positionX, positionY, width,
		height, textureImage, positionXinTexture, positionYInTexture,
		widthInTexture, heightInTexture, Vx, Vy,
		boundXMin, boundXMax, boundYMin, boundYMax)
{
	this->cost = cost;
	this->ovner = ovner;
}


Bullet::~Bullet()
{
}

void Bullet::SetCost(std::int16_t cost)
{
	this->cost = cost;
}

int Bullet::GetCost()
{
	return this->cost;
}

bool Bullet::CheckColisionsWithBullets(std::list<PhysicalGameObject*>* bulletsList)
{
	return false;
}

bool Bullet::CheckAlive(float time)
{
	return true;
}

bool Bullet::CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors)
{
	return false;
}

void Bullet::Move(float deltaT)
{
	this->LinearMove(deltaT);
}

bool Bullet::CheckCollisionWithList(std::list<PhysicalGameObject*>* physicalGameObjectList, CollisionTypes typeOfCollision)
{
	switch (typeOfCollision)
	{
	case COLLISION_WITH_METEOR:
		return this->CheckCollisionsWithMetheors(physicalGameObjectList);
		break;
	case COLLISION_WITH_BULLET:
		return this->CheckColisionsWithBullets(physicalGameObjectList);
		break;
	default:
		return false;
		break;
	}
}
