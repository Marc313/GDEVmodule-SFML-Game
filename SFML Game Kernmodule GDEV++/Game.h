#pragma once

#include "Vector2.h"
#include "Player.h"
#include "EnemyManager.h"

class Game
{
	public:
		Vector2 windowSize;
		int difficulty;

		// Public Variables //
		Game();
		virtual ~Game();

		// Public Methods //
		void onUpdate(float deltaTime);
		bool isRunning();

		// Public Methods //
		void onPlayerDied();
		void setDifficulty(int difficulty);

	private:
		// Private Variables //
		Player player;
		EnemyManager enemyManager;
		ScoreManager scoreManager;

		sf::RenderWindow* renderWindow;

		// Private Methods //
		void CreateWindow();
		void StartGame();
		void EndGame();
		void pollEvents();

};

