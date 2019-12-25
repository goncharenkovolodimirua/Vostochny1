/*!
* \file
* \brief Header file, which store declaration SFML_ScoreCounterObject class.
*/
#ifndef __SFML_ScoreCounterObject__
#define __SFML_ScoreCounterObject__

#define TIME_COEF 100 //!< Coefficient of coefficient growth over time
#define MAX_COEF 0.0001 //!< Max coefficient after which the coefficient does not increase

#include "SFML_TextGameObject.h"
#include <string>
#include <cstdint>

#pragma warning(disable : 4996) //Remove error "sf::Text::setColor declareted deprecate"

/*!
* \brief Class, which represent Score
*
* This class store data about score, score growth rate coefficient
*/
class SFML_ScoreCounterObject :
	public SFML_TextGameObject
{
private:
	float coef; //!< Score growth rate coefficient
	std::int16_t score; //!< Game score

public:
	/*!
	* Constructor
	* \param[in] positionX X coordinate in px
	* \param[in] positionY Y coordinate in px
	* \param[in] font Reference to sf::Font, which store font to use in label
	* \param[in] fontSize Value of string to output
	*/
	SFML_ScoreCounterObject(std::int16_t positionX,
		std::int16_t positionY,
		sf::Font* font,
		std::uint16_t fontSize);

	/*!
	* Destructor
	*/
	virtual ~SFML_ScoreCounterObject();

	/*!
	* Change coef by formula coef = coef + TIME_COEF * deltaTime and enlarge score with formula score = score + deltaTime * coef 
	*
	* \param[in] deltaTime TimeInterval as microseconds
	*/
	virtual void AddWithTime(float deltaTime);
	
	/*!
	* Enlarge score with formula score += score and changing text
	*
	* \param[in] score Score in point
	*/
	virtual void AddWithNumber(std::int16_t score);

	/*!
	* Enlarge score with formula score -= score and changing text
	*
	* \param[in] score Score in point
	*/
	virtual void SubstractWithNumber(std::int16_t score);

	/*!
	* Set score into field score
	*
	* \param[in] score Score in point
	*/
	virtual void SetScore(std::int16_t score);

	/*!
	* Set coef into field coef
	*
	* \param[in] coef Coefficient which used to transform time interval into score enlargement
	*/
	virtual void SetCoef(float coef);
	
	/*!
	* Get score from field score
	*
	* \return Score in points
	*/
	virtual std::int16_t GetScore();

	/*!
	* Get coef from field coef
	*
	* \return Coefficient which used to transform time interval into score enlargement
	*/
	virtual float GetCoef();
};
#endif