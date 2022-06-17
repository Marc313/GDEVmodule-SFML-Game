#pragma once

#include "Vector2.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Timer.h"

class Game
{
	public:
		// Public Variables //
		Game();
		virtual ~Game();

		// Public Methods //
		void onUpdate();
		bool isRunning();

		// Public Methods //
		void checkDifficultyIncrease();
		void checkPlayerLives();
		void setDifficulty(int difficulty);
		bool getHasEnded();

	private:
		// Private Variables //
		Player player;
		EnemyManager enemyManager;
		ScoreManager scoreManager;

		bool hasEnded;
		int difficulty;
		const float restartGameTime = 3.0f;
		Timer restartTimer;

		Vector2 windowSize;
		sf::RenderWindow* window;
		sf::Text gameOverText;
		sf::Font font;

		// Private Methods //
		void createWindow();
		void initializeText();
		void startGame();
		void endGame();
		void pollEvents();
		void drawGameOverText();

};

