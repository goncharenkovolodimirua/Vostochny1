#include "pch.h"
#include "Background.h"


Background::Background(std::int16_t positionX,
	std::int16_t positionY,
	std::uint16_t width,
	std::uint16_t height,
	sf::Image* textureImage,
	std::int16_t positionXInTexture,
	std::int16_t positionYInTexture,
	std::int16_t widthInTexture,
	std::int16_t heightInTexture):SFML_GraphicalGameObject(positionX,
		positionY,
		width,
		height,
		textureImage,
		positionXInTexture,
		positionYInTexture,
		widthInTexture,
		heightInTexture)
{
}


Background::~Background()
{
}
