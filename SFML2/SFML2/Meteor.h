#ifndef __METEOR__
#define __METEOR__

#define METEOR_INITIAL_MAX_HEALTH 100

#include "PhysicalGameObject.h"

#include <list>
class Meteor :
	public PhysicalGameObject
{
private:
	std::list<SFML_GameObject*>* meteors;

	float mass;
	int health;

public:
	Meteor(int positionX, int positionY, int width,
		int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
		int widthInTexture, int heightInTexture, float Vx, float Vy,
		int boundXMin, int boundXMax, int boundYMin, int boundYMax, float mass, std::list<SFML_GameObject*>* meteors);
	virtual ~Meteor();

	void SetMass(float mass);
	void SetHealth(int health);

	float GetMass();
	int GetHealth();

};
#endif


