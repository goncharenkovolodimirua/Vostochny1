/*!
* \file
* \brief Header file, which store declaration SFML_GameObject class.
*/

#ifndef __SFML_GAMEOBJECT__
#define __SFML_GAMEOBJECT__

#include "SFML/Graphics.hpp"
#include <cstdint>

/*!
*	\brief Abstract class, which define main entity of game structure 
*
*	Class holds only geometrical parameters.
*	
*	int16_t positionX;
*	int16_t positionY;
*	uint16_t width;
*	uint16_t height;
*	uint16_t originalWidth;
*	uint16_t originalHeight;
*	
*/

class SFML_GameObject
{
private:
	int16_t positionX; //! Variable to store X position
	int16_t positionY; //! Variable to store Y position
	uint16_t width; //! Variable to store Width with some scale
	uint16_t height;//! Variable to store Height with some scale
	uint16_t originalWidth;//! Variable to store Width with scalse=1
	uint16_t originalHeight;//! Variable to store Height with scalse=1


protected:
	/*!
	* Set parameter positinX
	* \param[in] positionX Position X to set in parameter
	*/
	void SetPositionX(int16_t positionX);

	/*!
	* Set parameter positinY
	* \param[in] positionY Position Y to set in parameter
	*/
	void SetPositionY(int16_t positionY);
	
	/*!
	* Set parameter width
	* \param[in] width Width to set in parameter
	*/
	void SetWidth(uint16_t width);

	/*!
	* Set parameter height
	* \param[in] height Height to set in parameter
	*/
	void SetHeight(uint16_t height);

	/*!
	* Set parameter originalWidth
	* \param[in] originalWidth Width in px with scale 0 to set in parameter
	*/
	void SetOriginalWidth(uint16_t originalWidth);

	/*!
	* Set parameter originalHeight
	* \param[in] originalHeight Height in px with scale 0 to set in parameter
	*/
	void SetOriginalHeight(uint16_t originalHeight);

	/*!
	* Get parameter originalWidth
	* \return Width in px with scale 0, that is value of parameter originalWidth
	*/
	uint16_t GetOriginalWidth();

	/*!
	* Get parameter originalHeight
	* \return Height in px with scale 0, that is value of parameter originalHeight
	*/
	uint16_t GetOriginalHeight();


public:
	/*!
	* Get parameter positionX
	* \return PositionX in px
	*/
	int16_t GetPositionX();

	/*!
	* Get parameter positionY
	* \return PositionY in px
	*/
	int16_t GetPositionY();

	/*!
	* Get parameter Width
	* \return Width in px
	*/
	uint16_t GetWidth();

	/*!
	* Get parameter Height
	* \return Height in px
	*/
	uint16_t GetHeight();

	/*!
	* Constructor
	* \param[in] positionX X position to set in parameter
	* \param[in] positionY Y position to set in parameter
	* \param[in] width Width to set in parameter
	* \param[in] height Height to set in parameter
	*/
	SFML_GameObject(int16_t positionX, int16_t positionY, uint16_t width, uint16_t height);

	/*!
	* Constructor
	* \param[in] positionX X position to set in parameter
	* \param[in] positionY Y position to set in parameter
	*/
	SFML_GameObject(int16_t positionX, int16_t positionY);
	
	/*!
	* Destructor
	*/
	virtual ~SFML_GameObject();

	/*!
	* Get rectangle, where object is located
	* \return sf::IntRext (defenition in SFML_Graphics.hpp), which stores object position
	*/
	virtual sf::IntRect GetSpriteIntRect();

	/*!
	* Check is there collision between rectangles of objects
	* \param[in] *gameObject Reference to gameObject to check collision with
	* \return Logical wariable. True when one object IntRect overlays another object ones
	*/
	virtual bool CheckSpriteColision(SFML_GameObject *gameObject);

	/*!
	* Check is there collision between rectangles of objects
	* \param[in] *gameObject Reference to gameObject to check collision with
	* \param[out] sf::IntRect Reference to return collision area as rectangle
	* \return Logical wariable. True when one object IntRect overlays another object ones
	*/
	virtual bool CheckSpriteColision(SFML_GameObject *gameObject, sf::IntRect *intersection);

	/*!
	* Draw object on sf::Renderwindow
	* \param[in] *window Reference to sf::RenderWindow to draw on it
	*/
	virtual void DrawOnWindow(sf::RenderWindow *window) = 0;

	/*!
	* Resize object with scale to given size and set them into fields
	* \param[in] width Width in px to resize
	* \param[in] height Height in px to resize
	*/
	virtual void Resize(uint16_t width, uint16_t height) = 0;

	/*!
	* Resize object to scale=1 and sets its new width an height
	*/
	virtual void ResizeDefault()=0;
};
#endif

