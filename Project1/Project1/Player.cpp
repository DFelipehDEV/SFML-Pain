#include "Player.h"
#include "SFML/Graphics.hpp"
#include <stdio.h>

int currentFrame;
int frameTime;
float xSpeed, ySpeed;
Player::Player() 
{
    // 0-DEFAULT/1-JUMP
    state = 0;
    ground = false;
    currentFrame = 0;
    frameTime = 0;
    xPos = 15.0;
    yPos = 40.0;

    if (!texture.loadFromFile("images/sprPlayerIdle.png")) 
    {
        // Handle loading error
    }

    // Set the sprite sheet texture to the sprite
    pSprite.setTexture(texture);
    pSprite.setOrigin(sf::Vector2f(16, 26));
    pSprite.setPosition(sf::Vector2f(xPos, yPos));

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

void Player::Jump()
{
    ground = false;
    ySpeed = -5.0;
    state = 1;
    printf("JUMP");
}
void Player::States()
{
    switch (state)
    {
        // Default state
        case 0:
            // Check jump input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ground == true)
            {
                // Jump
                Jump();
            }
            break;
        // Jump state
        case 1:
            // Check if we are on the ground
            if (ground)
            {
                // Reset to default state
                state = 0;
            }
            break;
    }
}

void Player::Animate()
{
    // Animate
    frameTime += 1;
    if (frameTime > 5)
    {
        currentFrame = (currentFrame + 1) % IDLEFRAMES;
        frameTime = 0;
    }
}
void Player::update()
{
    xPos += xSpeed;
    yPos += ySpeed;

    // Check directional inputs
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // Move left
        xSpeed = -4;
        printf("%0.2f\n", xPos);
    }
    else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // Move right
        xSpeed = 4;
        printf("%0.2f\n", xPos);
    }
    else
    {
        // Stop
        xSpeed = 0;
    }

    // Temporary ground code
    if (yPos >= 200 && ground == false && ySpeed >= 0)
    {
        ground = true;
        yPos = 200;
        ySpeed = 0;
    }
    
    // Fall
    if (ground == false)
    {
        ySpeed += 0.2f;
    }

    States();
    Animate();
}

void Player::draw(sf::RenderWindow& window) 
{
    idleFrames[currentFrame].setPosition(sf::Vector2f(xPos, yPos));
    window.draw(idleFrames[currentFrame]);
}
