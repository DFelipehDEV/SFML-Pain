#pragma once
#include <SFML/Graphics.hpp>
#define IDLEFRAMES 7

#define FRAMEWIDTH 38
#define FRAMEHEIGHT 40
class Player
{
public:
    Player();
    ~Player();
    void update();
    void draw(sf::RenderWindow& window);

private:
    float drawX, drawY;
    sf::Texture texture;
    sf::Sprite pSprite;
    sf::Sprite idleFrames[IDLEFRAMES];
};