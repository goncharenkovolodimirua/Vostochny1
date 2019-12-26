// SFML2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include "SFML_GameWindow.h"

int main()
{
	SFML_GameWindow gw(3840, 2160, "Test", sf::Style::Close);

	return 0;
}
