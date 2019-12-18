#include "pch.h"
#include "Meteor.h"


Meteor::Meteor(int positionX, int positionY, int width,
	int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
	int widthInTexture, int heightInTexture, float Vx, float Vy,
	int boundXMin, int boundXMax, int boundYMin, int boundYMax, float mass):PhysicalGameObject(positionX, positionY, width,
		height, textureImage, positionXinTexture, positionYInTexture,
		 widthInTexture, heightInTexture, Vx, Vy,
		boundXMin, boundXMax, boundYMin, boundYMax)
{
	this->mass = mass;
	this->health = METEOR_INITIAL_MAX_HEALTH;
}


Meteor::~Meteor()
{
}

void Meteor::SetMass(float mass)
{
	this->mass = mass;
}

void Meteor::SetHealth(int health)
{
	this->health = health;
}

float Meteor::GetMass()
{
	return this->mass;
}

int Meteor::GetHealth()
{
	return this->health;
}
