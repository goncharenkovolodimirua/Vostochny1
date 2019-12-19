#ifndef __BACKGROUND__
#define __BACKGROUND__
#include "SFML_GraphicalGameObject.h"
class Background :
	public SFML_GraphicalGameObject
{
public:
	Background(std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
		sf::Image* textureImage,
		std::int16_t positionXInTexture,
		std::int16_t positionYInTexture,
		std::uint16_t widthInTexture,
		std::uint16_t heightInTexture);
	virtual ~Background();
};
#endif

