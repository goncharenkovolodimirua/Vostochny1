#include "pch.h"
#include "SettingsWindow.h"


void SettingsWindow::Control(float deltaTime)
{
}

SettingsWindow::SettingsWindow(std::uint16_t windowWidth,
	std::uint16_t windowHeight, 
	std::string windowName, 
	sf::Uint32 style, 
	std::int16_t* width,
	std::int16_t* height,
	bool* selected):SFML_Window(windowWidth, windowHeight, windowName, style)
{
	sf::Font font; 
	font.loadFromFile(SETTINGS_FONTNAME);

	std::int16_t positionX;
	std::int16_t positionY;

	

	GameButton hd(100, 100, &font, 80, "1280 x 720", 20, 20); 
	positionX = this->GetWindowWidth() / 2 - hd.GetWidth() / 2;
	hd.ChangeButtonPosition(positionX, 40);
	hd.SetBackgroundColorNoMouse(sf::Color(33, 108, 59));
	hd.SetBackgroundColorMouseOver(sf::Color(53, 213, 110));
	hd.SetBackgroundColorPressed(sf::Color(100, 100, 100));
	
	GameButton fhd(100, 300, &font, 80, "1920 x 1080", 20, 20);
	positionX = this->GetWindowWidth() / 2 - fhd.GetWidth() / 2;
	fhd.ChangeButtonPosition(positionX, 180);
	fhd.SetBackgroundColorNoMouse(sf::Color(33, 108, 59));
	fhd.SetBackgroundColorMouseOver(sf::Color(53, 213, 110));
	fhd.SetBackgroundColorPressed(sf::Color(100, 100, 100));
	
	GameButton fk(100, 300, &font, 80, "3840 x 2160", 20, 20);
	positionX = this->GetWindowWidth() / 2 - fk.GetWidth() / 2;
	fk.ChangeButtonPosition(positionX, 320);
	fk.SetBackgroundColorNoMouse(sf::Color(33, 108, 59));
	fk.SetBackgroundColorMouseOver(sf::Color(53, 213, 110));
	fk.SetBackgroundColorPressed(sf::Color(100, 100, 100));
	
	

	while (this->GetWindowAddress()->isOpen()) {

		while (this->GetWindowAddress()->pollEvent(this->event)) {
			if (this->event.type == sf::Event::Closed) {
				*selected = false;
				this->WindowClose();
			}
		}

		this->WindowClear();
		hd.DrawOnWindow(this->GetWindowAddress());
		fhd.DrawOnWindow(this->GetWindowAddress());
		fk.DrawOnWindow(this->GetWindowAddress());
		this->WindowDisplay();

		if (hd.CheckButtonPressed()) {
			*selected = true;
			*width = 1280;
			*height = 720;
			this->WindowClose();
		}
		if (fhd.CheckButtonPressed()) {
			*selected = true;
			*width = 1920;
			*height = 1080;
			this->WindowClose();
		}
		if (fk.CheckButtonPressed()) {
			*selected = true;
			*width = 3840;
			*height = 2160;
			this->WindowClose();
		}
	}
}


SettingsWindow::~SettingsWindow()
{
}
