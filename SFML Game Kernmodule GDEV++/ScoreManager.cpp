#include "ScoreManager.h"
#include "Game.h"

ScoreManager::ScoreManager() 
{
	score = 0;

	// Bad code because otherwise it deletes my font
	sf::Font* font = new sf::Font;
	font->loadFromFile("Resources/PTSerif-Regular.ttf");
	
	/*font.loadFromFile("C:/Users/marcr/Documents/Visual Studio Projects Git/GDEVmodule-SFML-Game/SFML Game Kernmodule GDEV++/Resources/PTSerif-Regular.ttf");
	text.setFont(font);*/

	text.setFont(*font);
	text.setPosition(600.0f, 100.0f);
	text.setString("0");
	text.setCharacterSize(100);
	text.setStyle(sf::Text::Bold);
}

//ScoreManager::~ScoreManager()
//{
//	delete font;
//}

void ScoreManager::increaseScore(int value)
{
	score += value;
	text.setString(std::to_string(score));

	//checkDifficultyIncrease();
}

void ScoreManager::onUpdate(sf::RenderWindow& window)
{
	window.draw(text);
}

//void ScoreManager::checkDifficultyIncrease()
//{
//	int difficulty = 1;
//
//	if (score < 10) {
//		difficulty = 1;
//	} 
//	else if (score < 25) {
//		difficulty = 2;
//	}
//	else if (score < 50) {
//		difficulty = 3;
//	}
//	else {
//		// After a certain point, increase the difficulty every 100 points
//		for (int i = 1; i < 50; i++)
//		{
//			if (score < 100 * i) {
//				difficulty = 3 + i;
//				break;
//			}
//		}
//	}
//
//	game.setDifficulty(difficulty);
//}


