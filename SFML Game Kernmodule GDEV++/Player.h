#pragma once

#include "Vector2.h";
#include "Character.h";
#include <SFML/Graphics.hpp>;

class Player : public Character
{
	public:
		Player(float squareSize, sf::Color playerColor);
		
		void onUpdate(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

	private:
		RectRenderer rectRenderer;
		const Vector2 startPos = Vector2(1000, 900);
		
		float input;
		float getMouseInputX();
};

