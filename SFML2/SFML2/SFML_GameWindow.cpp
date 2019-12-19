#include "pch.h"
#include "SFML_GameWindow.h"

#include "PlayerShip.h"

#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include "SFML_GameObject.h"
#include "SFML_GraphicalGameObject.h"
#include "PhysicalGameObject.h"
#include "Background.h"
#include "Meteor.h"

#include <cstdlib>
#include <ctime>

#define TIME_BETW_GEN 900000

#include "Bullet.h"
#pragma warning(disable : 4996)


SFML_GameWindow::SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName){

	int positionX;
	int positionY;
	int width;
	float Vx;
	float Vy;
	float mass;

	float deltaTime;

	bool started = true;

	float timeBetweenGen = TIME_BETW_GEN;

	Meteor* dinamicMeteor=nullptr;

	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Close);
	this->clock = new sf::Clock;

	std::list<PhysicalGameObject*> bullets;
	std::list<PhysicalGameObject*> meteors;

	std::list<PhysicalGameObject*>::iterator meteorsIterator;
	std::list<PhysicalGameObject*>::iterator bulletsIterator;

	srand(time(NULL));


	sf::Image met;
	met.loadFromFile("78.png");

	sf::Image shp;
	shp.loadFromFile("57.png");
	PlayerShip sh(1000, 1000, 330, 210, &shp, 0, 0, shp.getSize().x, shp.getSize().y, 0, windowWidth, 0, windowHeight, &bullets);


	sh.SetBulletTextureImage(&met);
	sh.SetBulletBoundXMax(windowWidth);
	sh.SetBulletBoundYMax(windowHeight);
	sh.SetBulletBoundXMin(0);
	sh.SetBulletBoundYMin(0);

	sh.SetBulletWidth(30);
	sh.SetBulletHeight(30);

	sf::Image bkgImg;
	bkgImg.loadFromFile("34.png");
	Background back(0, 0, windowWidth, windowHeight, &bkgImg, 0, 0, bkgImg.getSize().x, bkgImg.getSize().y);


	while (this->window->isOpen()) {
		sf::Event event;
		while (this->window->pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				window->close();
			}

		}
		
		if (started) {
			deltaTime = this->clock->getElapsedTime().asMicroseconds();
			clock->restart();
		}


		if (timeBetweenGen > 0) {
			timeBetweenGen -= deltaTime;
		}
		else {
			timeBetweenGen = TIME_BETW_GEN;

			do
			{
				if (dinamicMeteor != nullptr) {
					delete dinamicMeteor;
				}
				width = int((windowWidth / 10) + rand() % (5 * (windowWidth / 100)));
				positionX = rand() % (windowWidth - width - 1);
				positionY = -width + 1;
				Vx = 0; //-0.5 + 0.01 * (rand() % 101);
				Vy = 0.1 + 0.01 * (rand() % 31);
				mass = 25 + rand() % 300;

				dinamicMeteor = new Meteor(positionX, positionY, width, width, &met, 0, 0,
					int(met.getSize().x/2), int(met.getSize().y), Vx, Vy, 0, windowWidth, 0, windowHeight, mass, &meteors);

			} while (dinamicMeteor->CheckCollisionsWithMetheors(&meteors));

			meteors.push_back(dinamicMeteor);

			dinamicMeteor=nullptr;

		}


		sh.Control(deltaTime /800);

		//if (sh.CheckColision(&s1)) {
			//std::cout << "collision" << std::endl;
		//}

		window->clear();
		back.DrawOnWindow(window);


		for (meteorsIterator = meteors.begin(); meteorsIterator != meteors.end();) {
			(*meteorsIterator)->Move(deltaTime / 800);
			(*meteorsIterator)->CheckColisionsWithBullets(&bullets);
			

			if ((*meteorsIterator)->CheckAlive(deltaTime /800)) {
				(*meteorsIterator)->DrawOnWindow(window);
				
				if (!(*meteorsIterator)->IsInBounds())
				{
					delete (*meteorsIterator);
					meteorsIterator = meteors.erase(meteorsIterator);
				}
				else {
					meteorsIterator++;
				}
			}
			else {
				delete (*meteorsIterator);
				meteorsIterator = meteors.erase(meteorsIterator);
			}
		}

		

		for (bulletsIterator = bullets.begin(); bulletsIterator != bullets.end();) {
			(*bulletsIterator)->Move(deltaTime / 800);
			(*bulletsIterator)->DrawOnWindow(window);

			if (!(*bulletsIterator)->IsInBounds())
			{
				delete (*bulletsIterator);
				bulletsIterator = bullets.erase(bulletsIterator);
			}
			else {
				bulletsIterator++;
			}
		}
		if (sh.CheckCollisionsWithMeteors(&meteors)) {
			started = false;
			deltaTime = 0;
		}

		

		sh.DrawOnWindow(window);
		window->display();


	}
	
	

}


SFML_GameWindow::~SFML_GameWindow()
{
}