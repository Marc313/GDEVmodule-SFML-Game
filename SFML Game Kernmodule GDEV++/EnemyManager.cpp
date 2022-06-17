#include "EnemyManager.h"
#include <random>
#include <iostream>
using namespace std;

EnemyManager::EnemyManager() {
	maxEnemies = 0;
}

EnemyManager::EnemyManager(int maxEnemies)
{
	this->maxEnemies = maxEnemies;
}

void EnemyManager::SpawnEnemy(Vector2 windowSize)
{
	Vector2 randomPos = getRandomEnemySpawnPos(windowSize);
	
	Enemy enemy = Enemy(Vector2(100.0f, 100.0f), sf::Color::Red, randomPos);
	enemies.push_back(enemy);
}

void EnemyManager::RespawnEnemy(Enemy& enemy, Vector2 windowSize)
{
	enemy.position = getRandomEnemySpawnPos(windowSize);
}

void EnemyManager::onUpdate(sf::RenderWindow& window, ScoreManager& scoreManager, Player& player)
{
	// Make a window manager?
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);
	
	// Update each enemy
	for (Enemy& enemy : enemies)
	{
		// Check Border Collision
		if (enemy.isOutOfScreen(window)) 
		{
			scoreManager.increaseScore(1);
			RespawnEnemy(enemy, windowSize);
		}
		enemy.onUpdate(window);

		// Check collision with Player
		if (enemy.collider.isCollidingWith(player.collider)) {
			player.onCollision();
		}
	}

	// Spawn a new enemy if there is capacity
	if (enemies.capacity() < maxEnemies) {
		SpawnEnemy(windowSize);
	}
}

Vector2 EnemyManager::getRandomEnemySpawnPos(Vector2 windowSize)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> dist(0, windowSize.x - 100); // Range is from 0.0f to t

	float randomX = dist(mt);

	return Vector2(randomX, 0);
}
