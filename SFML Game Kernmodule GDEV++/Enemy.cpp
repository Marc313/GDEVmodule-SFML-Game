#include "Enemy.h";
#include <IOStream>;

Enemy::Enemy(int squareSize, sf::Color enemyColor, Vector2 startPos)
{
	velocity.y = 6;
	position = startPos;
	rectRenderer = RectRenderer(squareSize, squareSize, enemyColor);
}

void Enemy::onUpdate(sf::RenderWindow& window)
{
	position = calculateNewPosition();
	rectRenderer.SetShapePosition(position);

	draw(window);

	
	//std::cout << position.to_string();
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
