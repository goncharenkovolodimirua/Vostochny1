#include "pch.h"
#include "Meteor.h"

#include <iostream>

Meteor::Meteor(int positionX, int positionY, int width,
	int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
	int widthInTexture, int heightInTexture, float Vx, float Vy,
	int boundXMin, int boundXMax, int boundYMin, int boundYMax, float mass, 
	std::list<PhysicalGameObject*>* meteors):PhysicalGameObject(positionX, positionY, width,
		height, textureImage, positionXinTexture, positionYInTexture,
		 widthInTexture, heightInTexture, Vx, Vy,
		boundXMin, boundXMax, boundYMin, boundYMax)
{
	this->mass = mass;
	this->health = METEOR_INITIAL_MAX_HEALTH;
	this->meteors = meteors;
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

void Meteor::CheckColisionsWithBullets(std::list<PhysicalGameObject*> *bulletsList)
{
	std::list<PhysicalGameObject*>::iterator k = bulletsList->begin();
	for (k = bulletsList->begin(); k != bulletsList->end();) {
		if (this->health > 0) {
			if ((*k)->CheckColision(this)) {
				delete (*k);
				k=bulletsList->erase(k);
				this->health = this->health - (int(METEOR_NORMAL_MASS / this->mass*(METEOR_INITIAL_MAX_HEALTH / 2)));
			}
			else {
				++k;
			}
		}
		else {
			++k;
		}
	}
	if (this->health <= 0) {
		
	}
}
