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
	met.loadFromFile("77.png");

	sf::Image shp;
	shp.loadFromFile("55.png");
	PlayerShip sh(1000, 1000, 100, 300, &shp, 0, 0, shp.getSize().x, shp.getSize().y, 0, windowWidth, 0, windowHeight, &bullets);

	sf::Image bkgImg;
	bkgImg.loadFromFile("33.jpg");
	Background back(0, 0, windowWidth, windowHeight, &bkgImg, 0, 0, bkgImg.getSize().x, bkgImg.getSize().y);


	while (this->window->isOpen()) {
		sf::Event event;
		while (this->window->pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				window->close();
			}

		}
	
		float time = this->clock->getElapsedTime().asMicroseconds(); 
		clock->restart(); 

		if (timeBetweenGen > 0) {
			timeBetweenGen -= time;
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
					met.getSize().x, met.getSize().y, Vx, Vy, 0, windowWidth, 0, windowHeight, mass, &meteors);

			} while (dinamicMeteor->CheckCollisionsWithMetheors(&meteors));

			meteors.push_back(dinamicMeteor);

			dinamicMeteor=nullptr;

		}


		sh.Control(time/800);

		//if (sh.CheckColision(&s1)) {
			//std::cout << "collision" << std::endl;
		//}

		window->clear();
		back.DrawOnWindow(window);
		//backg.DrawOnWindow(window);
	
		//
		//sh.DrawOnWindow(window);
		//m1.DrawOnWindow(window);

		//sf::Font font;//øðèôò 
		//font.loadFromFile("F.ttf");//ïåðåäàåì íàøåìó øðèôòó ôàéë øðèôòà
		//sf::Text text("", font,100);//ñîçäàåì îáúåêò òåêñò. çàêèäûâàåì â îáúåêò òåêñò ñòðîêó, øðèôò, ðàçìåð øðèôòà(â ïèêñåëÿõ);//ñàì îáúåêò òåêñò (íå ñòðîêà)
		////text.setColor(sf::Color::Red);//ïîêðàñèëè òåêñò â êðàñíûé. åñëè óáðàòü ýòó ñòðîêó, òî ïî óìîë÷àíèþ îí áåëûé
		////text.setStyle(sf::Text::Bold | sf::Text::Underlined);//æèðíûé è ïîä÷åðêíóòûé òåêñò. ïî óìîë÷àíèþ îí "õóäîé":)) è íå ïîä÷åðêíóòûé
		//text.setString("SCORE:");//çàäàåò ñòðîêó òåêñòó
		//text.setPosition(500, 500);//çàäàåì ïîçèöèþ òåêñòà, öåíòð êàìåðû
		//text.getGlobalBounds
		//window->draw(text);//ðèñóþ ýòîò òåêñò
		//
		//for (meteorsIterator = meteors.begin();
		//	meteorsIterator != meteors.end(); meteorsIterator++) {
		//	(*meteorsIterator)->DrawOnWindow(this->window);
		//}
		


		s1.DrawOnWindow(window);
		s1.Move(time / 800);


		s1.CheckColisionsWithBullets(&meteors);

		for (meteorsIterator = meteors.begin(); meteorsIterator != meteors.end();) {
			(*meteorsIterator)->Move(time / 800);
			(*meteorsIterator)->DrawOnWindow(window);

			if (!(*meteorsIterator)->IsInBounds())
			{	
				delete (*meteorsIterator);
				meteorsIterator=meteors.erase(meteorsIterator);
			}
			else {
				meteorsIterator++;
			}
		}

		

		for (bulletsIterator = bullets.begin(); bulletsIterator != bullets.end();) {
			(*bulletsIterator)->Move(time / 800);
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

		sh.DrawOnWindow(window);
		window->display();
	}
	
	

}


SFML_GameWindow::~SFML_GameWindow()
{
}