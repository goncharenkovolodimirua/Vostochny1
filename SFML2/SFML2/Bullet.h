#pragma once
#include "PhysicalGameObject.h"
class Bullet :
	public PhysicalGameObject
{
private:
	int cost;

public:
	Bullet(int positionX, int positionY, int width,
		int height, sf::Image* textureImage, int positionXinTexture, int positionYInTexture,
		int widthInTexture, int heightInTexture, float Vx, float Vy,
		int boundXMin, int boundXMax, int boundYMin, int boundYMax, int cost);
	virtual ~Bullet();

	void SetCost(int cost);
	int GetCost();
};

