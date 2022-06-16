#include "Game.h"

Game::Game()
{
	CreateWindow();
	StartGame();
}

Game::~Game()
{
	delete player;
	delete enemyManager;
	delete scoreManager;
	delete renderWindow;
}

void Game::pollEvents()
{
	sf::Event event;
	while (renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			renderWindow->close();
	}
}

void Game::onUpdate()
{
	pollEvents();

	renderWindow->clear();

	player->onUpdate(*renderWindow);
	enemyManager->onUpdate(*renderWindow, *scoreManager);
	scoreManager->onUpdate(*renderWindow);

	renderWindow->display();
}

bool Game::isRunning()
{
	return renderWindow->isOpen();
}

void Game::CreateWindow()
{
	windowSize = Vector2(1920, 1080);
	renderWindow = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Fun Game");
}

void Game::StartGame()
{
	player = new Player(50.0f, sf::Color::Green);
	enemyManager = new EnemyManager(5);
	scoreManager = new ScoreManager();
}



