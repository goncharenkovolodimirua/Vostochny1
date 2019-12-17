#include "pch.h"
#include "SFML_GameWindow.h"

#include "PlayerShip.h"

#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include "SFML_GameObject.h"
#include "SFML_GraphicalGameObject.h"
#include "PhysicalGameObject.h"
#pragma warning(disable : 4996)


SFML_GameWindow::SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName){
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Close);
	this->clock = new sf::Clock;

	std::list<SFML_GameObject*> bullets;



	sf::Image met;
	met.loadFromFile("77.png");
	PhysicalGameObject s1(10, 10, 300, 300, &met, 0, 0, met.getSize().x, met.getSize().y,0.1,0.2, 0,1920,0,1080);
	//SFML_GraphicalGameObject s2(280,150, 300, 300, &met, 0, 0, met.getSize().x, met.getSize().y);
	//std::cout << s1.CheckColision(&s2);


	sf::Image shp;
	shp.loadFromFile("55.png");
	PlayerShip sh(1000, 1000, 100, 300, &shp, 0, 0, shp.getSize().x, shp.getSize().y, 0, windowWidth, 0, windowHeight, &bullets);
	std::list<SFML_GameObject*> meteors;
	//std::list<SFML_GameObject*>::iterator meteorsIterator;


	//sf::Image bkgImg;
	//bkgImg.loadFromFile("33.jpg");

	//sf::Image shp;
	//shp.loadFromFile("55.png");

	//sf::Image met;
	//met.loadFromFile("77.png");


	//
	//
	//SpaceBackground backg(&bkgImg, 0, 0, windowWidth, windowHeight, 0, 0, bkgImg.getSize().x, bkgImg.getSize().y);
	//PlayerShip pl(100, 100, 100, 300, &shp, 0, 0, shp.getSize().x, shp.getSize().y, 0, windowWidth, 0, windowHeight);
	//Meteor m1(100, 100, 100, 100, &met, 0, 0, met.getSize().x, met.getSize().y);
	//
	//meteors.push_back(new Meteor(300, 300, 100, 100, &met, 0, 0, met.getSize().x, met.getSize().y));
	////vect.push_back(Meteor(800, 800, 100, 100, &met, 0, 0, met.getSize().x, met.getSize().y));

	

	while (this->window->isOpen()) {
		sf::Event event;
		while (this->window->pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				window->close();
			}

		}
	
		float time = this->clock->getElapsedTime().asMicroseconds(); //äàòü ïðîøåäøåå âðåìÿ â ìèêðîñåêóíäàõ
		clock->restart(); //ïåðåçàãðóæàåò âðåìÿ


		sh.Control(time/800);

		if (sh.CheckColision(&s1)) {
			std::cout << "collision" << std::endl;
		}

		window->clear();
		//backg.DrawOnWindow(window);
	
		//
		sh.DrawOnWindow(window);
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
		
			std::cout << s1.IsInBounds()<<std::endl;
		
		//s2.DrawOnWindow(window);
		window->display();
	}
	
	

}


SFML_GameWindow::~SFML_GameWindow()
{
}