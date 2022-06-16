#pragma once

#include "Vector2.h"
#include "Character.h"
#include <SFML/Graphics.hpp>

class Player : public Character
{
	public:
		// Constructor - Destructor
		Player();
		Player(Vector2 size, sf::Color playerColor);
		Player& operator=(const Player& player);
		
		void onUpdate(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

		// Setter
		int getInputHorizontal();

	private:
		RectRenderer rectRenderer;
		int horizontalInput;
		
};

