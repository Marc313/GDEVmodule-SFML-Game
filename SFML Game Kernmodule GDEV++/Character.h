#pragma once

#include "Vector2.h";
#include "PhysicsComponent.h";
#include "ShapeRenderer.h";
#include "RectRenderer.h";
#include <SFML/Graphics.hpp>;
#include "Math.h"

class Character
{
	public:
		// Variables
		Vector2 size;
		Vector2 position;
		Vector2 velocity;

		// Methods
		Character();
		//Character(Vector2 size, sf::Color shapeColor);
		Character& operator=(const Character& character);
		Vector2 calculateNewPosition();
		void onUpdate(sf::RenderWindow& window);

	protected:
		Vector2 startPos;
		PhysicsComponent physicsComponent;
};

