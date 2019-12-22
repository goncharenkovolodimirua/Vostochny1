/*!
* \file
* \brief Header file, which store declaration of Meteor class.
*/
#ifndef __METEOR__
#define __METEOR__

#define METEOR_INITIAL_NORMAL_HEALTH 100 //!< Initial health of meteor
#define METEOR_NORMAL_MASS 100 //!< Normal mass of meteor
#define METEOR_RELIFE_TIME 200 //!< Time interval when meteor is stel alive with 0 health

#include "PhysicalGameObject.h"
#include "CollisionTypes.h"

#include <list>

/*!
* \brief Class, which represent Meteors
*
* This class store data about Meteors mass, health and relifetime
*/
class Meteor :
	public PhysicalGameObject
{
private:
	/*!
	* Reference to list of references on PhysicalGameObjects, where are Meteors stored,
	*to create new, when distructed, if needed.
	*/
	std::list<PhysicalGameObject*>* meteors;

	/*!
	* Field to store metheor mass.
	*/
	float mass;

	/*!
	* Field to store metheor health.
	*/
	int health;

	/*!
	* Field to store time intrval, when meteor is steal alive after become 0 health.
	* Used to display explosion texture.
	*/
	int relifeTime;
	
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
	* \param[in] mass Mass of metheor in points
	* \param[in] meteors Reference to list of references on meteors
	*/
	Meteor(int positionX, 
		int positionY, 
		int width,
		int height, 
		sf::Image* textureImage, 
		int positionXinTexture, 
		int positionYInTexture,
		int widthInTexture, 
		int heightInTexture, 
		float Vx, 
		float Vy,
		int boundXMin, 
		int boundXMax, 
		int boundYMin, 
		int boundYMax, 
		float mass, 
		std::list<PhysicalGameObject*>* meteors);

	/*!
	* Destructor
	*/
	virtual ~Meteor();

	/*!
	* Set mass value into mass field
	* \param[in] mass Mass of metheor to set in points
	*/
	void SetMass(float mass);

	/*!
	* Set health value into health field
	* \param[in] mass Health of metheor to set in points
	*/
	void SetHealth(int health);

	/*!
	* Get mass value from mass field
	* \return Mass of metheor in points
	*/
	float GetMass();

	/*!
	* Get health value from health field
	* \return Health of metheor in points
	*/
	virtual int GetHealth();

	/*!
	* Check collisions with array of PhysicalGameObjects. If detect collision 
	* substract health of metheor and delete collised bullet.
	*
	* \param[in] bulletsList Reference to list, which store references to bullets
	* \return Logical value, was there a collision (true) or not (false)
	*/
	virtual bool CheckColisionsWithBullets(std::list<PhysicalGameObject*>* bulletsList);

	/*!
	* Check is this metheor alive. Metheor is alive when its health is greater
	* then 0, or its lifetime is greater than 0, else it's not.
	*
	* \param[in] time Time interval from last check
	* \return Logical value, is a metheor alive (true) or not (false)
	*/
	virtual bool CheckAlive(float time);

	/*!
	* Check collisions with array of PhysicalGameObjects. 
	* 
	* \warning In this version always returns false.
	*
	* \param[in] bulletsList Reference to list, which store references to meteors
	* \return Logical value, was there a collision (true) or not (false)
	*/
	virtual bool CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors);

	/*!
	* Move a meteor. Now uses usual linear movement.
	*
	* \param[in] bulletsList Time interval of movement
	*
	*/
	virtual void Move(float deltaT);
	virtual bool CheckCollisionWithList(std::list<PhysicalGameObject*>* physicalGameObjectList, CollisionTypes typeOfCollision);

};
#endif


