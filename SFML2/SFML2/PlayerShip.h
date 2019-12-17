#ifndef __PLAYER_SHIP__
#define __PLAYER_SHIP__
#include "SFML_GraphicalGameObject.h"
#include <list>
class PlayerShip :
    public SFML_GraphicalGameObject
{
private:
    int controlWidthMin;
    int controlWidthMax;
    int controlHeightMin;
    int controlHeightMax;

	std::list<SFML_GameObject*>* bulletsList;

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
        std::list<SFML_GameObject*>* bulletsList
    );
    ~PlayerShip();
        
    void Control(float time);
};
#endif