#include "Player.h"
#include "SFML/Graphics.hpp"

float drawX, drawY;
int currentFrame;
int frameTime;
Player::Player() 
{
    currentFrame = 0;
    frameTime = 0;
    drawX = 15.0;
    drawY = 40.0;

    if (!texture.loadFromFile("images/sprPlayerIdle.png")) 
    {
        // Handle loading error
    }

    // Set the sprite sheet texture to the sprite
    pSprite.setTexture(texture);
    pSprite.setOrigin(sf::Vector2f(16, 26));
    pSprite.setPosition(sf::Vector2f(drawX, drawY));

    // Extract individual frames from the sprite sheet and store them as separate textures
    for (int i = 0; i < IDLEFRAMES; i++) 
    {
        sf::IntRect rect(i * FRAMEWIDTH, 0, FRAMEWIDTH, FRAMEHEIGHT);
        idleFrames[i].setTexture(texture);
        idleFrames[i].setTextureRect(rect);
    }
}


Player::~Player()
{

}

void Player::update()
{
    //pSprite.setPosition(drawX, drawY);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // left key is pressed: move our character
        drawX -= 4;
        printf("%0.2f\n", drawX);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        drawX += 4;
        printf("%0.2f\n", drawX);
    }

    drawY += 1;
    // Animate
    frameTime += 1;
    if (frameTime > 5) 
    {
        currentFrame = (currentFrame + 1) % IDLEFRAMES;
        frameTime = 0;
    }

}

void Player::draw(sf::RenderWindow& window) 
{
    idleFrames[currentFrame].setPosition(sf::Vector2f(drawX, drawY));
    window.draw(idleFrames[currentFrame]);
}
