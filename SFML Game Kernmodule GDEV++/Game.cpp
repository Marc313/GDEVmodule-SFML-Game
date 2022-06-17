#include "Game.h"
#include "ScoreManager.h"

Game::Game()
{
	CreateWindow();
	StartGame();
}

Game::~Game()
{
	delete renderWindow;
}

// Private Methods //
void Game::CreateWindow()
{
	windowSize = Vector2(1000, 1000);
	renderWindow = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Avoid the cubes");
	renderWindow->setFramerateLimit(60);
}

void Game::StartGame()
{
	difficulty = 1;
	player = Player(Vector2(50.0f, 50.0f), sf::Color::Green);
	enemyManager = EnemyManager(3);
	scoreManager = ScoreManager();
}

void Game::EndGame()
{
	StartGame();
}

void Game::pollEvents()
{
	int horizontalInput = 0;
	sf::Event event;
	while (renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			renderWindow->close();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			renderWindow->close();
		}
	}
}

// Public Methods //
void Game::onUpdate(float deltaTime)
{
	pollEvents();

	renderWindow->clear();

	player.onUpdate(*renderWindow);
	enemyManager.onUpdate(*renderWindow, scoreManager, player);
	scoreManager.onUpdate(*renderWindow);

	renderWindow->display();
}

bool Game::isRunning()
{
	return renderWindow->isOpen();
}

// Public Static Methods //

void Game::onPlayerDied()
{

}

void Game::setDifficulty(int difficulty)
{
	this->difficulty = difficulty;
	enemyManager.maxEnemies = difficulty + 2;
}

