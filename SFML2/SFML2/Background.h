/*!
* \file
* \brief Header file, which store declaration of Background class.
*/#ifndef __BACKGROUND__
#define __BACKGROUND__
#include "SFML_GraphicalGameObject.h"

/*!
* \brief Class, which represent Background
*/
class Background :
	public SFML_GraphicalGameObject
{
public:
	/*!
	* Constructor
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] width Width in px
	* \param[in] height Height in px
	* \param[in] textureImage Reference to sf::Image with texture
	* \param[in] positionXinTexture Position of left upper corner of square in texture
	* \param[in] positionYInTexture Position of right upper corner of square in texture
	* \param[in] widthInTexture Width of square in texture. Sets into originalWidth field
	* \param[in] heightInTexture Height of square in texture. Sets into originalHeight field
	*/
	Background(std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
		sf::Image* textureImage,
		std::int16_t positionXInTexture,
		std::int16_t positionYInTexture,
		std::uint16_t widthInTexture,
		std::uint16_t heightInTexture);

	/*!
	* Destructor
	*/
	virtual ~Background();
};
#endif

