#ifndef __PHYSICAL_GAME_OBJECT__
#define __PHYSICAL_GAME_OBJECT__
#include "SFML_GraphicalGameObject.h"

#include <list>

class PhysicalGameObject :
	public SFML_GraphicalGameObject
{
private:
	float Vx;
	float Vy;

	float globalPosX;
	float globalPosY;

	int boundXMin;
	int boundXMax;
	int boundYMin;
	int boundYMax;

public:
	PhysicalGameObject(int positionX, int positionY, int width,
		int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
		int widthInTexture, int heightInTexture,float Vx, float Vy,
		int boundXMin,	int boundXMax, int boundYMin, int boundYMax);
	virtual ~PhysicalGameObject();

	void Move(float deltaT);
	bool IsInBounds();

	void SetVx(float Vx);
	void SetVy(float Vy);

	float GetVx();
	float GetVy();

	void SetBoundXMin(int boundXMin);
	void SetBoundXMax(int boundXMax);
	void SetboundYMin(int boundYMin);
	void SetBoundYMax(int boundYMax);

	int GetBoundXMin();
	int GetBoundXMax();
	int GetBoundYMin();
	int GetBoundYMax();

	

	virtual void CheckColisionsWithBullets(std::list<PhysicalGameObject*>* bulletsList)=0;
	virtual bool CheckAlive(float time)=0;

	virtual bool CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors)=0;
};
#endif