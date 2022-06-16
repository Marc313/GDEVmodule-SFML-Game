#pragma once
#include <SFML/Graphics.hpp>

class ScoreManager
{
	public:
		int score;

		ScoreManager();
		void increaseScore(int value);
		void onUpdate(sf::RenderWindow& window);

	private:
		sf::Text text;
};

