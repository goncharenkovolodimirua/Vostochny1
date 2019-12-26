#ifndef WINDOW
#define WINDOW

#include <SFML/Graphics.hpp>

#include <string>
#include <cstdint>

class SFML_Window
{
private:
	std::uint16_t windowWidth;
	std::uint16_t windowHeight;
	std::string windowName;
	sf::Uint32 style;

	sf::RenderWindow* window;
	sf::Clock* clock;
	
protected:
	sf::Event event;

	virtual sf::RenderWindow* GetWindowAddress();


	virtual void SetWindowWidth(std::uint16_t windowWidth);
	virtual void SetWindowHeight(std::uint16_t windowHeight);

	virtual float GetClockTime();
	virtual void RestartClock();

public:
	SFML_Window(std::uint16_t windowWidth, std::uint16_t windowHeight, std::string windowName, sf::Uint32 style);
	virtual ~SFML_Window();

	virtual void Control(float deltaTime) = 0;
		
	virtual std::uint16_t GetWindowWidth();
	virtual std::uint16_t GetWindowHeight();

	virtual sf::Uint32 GetWindowStyle();
	virtual std::string GetWindowName();

	virtual void SetWindowName(std::string name);

	virtual void WindowDisplay();
	virtual void WindowClear();
	virtual void WindowClose();
};

#endif // !WINDOW




