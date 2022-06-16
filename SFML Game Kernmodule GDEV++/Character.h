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
		Vector2 position;
		Vector2 velocity;

		// Methods
		Character();
		Vector2 calculateNewPosition();
		void onUpdate(sf::RenderWindow& window);

	protected:
		Vector2 startPos;		// Hoe geef ik deze handig een waarde?
		PhysicsComponent physicsComponent;
};

