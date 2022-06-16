#include <SFML/Window.hpp>;
#include "Player.h";
#include <IOStream>;

Player::Player(float squareSize, sf::Color playerColor)
{
    rectRenderer = RectRenderer((int)squareSize, (int)squareSize, playerColor);
    this->position = startPos;
}

void Player::onUpdate(sf::RenderWindow& window) {
    std::cout << "Player" << std::endl;

    input = getMouseInputX();
    position = Vector2(input, position.y);
    rectRenderer.SetShapePosition(position);
    draw(window);
}

void Player::draw(sf::RenderWindow& window)
{
    rectRenderer.drawShape(window);
}

float Player::getMouseInputX()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    return mousePos.x;
}
