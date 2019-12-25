/*!
* \file
* \brief Header file, which store declaration of Meteor class.
*/
#ifndef __METEOR__
#define __METEOR__

#define METEOR_INITIAL_NORMAL_HEALTH 100 //!< Initial health of meteor
#define METEOR_NORMAL_MASS 100 //!< Normal mass of meteor
#define METEOR_RELIFE_TIME 200 //!< Time interval when meteor is stel alive with 0 health
#define CRASHED_SIZE (this->GetBoundXMax()*0.125) //!< Minimal size of meteor to create new after destruction

#include <cstdlib>
#include <ctime>

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
	std::int16_t health;

	/*!
	* Field to store time intrval, when meteor is steal alive after become 0 health.
	* Used to display explosion texture.
	*/
	std::int16_t relifeTime;

	/*!
	* Field to store information was meteor destructed.
	* Used to call creation of metheros only once.
	*/
	bool distructed;
	
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
	Meteor(std::int16_t positionX,
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
	virtual void SetMass(float mass);

	/*!
	* Set health value into health field
	* \param[in] health Health of metheor to set in points
	*/
	virtual void SetHealth(std::int16_t health);

	/*!
	* Get mass value from mass field
	* \return Mass of metheor in points
	*/
	virtual float GetMass();

	/*!
	* Get health value from health field
	* \return Health of metheor in points
	*/
	virtual std::int16_t GetHealth();

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
	* \param[in] meteors Reference to list, which store references to meteors
	* \return Logical value, was there a collision (true) or not (false)
	*/
	virtual bool CheckCollisionsWithMetheors(std::list<PhysicalGameObject*>* meteors);

	/*!
	* Move a meteor. Now uses usual linear movement.
	*
	* \param[in] deltaT Time interval of movement
	*
	*/
	virtual void Move(float deltaT);
	virtual bool CheckCollisionWithList(std::list<PhysicalGameObject*>* physicalGameObjectList, CollisionTypes typeOfCollision);

	/*!
	* Generate metheors after meteor destruction.
	*
	* If metheor have enough size generates from to to 6 metheors
	* after meteor destruction.
	*
	*/
	virtual void GenerateMeteors();
};
#endif


