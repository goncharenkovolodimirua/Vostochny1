#include "pch.h"
#include "SFML_Window.h"


sf::RenderWindow * SFML_Window::GetWindowAddress()
{
	return this->window;
}

void SFML_Window::WindowDisplay()
{
	if (this->window != nullptr) {
		if (this->window->isOpen()) {
			this->window->display();
		}
	}
}

void SFML_Window::WindowClear()
{
	this->window->clear();
}

void SFML_Window::WindowClose()
{
	this->window->close();
}

SFML_Window::SFML_Window(std::uint16_t windowWidth, std::uint16_t windowHeight, std::string windowName, sf::Uint32 style)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->windowName = windowName;
	this->style = style;

	this->window = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), this->windowName, this->style);
	this->clock = new sf::Clock();
}

SFML_Window::~SFML_Window()
{
	if (this->window != nullptr) {
		delete this->window;
	}
	if (this->clock != nullptr) {
		delete this->clock;
	}
}

std::uint16_t SFML_Window::GetWindowWidth()
{
	return this->windowWidth;
}

std::uint16_t SFML_Window::GetWindowHeight()
{
	return this->windowHeight;
}

sf::Uint32 SFML_Window::GetWindowStyle()
{
	return this->style;
}

std::string SFML_Window::GetWindowName()
{
	return this->windowName;
}

void SFML_Window::SetWindowWidth(std::uint16_t windowWidth)
{
	this->windowWidth = windowWidth;
	this->window->setSize(sf::Vector2u(this->windowWidth, this->windowHeight));
}

void SFML_Window::SetWindowHeight(std::uint16_t windowHeight)
{
	this->windowHeight = windowHeight;
	this->window->setSize(sf::Vector2u(this->windowWidth, this->windowHeight));
}

float SFML_Window::GetClockTime()
{
	return this->clock->getElapsedTime().asMicroseconds();
}

void SFML_Window::RestartClock()
{
	this->clock->restart();
}

void SFML_Window::SetWindowName(std::string windowName)
{
	this->windowName = windowName;
	this->window->setTitle (this->windowName);
}

