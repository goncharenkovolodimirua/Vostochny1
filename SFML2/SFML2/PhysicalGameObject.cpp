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