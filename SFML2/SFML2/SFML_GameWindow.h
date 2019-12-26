/*!
* \file
* \brief Header file, whitch store declaration SFML_GameWindow class.
*/
#ifndef __SFML_GameWindow__
#define __SFML_GameWindow__

#define TIME_BETW_GEN 900000 //!< Minimal time between generation sets of meteors
#define FPS_TIME 800 //!< Value to devide time on it
#define FONT_NAME "F.ttf" //!< Font name
#define GAME_NAME "VOSTOCHNY" //!< Game name
#define BACKGROUND_SOUNDNAME "m3.ogg" //!< Name of background music
#define ESC_PRESS_TIME 300000 //!< Time between to esc presses to capture them as difrent presses

#pragma warning(disable : 4996) //Remove error "sf::Text::setColor declareted deprecate"


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <cstdlib>
#include <ctime>
#include <list>

#include "SFML_Window.h"
#include "Background.h"
#include "Meteor.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "PhysicalGameObject.h"
#include "SFML_TextGameObject.h"
#include "GameButton.h"
#include "CollisionTypes.h"
#include "GameStatements.h"
#include "SFML_ScoreCounterObject.h"
#include "HighScore.h"

/*!
* \brief Class with represent window with game.
*
* Class stored data about all needed for gameplay objects.
*
*/
class SFML_GameWindow: public SFML_Window
{
private:
	sf::Music* backgroundMusic; 

	std::list<PhysicalGameObject*> bullets; //!< Reference to list, which stores bullets
	std::list<PhysicalGameObject*> meteors; //!< Reference to list, which stores meteors

	std::list<PhysicalGameObject*>::iterator meteorsIterator; //!< Iterator for meteors
	std::list<PhysicalGameObject*>::iterator bulletsIterator; //!< Iterator fol bullets

	float deltaTime;  //!< Time interval from last game frame
	float escPressedTime;  //!< Time interval from last pressing esc button

	GameStatements statement;  //!< Current game statement
	GameStatements lastStatement;  //!< Last game statement
	float timeBetweenGen = TIME_BETW_GEN;  //!< Time interval from last generation of meteors set


	sf::Image meteorTexture;  //!<Reference to meteor texture
	sf::Image shipTexture; //!<Reference to ship texture
	sf::Image backgroundImage; //!<Reference to background texture
	sf::Image blackBackgroundImage; //!<Reference to half visible black rectangle texture
	sf::Image bulletsTexture; //!<Reference to bullets texture
	sf::Font font; //!<Reference to font texture

	PlayerShip* ship; //!<Reference to PlayerShip object
	Background* background; //!<Reference to Background object
	Background* blackBackground; //!<Reference to Background object with half visible black rectangle

	SFML_TextGameObject* gameName; //!<Reference to SFML_TextGameObject object with game name
	SFML_TextGameObject* looseScore; //!<Reference to SFML_TextGameObject object withgame score when player loosed

	GameButton* startButton; //!<Reference to GameButton object with start button
	GameButton* restartButton; //!<Reference to GameButton object with restart button
	GameButton* resumeButton; //!<Reference to GameButton object with resume button
	GameButton* mainMenuButton; //!<Reference to GameButton object with mainMenu button
	GameButton* exitButton; //!<Reference to GameButton object with exit button

	HighScore* higscore;

	SFML_ScoreCounterObject* score; //!<Reference to ScoreCounter object

	/*!
	* Generate set of uncollised metheors if time from last generation is
	* greater than TIME_BETW_GEN.
	*
	* \param[in] deltaTime Time interval from last call
	*
	*/
	void GenerateMeteors(float deltaTime);
	/*!
	* Move meteors, check collisions betwen evaery meteor an bullets,
	* distruct meteors if needed.
	*
	* \param[in] deltaTime Time interval from last call
	*
	*/
	void CheckMeteorsWithBullets(float deltaTime);
	/*!
	* Move bullets, check check is bullet inside the window,
	* distruct them if needed.
	*
	* \param[in] deltaTime Time interval from last call
	*
	*/
	void CheckBulletsWithScreen(float deltaTime);
	/*!
	* Remove all bullets and metheors from dynamic memory
	*
	*/
	void ClearLists();

	/*!
	* Generate current frame
	*
	* Check current game statement, call al methods for move objrcts, 
	* check buttons etc.
	*
	* \param[in] deltaTime Time interval from last call
	*
	*/
	void GameFrame(float deltaTime);
	/*!
	* Check keys pressed in game window (esc)
	*
	* \param[in] deltaTime Time interval from last call
	*
	*/
	void Control(float deltaTime);
	/*!
	* Load time from SFML clock to field and restart it
	*
	*/
	void UploadTime();

	/*!
	* Initialize all buttons needed for game
	*
	*/
	void InitializeButtons();
	/*!
	* Initialize all images needed for game with files
	*
	*/
	void InitializeImages();
	/*!
	* Initialize PlayerShip object
	*
	*/
	void InitializePlayerShip();
	/*!
	* Initialize all texts needed for game 
	*
	*/
	void InitializeTexts();
	/*!
	* Initialize background music with file
	*
	*/
	void InitializeBackgroundMusic();

public:
	/*!
	* Constructor
	* \param[in] windowWidth Window width in px
	* \param[in] windowHeight Window height in px
	* \param[in] windowName Window name
	* \param[in] style SFML window style
	*/
	SFML_GameWindow(std::uint16_t windowWidth, std::uint16_t windowHeight, std::string windowName, sf::Uint32 style);
	/*!
	* Destructor
	*/
	~SFML_GameWindow();
};
#endif