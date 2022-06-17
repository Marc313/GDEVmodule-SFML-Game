#include "Player.h" 
#include <SFML/Window.hpp>
#include <iostream>

// Constructors //

Player::Player()
{
    lives = 1;
    horizontalInput = 0;
}

Player::Player(Vector2 playerSize, sf::Color playerColor)
{
    lives = 1;
    size = playerSize;
    startPos = Vector2(500, 750);
    position = startPos;

    collider = BoxCollider(size, position);
    rectRenderer = RectRenderer((int) playerSize.x, (int) playerSize.y, playerColor);
    physicsComponent = PhysicsComponent(.6f);
}

Player& Player::operator=(const Player& player)
{
    Character::operator=(player);
    lives = player.lives;
    collider = player.collider;
    rectRenderer = player.rectRenderer;

    return *this;
}

void Player::onUpdate(sf::RenderWindow& window) {
    horizontalInput = getInputHorizontal();
    physicsComponent.addForce(Vector2(3 * horizontalInput, 0));
    physicsComponent.onUpdate();
    std::cout << "Acceleration: " + physicsComponent.acceleration.to_string() << std::endl;
    std::cout << "Velocity: " + physicsComponent.velocity.to_string() << std::endl;
    position = calculateNewPosition();

    collider.updatePosition(position);
    rectRenderer.SetShapePosition(position);

    draw(window);
}

void Player::draw(sf::RenderWindow& window)
{
    rectRenderer.drawShape(window);
}

void Player::onCollision()
{
    // Set alpha lower for a few seconds
    lives--;
}

int Player::getLives()
{
    return lives;
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
