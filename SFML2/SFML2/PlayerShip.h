#ifndef __PLAYER_SHIP__
#define __PLAYER_SHIP__

#define BULLET_TIMEOUT 10
#define BULLET_COST 1000
#define BULLET_SPEED -0.8

#define MIN_ALPHA_VAL 10

#include "SFML_GraphicalGameObject.h"
#include "PhysicalGameObject.h"
#include "Bullet.h"

#include <list>

class PlayerShip :
    public SFML_GraphicalGameObject
{
private:
    int controlWidthMin;
    int controlWidthMax;
    int controlHeightMin;
    int controlHeightMax;

	int needToShot;
	float lastShotTime;

	bool lastSpaceStatement;

	std::list<PhysicalGameObject*>* bulletsList;

	sf::Image* bulletTexture;
	int bulletWidth;
	int bulletHeight;

	int bulletBoundXMax;
	int bulletBoundYMax;
	int bulletBoundXMin;
	int bulletBoundYMin;


protected:
	void Shoot();

public:
    PlayerShip(
        int positionX,
        int positionY,
        int width,
        int height,
        sf::Image* textureImage,
        int positionXinTexture,
        int positionYInTexture,
        int widthInTexture,
        int heightInTexture,
        int controlWidthMin,
        int controlWidthMax,
        int cotrolHeightMin,
        int controlHeightMax,
        std::list<PhysicalGameObject*>* bulletsList
    );
    ~PlayerShip();
        
    void Control(float time);

	bool CheckCollisionsWithMeteors(std::list<PhysicalGameObject*>* meteors);

	void SetBulletTextureImage(sf::Image* bulletTexture);
	void SetBulletBoundXMax(int bulletBoundXMax);
	void SetBulletBoundYMax(int bulletBoundYMax);
	void SetBulletBoundXMin(int bulletBoundXMin);
	void SetBulletBoundYMin(int bulletBoundYMin);

	void SetBulletWidth(int bulletWidth);
	void SetBulletHeight(int bulletHeight);

};
#endif
