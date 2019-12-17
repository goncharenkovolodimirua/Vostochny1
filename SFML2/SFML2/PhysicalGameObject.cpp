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