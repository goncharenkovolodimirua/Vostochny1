#ifndef __METEOR__
#define __METEOR__

#define METEOR_INITIAL_MAX_HEALTH 100
#define METEOR_NORMAL_MASS 100
#define METEOR_RELIFE_TIME 500

#include "PhysicalGameObject.h"

#include <list>
class Meteor :
	public PhysicalGameObject
{
private:
	std::list<PhysicalGameObject*>* meteors;

	float mass;
	int health;
	
	int relifeTime;


public:
	Meteor(int positionX, int positionY, int width,
		int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
		int widthInTexture, int heightInTexture, float Vx, float Vy,
		int boundXMin, int boundXMax, int boundYMin, int boundYMax, float mass, std::list<PhysicalGameObject*>* meteors);
	virtual ~Meteor();

	void SetMass(float mass);
	void SetHealth(int health);

	float GetMass();
	int GetHealth();

	void CheckColisionsWithBullets(std::list<PhysicalGameObject*>* bulletsList);

};
#endif


