#ifndef __SFML_GAMEOBJECT__
#define __SFML_GAMEOBJECT__

#include "SFML/Graphics.hpp"

class SFML_GameObject
{
private:
	int positionX;
	int positionY;
	int width;
	int height;
	int originalWidth;
	int originalHeight;


protected:
	void SetPositionX(int positionX);
	void SetPositionY(int positionY);
	void SetWidth(int width);
	void SetHeight(int height);
	void SetOriginalWidth(int originalWidth);
	void SetOriginalHeight(int originalHeight);

	int GetOriginalWidth();
	int GetOriginalHeight();


public:
	int GetPositionX();
	int GetPositionY();
	int GetWidth();
	int GetHeight();
	
	SFML_GameObject(int positionX, int positionY, int width, int height);
	SFML_GameObject(int positionX, int positionY);
	virtual ~SFML_GameObject();

	virtual sf::IntRect GetIntRect();
	virtual bool CheckColision(SFML_GameObject *gameObject);
	virtual void DrawOnWindow(sf::RenderWindow *window) = 0;
	virtual void Resize(int width, int height) = 0;
	virtual void ResizeDefault()=0;
	
};
#endif

