#include "Game.h"

Game::Game()
{
	CreateWindow();
	StartGame();
}

Game::~Game()
{
	delete renderWindow;
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

void Game::CreateWindow()
{
	windowSize = Vector2(1920, 1080);
	renderWindow = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Avoid the cubes");
	renderWindow->setFramerateLimit(60);
}

void Game::StartGame()
{
	player = Player(Vector2(50.0f, 50.0f), sf::Color::Green);
	enemyManager =  EnemyManager(5);
	scoreManager =  ScoreManager();
}



