#include "Player.h" 
#include <SFML/Window.hpp>
#include <iostream>

Player::Player()
{
    horizontalInput = 0;
}

Player::Player(Vector2 playerSize, sf::Color playerColor)
{
    size = playerSize;
    startPos = Vector2(1000, 900);
    position = startPos;
    collider = BoxCollider(size, position);
    rectRenderer = RectRenderer((int) playerSize.x, (int) playerSize.y, playerColor);
}

Player& Player::operator=(const Player& player)
{
    Character::operator=(player);
    collider = player.collider;
    rectRenderer = player.rectRenderer;
    //startPos = player.startPos;

    return *this;
}

void Player::onUpdate(sf::RenderWindow& window) {
    horizontalInput = getInputHorizontal();
    position = Vector2(position.x + horizontalInput * 10, position.y);
    //collider.updateSize(size);
    collider.updatePosition(position);
    rectRenderer.SetShapePosition(position);
    draw(window);
}

void Player::draw(sf::RenderWindow& window)
{
    rectRenderer.drawShape(window);
}

int Player::getInputHorizontal()
{
    int horizontal = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        horizontal = -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        horizontal = 1;
    }

    return horizontal;
}
