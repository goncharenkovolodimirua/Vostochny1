#ifndef __SFML_GameWindow__
#define __SFML_GameWindow__

#define TIME_BETW_GEN 900000
#define FPS_TIME 800
#define FONT_NAME "F.ttf"
#define GAME_NAME "VOSTOCHNY"
#define BACKGROUND_SOUNDNAME "m3.ogg"
#define ESC_PRESS_TIME 300000

#pragma warning(disable : 4996)

#include <string>
#include <SFML/Graphics.hpp>
#include"SFML/Audio.hpp"
#include <cstdlib>
#include <ctime>
#include <list>

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
class SFML_GameWindow
{
private:
	sf::RenderWindow* window;
	sf::Clock* clock;
	sf::Music* backgroundMusic;

	std::list<PhysicalGameObject*> bullets;
	std::list<PhysicalGameObject*> meteors;

	std::list<PhysicalGameObject*>::iterator meteorsIterator;
	std::list<PhysicalGameObject*>::iterator bulletsIterator;
	
	int windowWidth;
	int windowHeight;
	

	float deltaTime;
	float escPressedTime;

	bool started;
	GameStatements statement;
	GameStatements lastStatement;
	float timeBetweenGen = TIME_BETW_GEN;


	sf::Image meteorTexture;
	sf::Image shipTexture;
	sf::Image backgroundImage;
	sf::Image blackBackgroundImage;
	sf::Image bulletsTexture;
	sf::Font font;

	sf::Event event;


	PlayerShip* ship;
	Background* background;
	Background* blackBackground;

	SFML_TextGameObject* gameName;
	SFML_TextGameObject* looseScore;

	GameButton* startButton;
	GameButton* restartButton;
	GameButton* resumeButton;
	GameButton* mainMenuButton;
	GameButton* exitButton;

	SFML_ScoreCounterObject* score;


	void GenerateMeteors(float deltaTime);
	void CheckMeteorsWithBullets(float deltaTime);
	void CheckBulletsWithScreen(float deltaTime);
	void ClearLists();

	void GameFrame(float deltaTime);

	void Control(float deltaTime);

	void UploadTime();

	void InitializeButtons();

	void InitializeImages();

	void InitializePlayerShip();

	void InitializeTexts();

public:
	SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName);
	~SFML_GameWindow();
};
#endif