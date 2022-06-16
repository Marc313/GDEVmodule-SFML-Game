#pragma once

#include "Vector2.h";
#include "Character.h";
#include <SFML/Graphics.hpp>;

class Player : public Character
{
	public:
		Player();
		Player(float squareSize, sf::Color playerColor);

		Player& operator=(const Player& player);
		
		void onUpdate(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

	private:
		RectRenderer rectRenderer;
		
		float input;
		float getMouseInputX();
};

