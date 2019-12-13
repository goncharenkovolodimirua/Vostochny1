#ifndef __SFML_GAMEOBJECT__
#define __SFML_GAMEOBJECT__

#include "SFML/Graphics.hpp"

class SFML_GameObject
{
private:
	int positionX;
	int positionY;
	int width;
	int height;
	int originalWidth;
	int originalHeight;


protected:



public:
	
	SFML_GameObject(int positionX, int positionY, int width, int height);
	
};
#endif

