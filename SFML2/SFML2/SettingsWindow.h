/*!
* \file
* \brief Header file, whitch store declaration SettingsWindow class.
*/
#ifndef __SETTINGS_WINDOW__
#define __SETTINGS_WINDOW__

#define SETTINGS_FONTNAME "F.ttf" //!< Font file name

#include "SFML_Window.h"
#include "GameButton.h"

/*!
* \brief Class of window for set resolution of GameWindow.
*
*/
class SettingsWindow :
	public SFML_Window
{
private:
	virtual void Control(float deltaTime);
	
public:
	/*!
	* Constructor
	* \param[in] windowWidth Window width in px
	* \param[in] windowHeight Window height in px
	* \param[in] windowName Window name
	* \param[in] style SFML window style
	* \param[out] width Parameter for returning selected width in px
	* \param[out] height Parameter for returning selected height in px
	* \param[out] selected Parameter for returning was enything selected or not
	*/
	SettingsWindow(std::uint16_t windowWidth,
		std::uint16_t windowHeight,
		std::string windowName,
		sf::Uint32 style,
		std::int16_t* width,
		std::int16_t* height,
		bool* selected);
	/*!
	* Destructor
	*/
	virtual ~SettingsWindow();
};
#endif // !__SETTINGS_WINDOW__



