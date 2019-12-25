/*!
* \file
* \brief Header file, which store declaration GameButton class.
*/
#ifndef __GAME_BUTTON__
#define __GAME_BUTTON__
#include "SFML_TextGameObject.h"

#include <cstdint>

/*!
* \brief Class with represent buttons in game.
*
*/
class GameButton :
	public SFML_TextGameObject
{
private:
	sf::RectangleShape* rectangle; //!< Background rectangle for button
	sf::RenderWindow *window; //!< Reference to window, where button is located

	std::int16_t offsetVertical; //!< Size in px how much larger is background than text in vertical demension
	std::int16_t offsetHorizontal;//!< Size in px how much larger is background than text in horizontal demension

	bool lastSatement; //!< Statemento of button in last check

	sf::Color noMouseFillColor; //!< Color of background when mouse isn't on the button
	sf::Color mouseOverFillColor; //!< Color of background when mouse is on the button
	sf::Color pressedFillColor; //!< Color of background when button is pressed

public:
	/*!
	* Constructor
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] font Font as sf::Font
	* \param[in] fontSize Size of font in px
	* \param[in] text Button text
	* \param[in] offsetVertical Size in px how much larger is background than text in vertical demension
	* \param[in] offsetHorizontal Size in px how much larger is background than text in horizontal demension
	*/
	GameButton(std::int16_t positionX, 
		std::int16_t positionY,
		sf::Font* font,
		std::uint16_t fontSize, 
		std::string text, 
		std::int16_t offsetVertical, 
		std::int16_t offsetHorizontal);

	/*!
	* Destructor
	*/
	virtual ~GameButton();

	virtual void DrawOnWindow(sf::RenderWindow *window);

	/*!
	* Set background color for situations, when there is no mouse on the button
	*
	* \param[in] color Color as sf::Color
	*
	*/
	void SetBackgroundColorNoMouse(sf::Color color);

	/*!
	* Set background color for situations, when there is mouse on the button
	*
	* \param[in] color Color as sf::Color
	*
	*/
	void SetBackgroundColorMouseOver(sf::Color color);
	/*!
	* Set background color for situations, when button is pressed
	*
	* \param[in] color Color as sf::Color
	*
	*/
	void SetBackgroundColorPressed(sf::Color color);


	/*!
	* Set position of button 
	*
	* \param[in] positionX Horizontal position in px
	* \param[in] positionY Vertical position in px
	*
	*/
	virtual void ChangeButtonPosition(int positionX, int positionY);
	virtual void Resize(std::uint16_t width, std::uint16_t height);

	/*!
	* Check was button pressed
	*
	* \return Logical value was button pressed and then unpressed. If it was - true,
	* else - false.
	*
	*/
	bool CheckButtonPressed();

};
#endif

