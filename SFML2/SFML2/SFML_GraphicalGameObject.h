#ifndef __SFML_GRAPHICALGAMEOBJECT__
#define __SFML_GRAPHICALGAMEOBJECT__

#include "SFML_GameObject.h"
#include <cstdint>

class SFML_GraphicalGameObject :
    public SFML_GameObject
{
private:
    std::int16_t positionXInTexture;
    std::int16_t positionYInTexture;

    sf::Image* textureImage;
    sf::Texture* texture;
    sf::Sprite* sprite;

protected:
    sf::Sprite* GetSpriteAddress();

public:
    SFML_GraphicalGameObject(
        std::int16_t positionX,
        std::int16_t positionY,
        std::uint16_t width,
        std::uint16_t height, 
        sf::Image* textureImage,
        std::int16_t positionXInTexture,
        std::int16_t positionYInTexture,
        std::uint16_t widthInTexture,
        std::uint16_t heightInTexture
    );
    virtual ~SFML_GraphicalGameObject();

    virtual void SetPosition(
        std::int16_t x, 
        std::int16_t y
    );

    virtual void Resize(
        std::uint16_t width,
        std::uint16_t height
    );
    
    virtual void ResizeDefault();

    virtual void ChangeTextureRectangle(
        std::int16_t positionXInTexture, 
        std::int16_t positionYInTexture, 
        std::uint16_t widthInTexture, 
        std::uint16_t heightInTexture
    );

    virtual void DrawOnWindow(sf::RenderWindow *window);
};
#endif

