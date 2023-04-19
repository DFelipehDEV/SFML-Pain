#pragma once
#include <SFML/Graphics.hpp>
#define IDLEFRAMES 7

#define FRAMEWIDTH 38
#define FRAMEHEIGHT 40
class Player
{
public:
    int state;
    bool ground;
    float xPos, yPos;
    Player();
    ~Player();
    void Jump();
    void update();
    void draw(sf::RenderWindow& window);

private:    
    sf::Texture texture;
    sf::Sprite pSprite;
    sf::Sprite idleFrames[IDLEFRAMES];
    void States();
    void Animate();
};