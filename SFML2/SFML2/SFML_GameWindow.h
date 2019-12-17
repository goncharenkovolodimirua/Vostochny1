#ifndef __SFML_GameWindow__
#define __SFML_GameWindow__

#include <string>
#include <SFML/Graphics.hpp>

class SFML_GameWindow
{
private:
	sf::RenderWindow* window;
	sf::Clock* clock;

public:
	SFML_GameWindow(int windowWidth, int windowHeight, std::string windowName);
	~SFML_GameWindow();
};
#endif