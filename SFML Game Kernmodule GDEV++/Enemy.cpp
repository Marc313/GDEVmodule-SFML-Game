#include "Enemy.h"
#include <iostream>
#include <random>
using namespace std;

Enemy::Enemy(Vector2 size, sf::Color enemyColor, Vector2 startPos)
{
	this->size = size;
	velocity.y = getRandomVelocityY();
	position = startPos;
	rectRenderer = RectRenderer(size.x, size.y, enemyColor);
}

void Enemy::onUpdate(sf::RenderWindow& window)
{
	position = calculateNewPosition();
	rectRenderer.SetShapePosition(position);

	draw(window);
}

bool Enemy::isOutOfScreen(sf::RenderWindow& window) 
{
	float windowHeight = window.getSize().y;
	if (position.y > windowHeight) 
	{
		return true;
	}
	else {
		return false;
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	rectRenderer.drawShape(window);
}

float Enemy::getRandomVelocityY() {
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> dist(15, 20);

	float randomY = dist(mt);

	return randomY;
}
