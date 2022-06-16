#include "PhysicsComponent.h"

bool PhysicsComponent::IsColliding()
{
	return false;
}

float PhysicsComponent::CalculateFriction()
{
	// Force of Friction = frictionCoefficient * Normal force = frictionCoefficient * Gravitational force 
	float frictionForce = frictionCoefficient * mass * gravitationalConstant;
	return frictionForce;
}
