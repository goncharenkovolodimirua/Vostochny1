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
	this->health = METEOR_INITIAL_NORMAL_HEALTH;
	this->meteors = meteors;
	this->relifeTime = METEOR_RELIFE_TIME;
	this->distructed = false;
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

bool Meteor::CheckColisionsWithBullets(std::list<PhysicalGameObject*> *bulletsList)
{
	std::list<PhysicalGameObject*>::iterator k;
	bool collision = false;

	for (k = bulletsList->begin(); k != bulletsList->end();) {
		if (this->health > 0) {
			if ((*k)->CheckSpriteColision(this)) {
				delete (*k);
				k=bulletsList->erase(k);
				this->health = this->health - (int(METEOR_NORMAL_MASS / this->mass*(METEOR_INITIAL_NORMAL_HEALTH / 2)));
				collision = true;
			}
			else {
				++k;
			}
		}
		else {
			++k;
		}
	}
	if ((this->health <= 0) and (!this->distructed)) {
		this->distructed = true;
		this->ChangeTextureRectangle(this->GetOriginalWidth(), 0, this->GetOriginalWidth(), this->GetOriginalHeight());
		if (this->GetWidth() >= CRASHED_SIZE) {
			this->GenerateMeteors();
		}
		
	}
	return collision;
}

bool Meteor::CheckAlive(float time)
{
	if (this->health > 0) {
		return true;
	}
	else {
		if (this->relifeTime > 0) {
			this->relifeTime -= time;
			return true;
		}
		else{
			return false;
		}
	}
}

bool Meteor::CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors)
{
	std::list<PhysicalGameObject*>::iterator k;
	bool collision = false;

	for (k = meteors->begin(); k != meteors->end();) {
		if (this->health > 0) {
			if ((*k) != this) {
				if ((*k)->CheckSpriteColision(this)) {
					collision = true;
					++k;
				}
				else {
					++k;
				}
			}
			else {
				++k;
			}
		}
		else {
			++k;
		}
	}
	return collision;
}

void Meteor::Move(float deltaT)
{
	this->LinearMove(deltaT);
}

bool Meteor::CheckCollisionWithList(std::list<PhysicalGameObject*>* physicalGameObjectList, CollisionTypes typeOfCollision)
{
	switch (typeOfCollision)
	{
	case COLLISION_WITH_METEOR:
		return this->CheckCollisionsWithMetheors(physicalGameObjectList);
		break;
	case COLLISION_WITH_BULLET:
		return this->CheckColisionsWithBullets(physicalGameObjectList);
		break;
	default:
		return false;
		break;
	}
	
}

void Meteor::GenerateMeteors()
{
	Meteor* dinamicMeteor = nullptr;

	int localMeteorPositionX;
	int localMeteorPositionY;
	int localMeteorWidth;
	float localMeteorVx;
	float localMeteorVy;
	float localMeteorMass;

	int quantity;

	srand(time(NULL));

	quantity = 2 + rand() % 4;
	
	localMeteorPositionX = this->GetPositionX();
	localMeteorPositionY = this->GetPositionY();
	localMeteorMass = this->GetMass() / 3;


  	for (int i = 0; i < quantity; i++)
	{
		
		localMeteorWidth = int((this->GetWidth() / quantity) + rand() % (5 * (this->GetWidth() / 100)));
		localMeteorVx = -0.5 + (0.01 * (rand() % 101));
		localMeteorVy = -0.5 + (0.01 * (rand() % 101));

		dinamicMeteor = new Meteor(localMeteorPositionX, localMeteorPositionY,
			localMeteorWidth, localMeteorWidth, this->GetTextureAddress(), 0, 0,
			int(this->GetTextureAddress()->getSize().x / 2), int(this->GetTextureAddress()->getSize().y),
			localMeteorVx, localMeteorVy, this->GetBoundXMin(), this->GetBoundXMax(), this->GetBoundYMin(),
			this->GetBoundYMax(), localMeteorMass, this->meteors);

		this->meteors->push_back(dinamicMeteor);

		dinamicMeteor = nullptr;
	}
}
