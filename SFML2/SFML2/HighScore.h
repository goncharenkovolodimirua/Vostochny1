/*!
* \file
* \brief Header file, which store declaration of HighScore class.
*/
#ifndef __HighScore__
#define __HighScore__

#define HIGHSCORE_FILENAME "hg.txt" //!<Name of file with heighscore

#include <fstream>
#include <cstdint>

#include "SFML_TextGameObject.h"


/*!
* \brief Class, which used to store best results
*
* This class work with binary file, where stored highscore.
*/
class HighScore :
	public SFML_TextGameObject
{
private:
	std::int32_t highscore; //!< Highscore
	std::ifstream fileIn; //!< Filestream to resd
	std::ofstream fileOut; //!< Filestream to write

public:
	/*!
	* Constructor whithout resizing
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] font Reference to sf::Font, which store font to use in label
	* \param[in] fontSize Size of font in px
	*/
	HighScore(std::int16_t positionX,
		std::int16_t positionY,
		sf::Font* font,
		std::uint16_t fontSize);
	/*!
	* Destructor
	*/
	virtual ~HighScore();

	/*!
	* Check new result, and save it if needed
	* \param[in] score New score to check
	*/
	virtual void NewScore(std::int32_t score);
};

#endif // !__HighScore__



