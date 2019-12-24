#include "pch.h"
#include "SFML_GameObject.h"


void SFML_GameObject::SetPositionX(std::int16_t positionX)
{
	this->positionX = positionX;
}

void SFML_GameObject::SetPositionY(std::int16_t positionY)
{
	this->positionY = positionY;
}

void SFML_GameObject::SetWidth(std::uint16_t width)
{
	this->width = width;
}

void SFML_GameObject::SetHeight(std::uint16_t height)
{
	this->height = height;
}

void SFML_GameObject::SetOriginalWidth(std::int16_t originalWidth)
{
	this->originalWidth = originalWidth;
}

void SFML_GameObject::SetOriginalHeight(std::int16_t originalHeight)
{
	this->originalHeight = originalHeight;
}

std::int16_t SFML_GameObject::GetOriginalWidth()
{
	return this->originalWidth;
}

std::int16_t SFML_GameObject::GetOriginalHeight()
{
	return this->originalHeight;
}

std::int16_t SFML_GameObject::GetPositionX()
{
	return this->positionX;
}

std::int16_t SFML_GameObject::GetPositionY()
{
	return this->positionY;
}

std::uint16_t SFML_GameObject::GetWidth()
{
	return this->width;
}

std::uint16_t SFML_GameObject::GetHeight()
{
	return this->height;
}

sf::IntRect SFML_GameObject::GetSpriteIntRect()
{
	sf::IntRect rectangle(this->positionX, this->positionY, this->width, this->height);
	return rectangle;
}

bool SFML_GameObject::CheckSpriteColision(SFML_GameObject *gameObject)
{
	return this->GetSpriteIntRect().intersects(gameObject->GetSpriteIntRect());
}

bool SFML_GameObject::CheckSpriteColision(SFML_GameObject * gameObject, sf::IntRect * intersection)
{
	return this->GetSpriteIntRect().intersects(gameObject->GetSpriteIntRect(), *intersection);
}

SFML_GameObject::SFML_GameObject(std::int16_t positionX, std::int16_t positionY,
	std::uint16_t width, std::uint16_t height)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->width = width;
	this->height = height;
	this->originalWidth = 0;
	this->originalHeight = 0;
}

SFML_GameObject::SFML_GameObject(std::int16_t positionX, std::int16_t positionY)
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
