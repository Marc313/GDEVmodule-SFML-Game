#pragma once
#include "Character.h";

class Enemy : public Character
{
	public:
		Enemy(int squareSize, sf::Color playerColor, Vector2 startPos);

		virtual void onUpdate(sf::RenderWindow& window);
		bool isOutOfScreen(sf::RenderWindow& window);
		virtual void draw(sf::RenderWindow& window);

	private:
		RectRenderer rectRenderer;
};

