#include "pch.h"
#include "SFML_GameObject.h"


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
