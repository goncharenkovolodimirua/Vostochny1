#ifndef __SFML_GAMEOBJECT__
#define __SFML_GAMEOBJECT__

#include "SFML/Graphics.hpp"
#include <cstdint>

class SFML_GameObject
{
private:
	int16_t positionX;
	int16_t positionY;
	uint16_t width;
	uint16_t height;
	uint16_t originalWidth;
	uint16_t originalHeight;


protected:
	void SetPositionX(int16_t positionX);
	void SetPositionY(int16_t positionY);
	void SetWidth(uint16_t width);
	void SetHeight(uint16_t height);
	void SetOriginalWidth(uint16_t originalWidth);
	void SetOriginalHeight(uint16_t originalHeight);

	uint16_t GetOriginalWidth();
	uint16_t GetOriginalHeight();


public:
	int16_t GetPositionX();
	int16_t GetPositionY();
	uint16_t GetWidth();
	uint16_t GetHeight();
	
	SFML_GameObject(int16_t positionX, int16_t positionY, uint16_t width, uint16_t height);
	SFML_GameObject(int16_t positionX, int16_t positionY);
	virtual ~SFML_GameObject();

	virtual sf::IntRect GetSpriteIntRect();
	virtual bool CheckSpriteColision(SFML_GameObject *gameObject);
	virtual bool CheckSpriteColision(SFML_GameObject *gameObject, sf::IntRect *intersection);

	virtual void DrawOnWindow(sf::RenderWindow *window) = 0;
	virtual void Resize(uint16_t width, uint16_t height) = 0;
	virtual void ResizeDefault()=0;
};
#endif

