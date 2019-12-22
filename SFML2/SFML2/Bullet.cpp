#include "pch.h"
#include "Bullet.h"


Bullet::Bullet(int positionX, 
	int positionY, 
	int width,
	int height, 
	sf::Image* textureImage, 
	int positionXinTexture, 
	int positionYInTexture,
	int widthInTexture, 
	int heightInTexture, 
	float Vx, 
	float Vy,
	int boundXMin, 
	int boundXMax, 
	int boundYMin, 
	int boundYMax, 
	int cost,
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

void Bullet::SetCost(int cost)
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
