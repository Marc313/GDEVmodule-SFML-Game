#pragma once

#include "Vector2.h"
#include "Character.h"
#include <SFML/Graphics.hpp>

class Player : public Character
{
	public:
		// Constructors //
		Player();
		Player(Vector2 size, sf::Color playerColor);
		Player& operator=(const Player& player);
		
		// Public Methods //
		void onUpdate(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

	private:
		// Private Variables //
		RectRenderer rectRenderer;
		int horizontalInput;

		// Private Methods //
		int getInputHorizontal();
};

