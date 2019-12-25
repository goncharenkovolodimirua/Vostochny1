/*!
* \file
* \brief Header file, which store declaration of PlayerShip class.
*/
#ifndef __PLAYER_SHIP__
#define __PLAYER_SHIP__

#define BULLET_TIMEOUT 10 //!<Minimal time interval betwen two shots
#define BULLET_COST 1000 //!<Cost of one bullet in points
#define BULLET_SPEED -0.8 //!<Speed of a bullet

#define MIN_ALPHA_VAL 10 //!<Minimal value of alpha chanel to check collisions

#include "SFML_GraphicalGameObject.h"
#include "PhysicalGameObject.h"
#include "Bullet.h"

#include <list>

/*!
* \brief Class, which represent Player ship
*
* This class store data about rectangle whwere user ship can fly 
* and allow to fly and shoot with control by keyboard
*/
class PlayerShip :
    public SFML_GraphicalGameObject
{
private: 
	std::int16_t controlWidthMin; //!< Minimal value of horizontal position where player ship can be
	std::int16_t controlWidthMax; //!< Maximal value of horizontal position where player ship can be 
	std::int16_t controlHeightMin; //!< Minimal value of vertical position where player ship can be
	std::int16_t controlHeightMax;  //!< Maximal value of vertical position where player ship can be

	std::uint16_t needToShot; //!< How much times should ship shoot at this moment
	float lastShotTime; //!< How long is time interval from last shoot

	bool lastSpaceStatement; //!< Last statement of space key (true==pressed, false=unpressed)

	std::list<PhysicalGameObject*>* bulletsList; //!<Reference to list, which store references on bullets objects

	sf::Image* bulletTexture; //!< Referense on sf::Image, which store bullet texture
	std::uint16_t bulletWidth; //!<Width of bullets
	std::uint16_t bulletHeight; //!<Height of bullets

	std::int16_t bulletBoundXMax; //!<Maximal horizontal coordinate in px, where bullet can be
	std::int16_t bulletBoundYMax; //!<Maximal vertical coordinate in px, where bullet can be
	std::int16_t bulletBoundXMin; //!<Minimal horizontal coordinate in px, where bullet can be
	std::int16_t bulletBoundYMin; //!<Minimal vertical coordinate in px, where bullet can be


protected:
	/*!
	* Shoot method. 
	*
	* Creates a bullet an add it to bullet list
	* 
	*/
	void Shoot(); 

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
	* \param[in] controlWidthMin Minimal value of horizontal position where player ship can be
	* \param[in] controlWidthMax Maximal value of horizontal position where player ship can be 
	* \param[in] cotrolHeightMin Minimal value of vertical position where player ship can be
	* \param[in] controlHeightMax Maximal value of vertical position where player ship can be
	* \param[in] bulletsList Reference to list, which store references on bullets objects
	*/
    PlayerShip(
		std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
        sf::Image* textureImage,
		std::int16_t positionXinTexture,
		std::int16_t positionYInTexture,
		std::uint16_t widthInTexture,
		std::uint16_t heightInTexture,
		std::int16_t controlWidthMin,
		std::int16_t controlWidthMax,
		std::int16_t cotrolHeightMin,
		std::int16_t controlHeightMax,
        std::list<PhysicalGameObject*>* bulletsList
    );

	/*!
	* Destructor
	*/
    virtual ~PlayerShip();
    
	/*!
	* Control method
	*
	* Implements control of player ship. Check left, right, 
	* up, down arow and space buttons press.
	*
	* On arrow keys press change position. On space button press
	* increments needToShot field.
	*
	* Every call method substract time from last call from lastShotTime field and
	* check is needToShot greater than 0. If it is
	* it means that there are some bullets in queune, then it check is lastShotTime field
	* less than 0, and if it is call shoot method. 
	*
	*\param[in] time Time interval from last check
	*/
    virtual void Control(float time);

	/*!
	* Check collisions with array of PhysicalGameObjects.
	*
	* \param[in] bulletsList Reference to list, which store references to meteors
	* \return Logical value, was there a collision (true) or not (false)
	*/
	virtual bool CheckCollisionsWithMeteors(std::list<PhysicalGameObject*>* meteors);

	/*!
	* Set bullet texture in bulletTexture field.
	*
	* \param[in] bulletTexture Reference to sf::Image, which store bullet texture
	*/
	virtual void SetBulletTextureImage(sf::Image* bulletTexture);
	/*!
	* Set maximal X value of bounds rectangle for bullet
	*
	* \param[in] bulletBoundXMax Maximal x value of bounds rectangle 
	to set into boundYMax field of bullet in px
	*/
	virtual void SetBulletBoundXMax(std::int16_t bulletBoundXMax);
	/*!
	* Set maximal Y value of bounds rectangle for bullet
	*
	* \param[in] bulletBoundYMax Maximal y value of bounds rectangle 
	to set into boundYMax field of bullet in px
	*/
	virtual void SetBulletBoundYMax(std::int16_t bulletBoundYMax);
	/*!
	* Set minimal X value of bounds rectangle for bullet
	*
	* \param[in] bulletBoundXMin Minimal x value of bounds rectangle 
	to set into boundXMin field of bullet in px
	*/
	virtual void SetBulletBoundXMin(std::int16_t bulletBoundXMin);
	/*!
	* Set minimal Y value of bounds rectangle for bullet
	*
	* \param[in] bulletBoundYMin Minimal y value of bounds rectangle 
	to set into boundYMin field of bullet in px
	*/
	virtual void SetBulletBoundYMin(std::int16_t bulletBoundYMin);

	/*!
	* Set bullet width to bulletWidth field
	*
	* \param[in] bulletWidth Width of bullet in px
	*/
	virtual void SetBulletWidth(std::uint16_t bulletWidth);
	/*!
	* Set bullet width to bulletHeight field
	*
	* \param[in] bulletHeight Height of bullet in px
	*/
	virtual void SetBulletHeight(std::uint16_t bulletHeight);
};
#endif
