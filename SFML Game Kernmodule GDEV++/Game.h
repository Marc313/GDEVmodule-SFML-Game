#pragma once
#include "Vector2.h";
#include "Player.h";
#include "EnemyManager.h";
#include "ScoreManager.h";

class Game
{
	public:
		Vector2 windowSize;

		Game();
		~Game();
		void pollEvents();
		void onUpdate();
		bool isRunning();

	private:
		Player* player;
		EnemyManager* enemyManager;
		ScoreManager* scoreManager;

		sf::RenderWindow* renderWindow;

		void CreateWindow();
		void StartGame();
};

