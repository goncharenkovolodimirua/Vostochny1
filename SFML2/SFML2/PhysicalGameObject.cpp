#include "pch.h"
#include "PhysicalGameObject.h"

PhysicalGameObject::PhysicalGameObject(int positionX, int positionY, int width, 
	int height, sf::Image * textureImage, int positionXinTexture, 
	int positionYInTexture, int widthInTexture, int heightInTexture, 
	float Vx, float Vy, int boundXMin, int boundXMax, int boundYMin, 
	int boundYMax) :SFML_GraphicalGameObject(positionX, positionY, 
		width, height, textureImage, positionXinTexture,
		positionYInTexture, widthInTexture, heightInTexture)
{
	this->Vx = Vx;
	this->Vy = Vy;
	this->boundXMin = boundXMin;
	this->boundXMax = boundXMax;
	this->boundYMin = boundYMin;
	this->boundYMax = boundYMax;
	this->globalPosX = this->GetPositionX();
	this->globalPosY = this->GetPositionY();
}

PhysicalGameObject::~PhysicalGameObject()
{
}

void PhysicalGameObject::SetVx(float Vx)
{
	this->Vx = Vx;
}

void PhysicalGameObject::SetVy(float Vy)
{
	this->Vy = Vy;
}

void PhysicalGameObject::SetBoundXMin(int boundXMin)
{
	this->boundXMin = boundXMin;
}

void PhysicalGameObject::SetBoundXMax(int boundXMax)
{
	this->boundXMax = boundXMax;
}

void PhysicalGameObject::SetboundYMin(int boundYMin)
{
	this->boundYMin = boundYMin;
}

void PhysicalGameObject::SetBoundYMax(int boundYMax)
{
	this->boundYMax = boundYMax;
}

int PhysicalGameObject::GetBoundXMin()
{
	return this->boundXMin;
}

int PhysicalGameObject::GetBoundXMax()
{
	return this->boundXMax;
}

int PhysicalGameObject::GetBoundYMin()
{
	return this->boundYMin;
}

int PhysicalGameObject::GetBoundYMax()
{
	return this->boundYMax;
}

void PhysicalGameObject::Move(float deltaT)
{
	this->globalPosX += Vx * deltaT;
	this->globalPosY += Vy * deltaT;
	this->SetPosition((uint16_t)this->globalPosX, (uint16_t)this->globalPosY);
}

bool PhysicalGameObject::IsInBounds()
{

	this->GetPositionY();

	if (this->boundXMin > this->GetPositionX())
	{
		return false;
	}
	else if (this->boundXMax < (this->GetPositionX() + this->GetWidth())) {
		return false;
	}
	else if (this->boundYMin > (this->GetPositionY() + this->GetHeight())) {
		return false;
	}
	else if (this->boundYMax < this->GetPositionY()) {
		return false;
	}
	return true;
}