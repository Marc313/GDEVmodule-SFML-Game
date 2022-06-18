#include "ScoreManager.h"

ScoreManager::ScoreManager() 
{
	score = 0;
}

void ScoreManager::increaseScore(int value)
{
	score += value;
}


