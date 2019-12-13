#include "pch.h"
#include "SFML_GameObject.h"

void SFML_GameObject::SetPositionX(int positionX)
{
	this->positionX = positionX;
}

void SFML_GameObject::SetPositionY(int positionY)
{
	this->positionY = positionY;
}

void SFML_GameObject::SetWidth(int width)
{
	this->width = width;
}

void SFML_GameObject::SetHeight(int height)
{
	this->height = height;
}

void SFML_GameObject::SetOriginalWidth(int originalWidth)
{
	this->originalWidth = originalWidth;
}

void SFML_GameObject::SetOriginalHeight(int originalHeight)
{
	this->originalHeight = originalHeight;
}

int SFML_GameObject::GetOriginalWidth()
{
	return this->originalWidth;
}

int SFML_GameObject::GetOriginalHeight()
{
	return this->originalHeight;
}

int SFML_GameObject::GetPositionX()
{
	return this->positionX;
}

int SFML_GameObject::GetPositionY()
{
	return this->positionY;
}

int SFML_GameObject::GetWidth()
{
	return this->width;
}

int SFML_GameObject::GetHeight()
{
	return this->height;
}

sf::IntRect SFML_GameObject::GetIntRect()
{
	sf::IntRect rectangle(this->positionX, this->positionY, this->width, this->height);
	return rectangle;
}

bool SFML_GameObject::CheckColision(SFML_GameObject *gameObject)
{
	return this->GetIntRect().intersects(gameObject->GetIntRect());
}

SFML_GameObject::SFML_GameObject(int positionX, int positionY, int width, int height)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->width = width;
	this->height = height;
	this->originalWidth = 0;
	this->originalHeight = 0;
}

SFML_GameObject::SFML_GameObject(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->width = 0;
	this->height = 0;
	this->originalWidth = 0;
	this->originalHeight = 0;
}

SFML_GameObject::~SFML_GameObject()
{
}
