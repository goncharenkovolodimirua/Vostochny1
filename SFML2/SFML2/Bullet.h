/*!
* \file
* \brief Header file, which store declaration Bullet class.
*/
#ifndef BULLET
#define BULLET

#include "PhysicalGameObject.h"
#include "CollisionTypes.h"

/*!
* \brief Class, which represent Bullets
*
* This class store data about cost and ovner of a bullet.
*/
class Bullet :
	public PhysicalGameObject
{
private:
	/*!
	* Field to store bullet cost in points.
	*/
	std::int16_t cost;

	/*!
	* Field to store reference on object, which created bullet.
	*/
	SFML_GraphicalGameObject* ovner;

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
	* \param[in] cost Cost of bullet in points
	* \param[in] ovner Reference on object, which created bullet
	*/
	Bullet(std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
		sf::Image* textureImage, 
		std::int16_t positionXinTexture,
		std::int16_t positionYInTexture,
		std::int16_t widthInTexture,
		std::int16_t heightInTexture,
		float Vx, 
		float Vy,
		std::int16_t boundXMin,
		std::int16_t boundXMax,
		std::int16_t boundYMin,
		std::int16_t boundYMax,
		std::int16_t cost,
		SFML_GraphicalGameObject* ovner);

	/*!
	* Destructor
	*/
	virtual ~Bullet();

	/*!
	* Set bullet cost value into cost field
	* \param[in] cost Cost of a bullet to set in points
	*/
	void SetCost(std::int16_t cost);

	/*!
	* Get cost value from cost field
	* \return Cost of a bullet in points
	*/
	int GetCost();

	/*!
	* Check collisions with array of PhysicalGameObjects where stored bullets.
	*
	* This method called by CheckCollisionWithList method, when COLLISION_WITH_BULLET 
	* selected.
	*
	* \warning In this version always returns false.
	*
	* \param[in] bulletsList Reference to list, which store references to bullets
	* \return Logical value, was there a collision (true) or not (false)
	*/
	virtual bool CheckColisionsWithBullets(std::list<PhysicalGameObject*>* bulletsList);

	/*!
	* Check collisions with array of PhysicalGameObjects. This method called by 
	* CheckCollisionWithList method, when COLLISION_WITH_METEOR selected.
	*
	* \param[in] bulletsList Reference to list, which store references to meteors
	* \return Logical value, was there a collision (true) or not (false)
	*/
	virtual bool CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors);

	/*!
	* Check is this bullet alive. 
	* 
	* \warning In this version always returns true.
	*
	* \param[in] time Time interval from last check
	* \return Logical value, is a metheor alive (true) or not (false)
	*/
	virtual bool CheckAlive(float time);

	
	/*!
	* Move a bullet. Now uses usual linear movement.
	*
	* \param[in] bulletsList Time interval of movement
	*
	*/
	virtual void Move(float deltaT);

	virtual bool CheckCollisionWithList(std::list<PhysicalGameObject*>* physicalGameObjectList, CollisionTypes typeOfCollision);
};
#endif

