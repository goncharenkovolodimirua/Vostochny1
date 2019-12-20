#ifndef __SFML_GameWindow__
#define __SFML_GameWindow__

#define TIME_BETW_GEN 900000
#define FPS_TIME 800

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

	bool started;
	float timeBetweenGen = TIME_BETW_GEN;


	sf::Image meteorTexture;
	sf::Image shipTexture;
	sf::Image backgroundImage;

	sf::Event event;


	PlayerShip* ship;
	Background* background;


	void GenerateMeteors();
	void CheckMeteorsWithBullets();
	void CheckBulletsWithScreen();
	void ClearLabels();

public:
	SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName);
	~SFML_GameWindow();
};
#endif