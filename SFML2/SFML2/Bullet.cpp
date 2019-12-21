#include "pch.h"
#include "Bullet.h"


Bullet::Bullet(int positionX, int positionY, int width,
	int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
	int widthInTexture, int heightInTexture, float Vx, float Vy,
	int boundXMin, int boundXMax, int boundYMin, int boundYMax, int cost): PhysicalGameObject(positionX, positionY, width,
		height, textureImage, positionXinTexture, positionYInTexture,
		widthInTexture, heightInTexture, Vx, Vy,
		boundXMin, boundXMax, boundYMin, boundYMax)
{
	this->cost = cost;
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

void Bullet::CheckColisionsWithBullets(std::list<PhysicalGameObject*>* bulletsList)
{
}

bool Bullet::CheckAlive(float time)
{
	return false;
}

bool Bullet::CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors)
{
	return false;
}
