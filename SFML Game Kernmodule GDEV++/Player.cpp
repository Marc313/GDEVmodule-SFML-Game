#include <SFML/Window.hpp>;
#include "Player.h";
#include <IOStream>;

Player::Player()
{
    input = 0;
    startPos = Vector2(1000, 900);
    position = startPos;
}

Player::Player(float squareSize, sf::Color playerColor)
{
    startPos = Vector2(1000, 900);
    position = startPos;
    rectRenderer = RectRenderer((int)squareSize, (int)squareSize, playerColor);
}

Player& Player::operator=(const Player& player)
{
    rectRenderer = player.rectRenderer;
    //startPos = player.startPos;

    return *this;
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
