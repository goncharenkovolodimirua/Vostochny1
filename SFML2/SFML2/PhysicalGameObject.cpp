#include "pch.h"
#include "PhysicalGameObject.h"

PhysicalGameObject::PhysicalGameObject(
	int16_t positionX,
	int16_t positionY,
	uint16_t width,
	uint16_t height,
	sf::Image * textureImage, 
	int16_t positionXinTexture,
	int16_t positionYInTexture,
	uint16_t widthInTexture,
	uint16_t heightInTexture,
	float Vx, 
	float Vy, 
	int16_t boundXMin,
	int16_t boundXMax,
	int16_t boundYMin,
	int16_t boundYMax):SFML_GraphicalGameObject(positionX, positionY,
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

float PhysicalGameObject::GetVx()
{
	return this->Vx;
}

float PhysicalGameObject::GetVy()
{
	return this->Vy;
}

void PhysicalGameObject::SetBoundXMin(int16_t boundXMin)
{
	this->boundXMin = boundXMin;
}

void PhysicalGameObject::SetBoundXMax(int16_t boundXMax)
{
	this->boundXMax = boundXMax;
}

void PhysicalGameObject::SetboundYMin(int16_t boundYMin)
{
	this->boundYMin = boundYMin;
}

void PhysicalGameObject::SetBoundYMax(int16_t boundYMax)
{
	this->boundYMax = boundYMax;
}

int16_t PhysicalGameObject::GetBoundXMin()
{
	return this->boundXMin;
}

int16_t PhysicalGameObject::GetBoundXMax()
{
	return this->boundXMax;
}

int16_t PhysicalGameObject::GetBoundYMin()
{
	return this->boundYMin;
}

int16_t PhysicalGameObject::GetBoundYMax()
{
	return this->boundYMax;
}

void PhysicalGameObject::LinearMove(float deltaT)
{
	this->globalPosX += Vx * deltaT;
	this->globalPosY += Vy * deltaT;
	this->SetPosition(static_cast<int16_t>(this->globalPosX), static_cast<int16_t>(this->globalPosY));
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