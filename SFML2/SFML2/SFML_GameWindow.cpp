#include "pch.h"
#include "SFML_GameWindow.h"

#include <iostream>

void SFML_GameWindow::GenerateMeteors(float deltaTime)
{
	Meteor* dinamicMeteor = nullptr;

	int localMeteorPositionX;
	int localMeteorPositionY;
	int localMeteorWidth;
	float localMeteorVx;
	float localMeteorVy;
	float localMeteorMass;

	if (this->timeBetweenGen > 0) {
		this->timeBetweenGen -= deltaTime;
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

void SFML_GameWindow::CheckMeteorsWithBullets(float deltaTime)
{
	for (this->meteorsIterator = this->meteors.begin(); 
		this->meteorsIterator != this->meteors.end();) {
		(*this->meteorsIterator)->Move(deltaTime / FPS_TIME);
		(*this->meteorsIterator)->CheckCollisionWithList(&this->bullets, COLLISION_WITH_BULLET);


		if ((*this->meteorsIterator)->CheckAlive(deltaTime / FPS_TIME)) {
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

void SFML_GameWindow::CheckBulletsWithScreen(float deltaTime)
{
	for (this->bulletsIterator = this->bullets.begin(); 
		this->bulletsIterator != this->bullets.end();) {
		(*this->bulletsIterator)->Move(deltaTime / FPS_TIME);
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

void SFML_GameWindow::ClearLists()
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

void SFML_GameWindow::GameFrame(float deltaTime)
{
	int startButtonFontSize;
	int startButtonPositionX;
	int startButtonPositionY;

	int fontSize;
	int textPositionY;
	int textPositionX;

	if (this->window->isOpen()) {
		if (this->statement != STARTED) {
			deltaTime = 0;
		}
		this->GenerateMeteors(deltaTime);
		this->ship->Control(deltaTime / FPS_TIME);

		this->window->clear();
		this->background->DrawOnWindow(window);

		this->CheckMeteorsWithBullets(deltaTime);
		this->CheckBulletsWithScreen(deltaTime);

		this->ship->DrawOnWindow(this->window);

		if (this->statement == STARTED) {

			this->score->AddWithTime(deltaTime);
			this->score->DrawOnWindow(this->window);

			if (this->ship->CheckCollisionsWithMeteors(&this->meteors)) {
				this->statement = LOOSED;
				this->deltaTime = 0;

				this->looseScore->SetText("SCORE: " + std::to_string(this->score->GetScore()));

			}
		}

		if (this->statement == NOT_STARTED) {
			this->gameName->DrawOnWindow(this->window);
			this->startButton->DrawOnWindow(this->window);
			this->exitButton->DrawOnWindow(this->window);
			if (this->startButton->CheckButtonPressed()) {
				this->score->SetScore(0);
				this->statement = STARTED;
			}

			if (this->exitButton->CheckButtonPressed()) {
				this->window->close();
			}

		}

		if (this->statement == PAUSED) {
			this->blackBackground->DrawOnWindow(this->window);

			this->resumeButton->DrawOnWindow(this->window);
			this->mainMenuButton->DrawOnWindow(this->window);
			this->exitButton->DrawOnWindow(this->window);

			if (this->resumeButton->CheckButtonPressed()) {
				this->statement = STARTED;
			}

			if (this->mainMenuButton->CheckButtonPressed()) {
				this->ClearLists();
				this->statement = NOT_STARTED;
				this->ship->SetPosition(1200, 800);
			}

			if (this->exitButton->CheckButtonPressed()) {
				this->window->close();
			}
		}
		if (this->statement == LOOSED) {

			this->blackBackground->DrawOnWindow(this->window);
			this->restartButton->DrawOnWindow(this->window);
			this->mainMenuButton->DrawOnWindow(this->window);


			

			fontSize = int(this->windowHeight / 6);
			textPositionY = int((this->windowHeight / 4) - (fontSize / 2));
			textPositionX = (this->windowWidth / 2) - (this->looseScore->GetWidth() / 2);
			this->looseScore->SetTextPosition(textPositionX, textPositionY);

			this->looseScore->DrawOnWindow(this->window);


			if (this->restartButton->CheckButtonPressed()) {
				this->score->SetScore(0);
				this->statement = STARTED;
				this->ship->SetPosition(1200, 800);
				this->ClearLists();
			}

			if (this->mainMenuButton->CheckButtonPressed()) {
				this->ClearLists();
				this->statement = NOT_STARTED;
				this->ship->SetPosition(1200, 800);
			}
		}

		if (this->window->isOpen()) {
			this->window->display();
		}
	}
	
}

void SFML_GameWindow::Control(float deltaTime)
{
	this->escPressedTime +=deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		if (this->escPressedTime >= ESC_PRESS_TIME) {
			if (this->statement == STARTED) {
				this->statement = PAUSED;
			}
			else if (this->statement == PAUSED) {
				this->statement = STARTED;
			}
			this->escPressedTime = 0;
		}

	}
}

void SFML_GameWindow::UploadTime()
{
	this->deltaTime = this->clock->getElapsedTime().asMicroseconds();
	this->clock->restart();
}

void SFML_GameWindow::InitializeButtons()
{
	int ButtonFontSize;
	int ButtonPositionX;
	int ButtonPositionY;

	this->font.loadFromFile(FONT_NAME);
	
	this->backgroundMusic = new sf::Music();
	this->backgroundMusic->openFromFile(BACKGROUND_SOUNDNAME);
	this->backgroundMusic->setLoop(true);
	this->backgroundMusic->play();

	ButtonFontSize = int(this->windowHeight / 8);
	this->startButton = new GameButton(500, 500, &this->font, ButtonFontSize, "START", ButtonFontSize / 7, ButtonFontSize / 7);
	ButtonPositionY = this->windowHeight / 2;
	ButtonPositionX = this->windowWidth / 2 - this->startButton->GetWidth() / 2;
	this->startButton->ChangeButtonPosition(ButtonPositionX, ButtonPositionY);
	this->startButton->SetBackgroundColorMouseOver(sf::Color(100, 200, 100));
	this->startButton->SetBackgroundColorNoMouse(sf::Color(100, 150, 100));
	this->startButton->SetBackgroundColorPressed(sf::Color(100, 100, 100));

	ButtonFontSize = int(this->windowHeight / 8);
	this->restartButton = new GameButton(500, 500, &this->font, ButtonFontSize, "RESTART", ButtonFontSize / 7, ButtonFontSize / 7);
	ButtonPositionY = (this->windowHeight / 3)*2;
	ButtonPositionX = this->windowWidth / 2 - this->restartButton->GetWidth() / 2;
	this->restartButton->ChangeButtonPosition(ButtonPositionX, ButtonPositionY);
	this->restartButton->SetBackgroundColorMouseOver(sf::Color(100, 200, 100));
	this->restartButton->SetBackgroundColorNoMouse(sf::Color(100, 150, 100));
	this->restartButton->SetBackgroundColorPressed(sf::Color(100, 100, 100));

	ButtonFontSize = int(this->windowHeight / 8);
	this->resumeButton = new GameButton(500, 500, &this->font, ButtonFontSize, "RESUME", ButtonFontSize / 7, ButtonFontSize / 7);
	ButtonPositionY = this->windowHeight / 4.8;
	ButtonPositionX = this->windowWidth / 2 - this->resumeButton->GetWidth() / 2;
	this->resumeButton->ChangeButtonPosition(ButtonPositionX, ButtonPositionY);
	this->resumeButton->SetBackgroundColorMouseOver(sf::Color(100, 200, 100));
	this->resumeButton->SetBackgroundColorNoMouse(sf::Color(100, 150, 100));
	this->resumeButton->SetBackgroundColorPressed(sf::Color(100, 100, 100));

	ButtonFontSize = int(this->windowHeight / 8);
	this->mainMenuButton = new GameButton(500, 500, &this->font, ButtonFontSize, "MAIN MENU", ButtonFontSize / 7, ButtonFontSize / 7);
	ButtonPositionY = (this->windowHeight / 4.8)*2;
	ButtonPositionX = this->windowWidth / 2 - this->mainMenuButton->GetWidth() / 2;
	this->mainMenuButton->ChangeButtonPosition(ButtonPositionX, ButtonPositionY);
	this->mainMenuButton->SetBackgroundColorMouseOver(sf::Color(100, 200, 100));
	this->mainMenuButton->SetBackgroundColorNoMouse(sf::Color(100, 150, 100));
	this->mainMenuButton->SetBackgroundColorPressed(sf::Color(100, 100, 100));

	ButtonFontSize = int(this->windowHeight / 8);
	this->exitButton = new GameButton(500, 500, &this->font, ButtonFontSize, "EXIT", ButtonFontSize / 7, ButtonFontSize / 7);
	ButtonPositionY = (this->windowHeight / 4.8) * 3;
	ButtonPositionX = this->windowWidth / 2 - this->exitButton->GetWidth() / 2;
	this->exitButton->ChangeButtonPosition(ButtonPositionX, ButtonPositionY);
	this->exitButton->SetBackgroundColorMouseOver(sf::Color(100, 200, 100));
	this->exitButton->SetBackgroundColorNoMouse(sf::Color(100, 150, 100));
	this->exitButton->SetBackgroundColorPressed(sf::Color(100, 100, 100));

}

void SFML_GameWindow::InitializeImages()
{
	this->meteorTexture.loadFromFile("meteor.png");
	this->backgroundImage.loadFromFile("34.png");
	this->blackBackgroundImage.loadFromFile("gr.png");
	
	this->background = new Background(0, 0, this->windowWidth, this->windowHeight,
		&this->backgroundImage, 0, 0, this->backgroundImage.getSize().x,
		this->backgroundImage.getSize().y);
	this->blackBackground = new Background(0, 0, this->windowWidth, this->windowHeight,
		&this->blackBackgroundImage, 0, 0, this->backgroundImage.getSize().x,
		this->backgroundImage.getSize().y);
}

void SFML_GameWindow::InitializePlayerShip()
{
	this->shipTexture.loadFromFile("57.png");
	this->bulletsTexture.loadFromFile("b1.png");

	this->ship = new PlayerShip(1200, 800, 330, 210, &this->shipTexture,
		0, 0, this->shipTexture.getSize().x, this->shipTexture.getSize().y,
		0, this->windowWidth, 0, this->windowHeight, &bullets);

	this->ship->SetBulletTextureImage(&this->bulletsTexture);
	this->ship->SetBulletBoundXMax(this->windowWidth);
	this->ship->SetBulletBoundYMax(this->windowHeight);
	this->ship->SetBulletBoundXMin(0);
	this->ship->SetBulletBoundYMin(0);

	this->ship->SetBulletWidth(30);
	this->ship->SetBulletHeight(50);
}

void SFML_GameWindow::InitializeTexts()
{
	int fontSize;
	int textPositionY;
	int textPositionX;

	this->font.loadFromFile(FONT_NAME);

	fontSize = int(this->windowHeight / 4);
	textPositionY = int((this->windowHeight / 3.5) - (fontSize / 2));
	this->gameName = new SFML_TextGameObject(100, 0, &this->font, fontSize, GAME_NAME);
	textPositionX = (this->windowWidth / 2) - (this->gameName->GetWidth() / 2);
	this->gameName->SetTextPosition(textPositionX, textPositionY);

	fontSize = int(this->windowHeight / 6);
	textPositionY = int((this->windowHeight / 4) - (fontSize / 2));
	this->looseScore = new SFML_TextGameObject(100, 0, &this->font, fontSize, "SCORE:");
	textPositionX = (this->windowWidth / 2) - (this->looseScore->GetWidth() / 2);
	this->looseScore->SetTextPosition(textPositionX, textPositionY);

	this->score = new SFML_ScoreCounterObject(10, 10, &this->font, 100);
	this->score->SetCoef(0.001);

}


SFML_GameWindow::SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName){

	

	int startButtonFontSize;
	int startButtonPositionX;
	int startButtonPositionY;

	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	
	srand(time(NULL));

	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Close);
	this->clock = new sf::Clock;

	this->statement = NOT_STARTED;



	this->InitializeImages();
	this->InitializeButtons();	
	this->InitializeTexts();
	this->InitializePlayerShip();


	while (this->window->isOpen()) {
		
		while (this->window->pollEvent(this->event)) {
			if (this->event.type == sf::Event::Closed) {
				window->close();
			}
		}

		this->UploadTime();
		this->Control(this->deltaTime);
		
		GameFrame(this->deltaTime);		
		
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

	if (this->blackBackground != nullptr) {
		delete this->blackBackground;
	}

	if (this->gameName != nullptr) {
		delete this->gameName;
	}

	if (this->looseScore != nullptr) {
		delete this->looseScore;
	}

	if (this->startButton != nullptr) {
		delete this->startButton;
	}

	if (this->restartButton != nullptr) {
		delete this->restartButton;
	}

	if (this->resumeButton != nullptr) {
		delete this->resumeButton;
	}

	if (this->mainMenuButton != nullptr) {
		delete this->mainMenuButton;
	}

	if (this->exitButton != nullptr) {
		delete this->exitButton;
	}

	if (this->score != nullptr) {
		delete this->score;
	}

	this->ClearLists();
	if (this->backgroundMusic != nullptr) {
		delete this->backgroundMusic;
	}
}
