#ifndef __SFML_GameWindow__
#define __SFML_GameWindow__

#define TIME_BETW_GEN 900000
#define FPS_TIME 800
#define FONT_NAME "F.ttf"
#define GAME_NAME "VOSTOCHNY"
#define ESC_PRESS_TIME 300000

#pragma warning(disable : 4996)

#include <string>
#include <SFML/Graphics.hpp>
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
class SFML_GameWindow
{
private:
	sf::RenderWindow* window;
	sf::Clock* clock;

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
	sf::Font font;

	sf::Event event;


	PlayerShip* ship;
	Background* background;
	Background* blackBackground;
	SFML_TextGameObject* gameName;

	GameButton* startButton;


	void GenerateMeteors(float deltaTime);
	void CheckMeteorsWithBullets(float deltaTime);
	void CheckBulletsWithScreen(float deltaTime);
	void ClearLabels();

	void GameFrame(float deltaTime);

	void Control(float deltaTime);

	void UploadTime();

public:
	SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName);
	~SFML_GameWindow();
};
#endif