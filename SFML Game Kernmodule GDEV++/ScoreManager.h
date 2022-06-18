#pragma once

#include <SFML/Graphics.hpp>

class ScoreManager
{
	public:
		int score;

		ScoreManager();
		void increaseScore(int value);
};

