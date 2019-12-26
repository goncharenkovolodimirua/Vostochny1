/*!
* \file
* \brief Header file, which store declaration PhysicalGameObject class.
*/
#ifndef __PHYSICAL_GAME_OBJECT__
#define __PHYSICAL_GAME_OBJECT__
#include "SFML_GraphicalGameObject.h"

#include "CollisionTypes.h"

#include <list>
#include <cstdint>

/*!
* \brief Class with represent phisical object in game
*
* Class stored data about bounds where object can be, 
* its position in float coordinates and speed projections 
*
*/
class PhysicalGameObject :
	public SFML_GraphicalGameObject
{
private:
	float Vx;	//!<Horizontal speed projection
	float Vy;	//!<Vertical speed projection

	float globalPosX;	//!<X position in float coordinates
	float globalPosY;	//!<Y position in float coordinates
	
	std::int16_t boundXMin;	//!<Minimal X coordinate
	std::int16_t boundXMax;	//!<Maximum X coordinate
	std::int16_t boundYMin;	//!<Minimum Y coordinate
	std::int16_t boundYMax;	//!<Maximum Y cordinate

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
	* \param[in] Vx Horizontal speed (from left upper corner)
	* \param[in] Vy Vertical speed (from left upper corner)
	* \param[in] boundXMin Minimal X position in px
	* \param[in] boundXMax Maximal X position in px
	* \param[in] boundYMin Minimal Y position in px
	* \param[in] boundYMax Maximal Y position in px
	*/
	PhysicalGameObject(
		std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
		sf::Image* textureImage, 
		std::int16_t positionXinTexture,
		std::int16_t positionYInTexture,
		std::uint16_t widthInTexture,
		std::uint16_t heightInTexture,
		float Vx, 
		float Vy,
		std::int16_t boundXMin,
		std::int16_t boundXMax,
		std::int16_t boundYMin,
		std::int16_t boundYMax);

	/*!
	* Destructor
	*/
	virtual ~PhysicalGameObject();

	/*!
	* Linear move method
	*
	* Changed X and Y coordinates with princip of linear movement,
	* uses Vx and Vy as speed
	*
	* \param[in] deltaT Time interval of movement
	*/
	virtual void LinearMove(float deltaT);


	/*!
	* Check is an object in bounds rectangle
	*
	* Returns true when X position is between boundXMin and boundXMax and
	* Y position is between boundYMin and boundYMax
	*
	* \return Logical value is object upper left corner in bounds rectangle
	*/
	virtual bool IsInBounds();

	/*!
	* Set horizontal speed
	*
	* \param[in] Vx Horizontal speed
	*/
	virtual void SetVx(float Vx);

	/*!
	* Set horizontal speed
	*
	* \param[in] Vy Vertical speed
	*/
	virtual void SetVy(float Vy);

	/*!
	* Get horizontal speed
	*
	* \return Horizontal speed
	*/
	virtual float GetVx();

	/*!
	* Get vertical speed
	*
	* \return Vertical speed
	*/
	virtual float GetVy();


	/*!
	* Set minimal x value of bounds rectangle
	*
	* \param[in] boundXMin Minimal x value of bounds rectangle to set into boundXMin field
	*/
	virtual void SetBoundXMin(std::int16_t boundXMin);

	/*!
	* Set maximal x value of bounds rectangle
	*
	* \param[in] boundXMax MAximal x value of bounds rectangle to set into boundXMax field
	*/
	virtual void SetBoundXMax(std::int16_t boundXMax);

	/*!
	* Set minimal y value of bounds rectangle
	*
	* \param[in] boundYMin Minimal y value of bounds rectangle to set into boundYMin field
	*/
	virtual void SetboundYMin(std::int16_t boundYMin);

	/*!
	* Set maximal y value of bounds rectangle
	*
	* \param[in] boundYMax Maximal y value of bounds rectangle to set into boundYMax field
	*/
	virtual void SetBoundYMax(std::int16_t boundYMax);


	/*!
	* Get minimal x value of bounds rectangle
	*
	* \return Minimal x value of bounds rectangle, stored in boundXMin field
	*/
	virtual std::int16_t GetBoundXMin();

	/*!
	* Get maximal x value of bounds rectangle
	*
	* \return Maximal x value of bounds rectangle, stored in boundXMax field
	*/
	virtual std::int16_t GetBoundXMax();

	/*!
	* Get minimal y value of bounds rectangle
	*
	* \return Minimal y value of bounds rectangle, stored in boundYMin field
	*/
	virtual std::int16_t GetBoundYMin();

	/*!
	* Get maximal y value of bounds rectangle
	*
	* \return Maximal y value of bounds rectangle, stored in boundYMax field
	*/
	virtual std::int16_t GetBoundYMax();

	/*!
	* Check collision with every PhysicalGameObject in the list
	*
	* Type of check determined by typeOfObjects value.
	*
	* \param[in] physicalGameObjectList Pointer to list (declareted in list), which store pointers 
	*	to PhysicalGameObjects to check collision with
	* \param[in] typeOfObjects Type of check 
	*	
	* \return Logical value is there a collisions (true) or not (false) 
	*/
	virtual bool CheckCollisionWithList(std::list<PhysicalGameObject*>* physicalGameObjectList, CollisionTypes typeOfObjects) = 0;

	/*!
	* Check is an object in alive statement
	*
	* \param[in] time Time interval from last check
	*
	* \return Logical value is is an object alive (true) or not (false)
	*/
	virtual bool CheckAlive(float time)=0;

	/*!
	* Move an object
	*
	* Can be a movement with any princips
	*
	* \param[in] deltaT Time interval of movement
	*
	*/
	virtual void Move(float deltaT) = 0;
};
#endif