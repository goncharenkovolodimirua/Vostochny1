#include "pch.h"
#include "SFML_GameWindow.h"

#include <iostream>

void SFML_GameWindow::GenerateMeteors()
{
	Meteor* dinamicMeteor = nullptr;

	int localMeteorPositionX;
	int localMeteorPositionY;
	int localMeteorWidth;
	float localMeteorVx;
	float localMeteorVy;
	float localMeteorMass;

	if (this->timeBetweenGen > 0) {
		this->timeBetweenGen -= this->deltaTime;
	}
	else {
		this->timeBetweenGen = TIME_BETW_GEN;
		do
		{
			if (dinamicMeteor != nullptr) {
				delete dinamicMeteor;
			}
			localMeteorWidth = int((this->windowWidth / 10) + rand() % (5 * (this->windowWidth / 100)));
			localMeteorPositionX = rand() % (this->windowWidth - localMeteorWidth - 1);
			localMeteorPositionY = -localMeteorWidth + 1;
			localMeteorVx = 0; 
			localMeteorVy = 0.1 + 0.01 * (rand() % 31);
			localMeteorMass = 25 + rand() % 300;

			dinamicMeteor = new Meteor(localMeteorPositionX, localMeteorPositionY, 
				localMeteorWidth, localMeteorWidth, &this->meteorTexture, 0, 0,
				int(meteorTexture.getSize().x / 2), int(meteorTexture.getSize().y),
				localMeteorVx, localMeteorVy, 0, this->windowWidth, 0, 
				this->windowHeight, localMeteorMass, &this->meteors);

		} while (dinamicMeteor->CheckCollisionsWithMetheors(&meteors));

		this->meteors.push_back(dinamicMeteor);

		dinamicMeteor = nullptr;
	}
}

void SFML_GameWindow::CheckMeteorsWithBullets()
{
	for (this->meteorsIterator = this->meteors.begin(); 
		this->meteorsIterator != this->meteors.end();) {
		(*this->meteorsIterator)->Move(this->deltaTime / FPS_TIME);
		(*this->meteorsIterator)->CheckCollisionWithList(&this->bullets, COLLISION_WITH_BULLET);


		if ((*this->meteorsIterator)->CheckAlive(this->deltaTime / FPS_TIME)) {
			(*this->meteorsIterator)->DrawOnWindow(this->window);

			if (!(*this->meteorsIterator)->IsInBounds())
			{
				delete (*this->meteorsIterator);
				this->meteorsIterator = this->meteors.erase(this->meteorsIterator);
			}
			else {
				this->meteorsIterator++;
			}
		}
		else {
			delete (*this->meteorsIterator);
			this->meteorsIterator = meteors.erase(this->meteorsIterator);
		}
	}
}

void SFML_GameWindow::CheckBulletsWithScreen()
{
	for (this->bulletsIterator = this->bullets.begin(); 
		this->bulletsIterator != this->bullets.end();) {
		(*this->bulletsIterator)->Move(this->deltaTime / FPS_TIME);
		(*this->bulletsIterator)->DrawOnWindow(this->window);

		if (!(*this->bulletsIterator)->IsInBounds())
		{
			delete (*this->bulletsIterator);
			this->bulletsIterator = this->bullets.erase(this->bulletsIterator);
		}
		else {
			this->bulletsIterator++;
		}
	}
}

void SFML_GameWindow::ClearLabels()
{
	for (this->bulletsIterator = this->bullets.begin();
		this->bulletsIterator != this->bullets.end();) 
	{
		delete (*this->bulletsIterator);
		this->bulletsIterator = this->bullets.erase(this->bulletsIterator);
	}

	for (this->meteorsIterator = this->meteors.begin();
		this->meteorsIterator != this->meteors.end();) 
	{
		delete (*this->meteorsIterator);
		this->meteorsIterator = this->meteors.erase(this->meteorsIterator);
	}
}

SFML_GameWindow::SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName){

	int fontSize;
	int textPositionY;
	int textPositionX;

	int startButtonFontSize;
	int startButtonPositionX;
	int startButtonPositionY;
	
	srand(time(NULL));

	this->meteorTexture.loadFromFile("78.png");
	this->shipTexture.loadFromFile("57.png");
	this->backgroundImage.loadFromFile("34.png");
	this->font.loadFromFile(FONT_NAME);

	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Close);
	this->clock = new sf::Clock;

	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	this->started= false;


	this->ship=new PlayerShip(1000, 800, 330, 210, &this->shipTexture,
		0, 0, this->shipTexture.getSize().x, this->shipTexture.getSize().y,
		0, this->windowWidth, 0, this->windowHeight, &bullets);

	startButtonFontSize = int(this->windowHeight / 8);
	this->startButton = new GameButton(500, 500, &this->font, startButtonFontSize, "START", startButtonFontSize/7, startButtonFontSize/7);
	startButtonPositionY = this->windowHeight / 2;
	startButtonPositionX= this->windowWidth / 2 - this->startButton->GetWidth() / 2;
	this->startButton->ChangeButtonPosition(startButtonPositionX, startButtonPositionY);
	this->startButton->SetBackgroundColorMouseOver(sf::Color(100, 200, 100));
	this->startButton->SetBackgroundColorNoMouse(sf::Color(100, 150, 100));
	this->startButton->SetBackgroundColorPressed(sf::Color(100, 100, 100));


	fontSize = int(this->windowHeight / 4);
	textPositionY = int((this->windowHeight / 3.5) - (fontSize / 2));
	this->gameName = new SFML_TextGameObject(100, 0, &this->font, fontSize,GAME_NAME);
	textPositionX = (this->windowWidth / 2) - (this->gameName->GetWidth() / 2);
	this->gameName->SetTextPosition(textPositionX, textPositionY);


	this->ship->SetBulletTextureImage(&this->meteorTexture);
	this->ship->SetBulletBoundXMax(this->windowWidth);
	this->ship->SetBulletBoundYMax(this->windowHeight);
	this->ship->SetBulletBoundXMin(0);
	this->ship->SetBulletBoundYMin(0);

	this->ship->SetBulletWidth(30);
	this->ship->SetBulletHeight(30);


	this->background=new Background(0, 0, windowWidth, windowHeight, 
		&this->backgroundImage, 0, 0, this->backgroundImage.getSize().x,
		this->backgroundImage.getSize().y);


	while (this->window->isOpen()) {
		
		while (this->window->pollEvent(this->event)) {
			if (this->event.type == sf::Event::Closed) {
				window->close();
			}
		}
		
		if (this->started) {
			deltaTime = this->clock->getElapsedTime().asMicroseconds();
			this->clock->restart();
		}

		this->GenerateMeteors();
		
		this->ship->Control(this->deltaTime / FPS_TIME);

		this->window->clear();
		this->background->DrawOnWindow(window);

		this->CheckMeteorsWithBullets();
		this->CheckBulletsWithScreen();
		
		if (this->started) {
			if (this->ship->CheckCollisionsWithMeteors(&this->meteors)) {
				this->started = false;
				this->deltaTime = 0;
			}
		}


		this->ship->DrawOnWindow(this->window);

		if (this->started == false) {
			this->gameName->DrawOnWindow(this->window);
			this->startButton->DrawOnWindow(this->window);
			if (this->startButton->CheckButtonPressed()) {
				this->started = true;
			}
		}

		this->window->display();
	}
}


SFML_GameWindow::~SFML_GameWindow()
{
	if (this->ship != nullptr) {
		delete this->ship;
	}
	if (this->background != nullptr) {
		delete this->background;
	}
	this->ClearLabels();
}
