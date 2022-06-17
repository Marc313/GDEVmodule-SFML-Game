#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Vector2 size, sf::Color enemyColor, Vector2 startPos)
{
	this->size = size;
	downwardForce = Vector2(0, Math::randomRange(3, 4));
	position = startPos;
	collider = BoxCollider(size, position);
	rectRenderer = RectRenderer(size.x, size.y, enemyColor);
	physicsComponent = PhysicsComponent(Math::randomRange(3, 5));
}

void Enemy::onUpdate(sf::RenderWindow& window)
{
	physicsComponent.addForce(downwardForce);
	physicsComponent.onUpdate();
	position = calculateNewPosition();
	collider.updatePosition(position);
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
