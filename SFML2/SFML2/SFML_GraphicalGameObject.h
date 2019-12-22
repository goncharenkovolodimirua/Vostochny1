/*!
* \file
* \brief Header file, which store declaration SFML_GraphicalGameObject class.
*/
#ifndef __SFML_GRAPHICALGAMEOBJECT__
#define __SFML_GRAPHICALGAMEOBJECT__

#include "SFML_GameObject.h"
#include <cstdint>

/*!
* \brief Class with represent graphical object in game/
*
* Class stored data about texture and rectangle in it, sprite and its scale 
*
*/
class SFML_GraphicalGameObject :
    public SFML_GameObject
{
private:
	/*!
	* Horizontal position of rectangle in texture.
	*/
    std::int16_t positionXInTexture;
	/*!
	* Vertical position of rectangle in texture.
	*/
    std::int16_t positionYInTexture;


	/*!
	* Reference to image, witch stored texture.
	*/
    sf::Image* textureImage;
	/*!
	* Reference to sf::Texture, which stored texture.
	*/
    sf::Texture* texture;
	/*!
	* Reference to sf::Sprite, which stored sprite.
	*/
    sf::Sprite* sprite;


	/*!
	* Horizontal sprite scale.
	*/
	double scaleX;
	/*!
	* Vertical sprite scale.
	*/
	double scaleY;

protected:
	/*!
	* Get reference to sprite.
	* \return Reference to sprite of object.
	*/
    sf::Sprite* GetSpriteAddress();
	/*!
	* Get reference to image with texture.
	* \return Reference to to image with texture of object.
	*/
	sf::Image* GetTextureAddress();
	
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
    SFML_GraphicalGameObject(
        std::int16_t positionX,
        std::int16_t positionY,
        std::uint16_t width,
        std::uint16_t height, 
        sf::Image* textureImage,
        std::int16_t positionXInTexture,
        std::int16_t positionYInTexture,
        std::uint16_t widthInTexture,
        std::uint16_t heightInTexture
    );
	/*!
	* Destructor
	*/
    virtual ~SFML_GraphicalGameObject();

	/*!
	* Set position of an object
	*
	* \param[in] x Position X in px
	* \param[in] y Position y in px
	*/
    virtual void SetPosition(
        std::int16_t x, 
        std::int16_t y
    );

	/*!
	* Get horizontal scale of a sprite
	*
	* \return Horizontal scale of a sprite
	*/
	virtual double GetScaleX();
	/*!
	* Get vertical scale of a sprite
	*
	* \return Vertical scale of a sprite
	*/
	virtual double GetScaleY();

	/*!
	* Get sf::IntRect with rectangle of sprite in a texture
	*
	* \return Rectangle of sprite in a texture
	*/
	virtual sf::IntRect GetTextureRect();
	/*!
	* Get copy of an image in dynamic memory
	*
	* \return Reference on copy of an texture image
	*/
	virtual sf::Image* GetTextureCopy();

	/*!
	* Get color of a pixel by its local coordinates
	*
	* \warning Very slow for massive use
	*
	* \param[in] positionX Horizontal coordinate of pixel from top left corner of Sprite
	* \param[in] positionY Vertical coordinate of pixel from top left corner of Sprite
	*
	* \return Color of an image pixel as sf::Color
	*/
	virtual sf::Color GetPxColorLocal(int positionX, int positionY);
	/*!
	* Get color of a pixel by its global coordinates
	*
	* Calls GetPxColorLocal.
	*
	* \warning Very slow for massive use
	*
	* \param[in] positionX Horizontal coordinate of pixel from top left corner of window with sprite
	* \param[in] positionY Vertical coordinate of pixel from top left corner of window with sprite
	*
	* \return Color of an image pixel as sf::Color
	*/
	virtual sf::Color GetPxColorGlobal(int positionX, int positionY);


	/*!
	* Check collision betwen objects by pixels
	*
	* Doesn't calls GetPxColorLocal, GetPxColorGlobal speed reasons.
	*
	* \warning Slow
	*
	* \param[in] graphicalGameObject Reference to object check collision with
	* \param[in] alphaChanelMinValue Minimal value of alpha chanel in places where there is a part of texture to collision
	*
	* \return Logical value is there a collision (true), or not (false)
	*/
	virtual bool CheckPxCollision(SFML_GraphicalGameObject* graphicalGameObject, int alphaChanelMinValue);	


	/*!
	* Resize sprite with scale 
	*
	* \param[in] width Width to resize in px
	* \param[in] height Height to resize in px
	*
	*/
    virtual void Resize(
        std::uint16_t width,
        std::uint16_t height
    );
    
    virtual void ResizeDefault();

	/*!
	* Change part in texture which show on  sprite
	*
	* \param[in] positionXInTexture Horizontal position of rectangle top left corner
	* \param[in] positionYInTexture Vertical position of rectangle top left corner
	* \param[in] widthInTexture Width of rectangle
	* \param[in] heightInTexture Height of rectangle
	*
	*/
    virtual void ChangeTextureRectangle(
        std::int16_t positionXInTexture, 
        std::int16_t positionYInTexture, 
        std::uint16_t widthInTexture, 
        std::uint16_t heightInTexture
    );

    virtual void DrawOnWindow(sf::RenderWindow *window);

	/*!
	* Convert horizontal position in sprite in horizontal position in texture
	*
	* For convertation use scale parameters.
	*
	* \param[in] positionX Horizontal position in sprite
	* 
	* \return Appropriate position in texture
	*
	*/
	virtual int localXPositionToPositionInTexture(int positionX);
	/*!
	* Convert vertical position in sprite in vertical position in texture
	*
	* For convertation use scale parameters.
	*
	* \param[in] positionY Vertical position in sprite
	*
	* \return Appropriate position in texture
	*
	*/
	virtual int localYPositionToPositionInTexture(int positionY);


	/*!
	* Convert horizontal position in window in horizontal position in sprite
	*
	* \param[in] positionX Horizontal position in window
	*
	* \return Appropriate position in sprite
	*
	*/
	virtual int GlobalXPositionToLocalPosition(int positionX);
	/*!
	* Convert vertical position in window in vertical position in sprite
	*
	* \param[in] positionY Vertical position in window
	*
	* \return Appropriate position in sprite
	*
	*/
	virtual int GlobalYPositionToLocalPosition(int positionY);

	/*!
	* Convert horizontal position in window in horizontal position in texture
	*
	* \param[in] positionX Horizontal position in window
	*
	* \return Appropriate position in texture
	*
	*/
	virtual int GlobalXPositionToPositionInTexture(int positionX);
	/*!
	* Convert vertical position in window in vertical position in texture
	*
	* \param[in] positionY Vertical position in window
	*
	* \return Appropriate position in texture
	*
	*/
	virtual int GlobalYPositionToPositionInTexture(int positionY);

};
#endif

