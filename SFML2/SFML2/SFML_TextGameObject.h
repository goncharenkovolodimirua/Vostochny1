/*!
* \file
* \brief Header file, which store declaration SFML_TextGameObject class.
*/
#ifndef __SFML_TextGameObject__
#define __SFML_TextGameObject__

#include "SFML_GameObject.h"
#include <string>

#include <cstdint>

#pragma warning(disable : 4996) //Remove error "sf::Text::setColor declareted deprecate"

/*!
* \brief Class with represent phisical text in game
*
* Class stored data about font, it size, and text value.
*
*/
class SFML_TextGameObject :
	public SFML_GameObject
{
private:
	sf::Font* SFMLFont; //!< Reference to sf::Font, which store font to use in label
	std::uint16_t fontSize; //!< Size of font in px
	sf::Text* SFMLText; //!< Reference to sf::Text, to output text on RenderWindo
	std::string text; //!<Value of string to output

protected:
	/*!
	* Get reference on sf::Text, which stored in SFMLText variable
	*
	* \return Reference on sf::Text, which stored in SFMLText variable
	*/
	sf::Text* GetSFMLText();


public:
	/*!
	* Constructor with resizing
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] width Width in px
	* \param[in] height Height in px
	* \param[in] font Reference to sf::Font, which store font to use in label
	* \param[in] fontSize Size of font in px
	*/
	SFML_TextGameObject(std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
		sf::Font* font,
		std::uint16_t fontSize);
	/*!
	* Constructor with resizing
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] width Width in px
	* \param[in] height Height in px
	* \param[in] font Reference to sf::Font, which store font to use in label
	* \param[in] fontSize Size of font in px
	* \param[in] text Value of string to output
	*/
	SFML_TextGameObject(std::int16_t positionX,
		std::int16_t positionY,
		std::uint16_t width,
		std::uint16_t height,
		sf::Font* font,
		std::uint16_t fontSize,
		std::string text);

	/*!
	* Constructor whithout resizing
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] font Reference to sf::Font, which store font to use in label
	* \param[in] fontSize Size of font in px
	*/
	SFML_TextGameObject(std::int16_t positionX,
		std::int16_t positionY,
		sf::Font* font,
		std::uint16_t fontSize);
	/*!
	* Constructor whithout resizing
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] font Reference to sf::Font, which store font to use in label
	* \param[in] fontSize Size of font in px
	* \param[in] text Value of string to output
	*/
	SFML_TextGameObject(std::int16_t positionX,
		std::int16_t positionY,
		sf::Font* font,
		std::uint16_t fontSize,
		std::string text);
	
	/*!
	* Destructor
	*/
	virtual ~SFML_TextGameObject();

	/*!
	* Set font reference into SFMLFont field to use in label
	*
	* \param[in] font Reference to sf::Font, which store font to use in label
	*/
	virtual void SetFont(sf::Font * font);
	/*!
	* Set font size 
	*
	* \param[in] fontSize Size of font in px
	*/
	void SetFontSize(std::uint16_t fontSize);
	/*!
	* Set text string
	*
	* \param[in] text String to set in text field
	*/
	virtual void SetText(std::string text);
	/*!
	* Set position of top left corner of text
	*
	* \param[in] positionX Horizontal position
	* \param[in] positionY Vertical position
	*/
	void SetTextPosition(std::int16_t positionX, std::int16_t positionY);

	/*!
	* Set color of text
	*
	* \param[in] color Color as sf::Color
	*/
	virtual void SetTextColor(sf::Color color);

	/*!
	* Get font size in px
	*
	* \return Font size in px
	*/
	std::uint16_t GetFontSize();
	/*!
	* Get string vith curen label text value
	*
	* \return String with curren text value
	*/
	virtual std::string GetText();

	virtual void ResizeDefault();
	virtual void Resize(std::uint16_t width, std::uint16_t height);

	virtual void DrawOnWindow(sf::RenderWindow *window);
};
#endif