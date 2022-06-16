#include "ScoreManager.h"

ScoreManager::ScoreManager() 
{
	score = 0;

	/*sf::Font font;
	font.loadFromFile("Frijole-Regular.tff");

	text.setFont(font);*/

	text.setPosition(600.0f, 100.0f);
	text.setString("0");
	text.setCharacterSize(50);
	text.setStyle(sf::Text::Bold);
}

void ScoreManager::increaseScore(int value)
{
	score += value;
	text.setString(std::to_string(score));
}

void ScoreManager::onUpdate(sf::RenderWindow& window)
{
	window.draw(text);
}


