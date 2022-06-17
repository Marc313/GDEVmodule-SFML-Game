#include "ScoreManager.h"

ScoreManager::ScoreManager() 
{
	score = 0;

	// Bad code because otherwise it deletes my font
	sf::Font* font = new sf::Font;
	font->loadFromFile("Resources/PTSerif-Regular.ttf");
	
	/*font.loadFromFile("C:/Users/marcr/Documents/Visual Studio Projects Git/GDEVmodule-SFML-Game/SFML Game Kernmodule GDEV++/Resources/PTSerif-Regular.ttf");
	text.setFont(font);*/

	text.setFont(*font);
	text.setPosition(500.0f, 100.0f);
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


