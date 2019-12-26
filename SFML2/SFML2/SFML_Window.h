/*!
* \file
* \brief Header file, whitch store declaration SFML_Window class.
*/
#ifndef __WINDOW__
#define __WINDOW__

#include <SFML/Graphics.hpp>

#include <string>
#include <cstdint>

/*!
* \brief Class witch used to create windows in programm.
*
*/
class SFML_Window
{
private:
	std::uint16_t windowWidth; //!< Window width in px
	std::uint16_t windowHeight; //!< Window height in px
	std::string windowName; //!< Window name
	sf::Uint32 style; //!< SFML window style

	sf::RenderWindow* window; //!< SFML render window
	sf::Clock* clock; //!< SFML Clock
	
protected:
	sf::Event event; //!< SFML window Event

	/*!
	* Get RenderWindow address in memory
	*
	* \return RenderWindow address
	*
	*/
	virtual sf::RenderWindow* GetWindowAddress(); 

	/*!
	* Set window width in windowWidth field and resize window
	*
	* \param[in] windowWidth Window width in px
	*
	*/
	virtual void SetWindowWidth(std::uint16_t windowWidth);
	/*!
	* Set window height in windowHeight field and resize window
	*
	* \param[in] windowHeight Window height in px
	*
	*/
	virtual void SetWindowHeight(std::uint16_t windowHeight);

	/*!
	* Get time from SFML Clock
	*
	* \return Time interval from last restart
	*
	*/
	virtual float GetClockTime();
	/*!
	* Restart SFML Clock
	*
	*/
	virtual void RestartClock();

public:
	/*!
	* Constructor
	* \param[in] windowWidth Window width in px
	* \param[in] windowHeight Window height in px
	* \param[in] windowName Window name
	* \param[in] style SFML window style
	*/
	SFML_Window(std::uint16_t windowWidth, std::uint16_t windowHeight, std::string windowName, sf::Uint32 style);
	/*!
	* Destructor
	*/
	virtual ~SFML_Window();

	/*!
	* Function to communicate with all window elements
	*
	* \param[in] deltaTime Time interval from last check
	*
	*/
	virtual void Control(float deltaTime) = 0;
	
	/*!
	* Get window width from windowWidth field
	*
	* \return Window width in px
	*
	*/
	virtual std::uint16_t GetWindowWidth();
	/*!
	* Get window height from windowHeight field
	*
	* \return Window height in px
	*
	*/
	virtual std::uint16_t GetWindowHeight();
	
	/*!
	* Get SFML window style 
	*
	* \return Window style
	*
	*/
	virtual sf::Uint32 GetWindowStyle();
	/*!
	* Get window name 
	*
	* \return Window name
	*
	*/
	virtual std::string GetWindowName();

	/*!
	* Get name of a window
	*
	* \param[in] name Window name as Sting
	*
	*/
	virtual void SetWindowName(std::string name);

	/*!
	* Display things, what was set to draw on window
	*
	*/
	virtual void WindowDisplay();
	/*!
	* Clear window from things, what was set to draw on window
	*
	*/
	virtual void WindowClear();
	/*!
	* Close window
	*
	* After this operation window can be reopen
	*/
	virtual void WindowClose();
};

#endif // !__WINDOW__




