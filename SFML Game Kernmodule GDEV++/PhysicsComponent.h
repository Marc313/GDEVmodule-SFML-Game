#pragma once
#include "Vector2.h"

class PhysicsComponent
{
	public:
		Vector2 velocity;
		bool IsColliding();
		float CalculateFriction();

	private:
		float mass = 1;
		const float gravitationalConstant = 9.81f;
		const float frictionCoefficient = 0.5f;		// Coefficient value for metal on wood
};

