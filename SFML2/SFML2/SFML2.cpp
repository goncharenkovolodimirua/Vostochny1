// SFML2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include "SFML_GameWindow.h"
#include "SettingsWindow.h"

SFML_GameWindow* gw;


int main()
{
	std::int16_t width;
	std::int16_t height;
	bool selected;

	SettingsWindow* settings = new SettingsWindow(640, 480, "Resolution", sf::Style::Close, &width, &height, &selected);
	delete settings;

	if (selected) {
		gw = new SFML_GameWindow(width, height, "VOSTOCNY", sf::Style::Close);
	}
	delete gw;
	return 0;
}
