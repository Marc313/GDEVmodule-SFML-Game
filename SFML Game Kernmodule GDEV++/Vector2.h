#pragma once

#include <SFML/Graphics.hpp>

class Vector2
{
	public:
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);
		Vector2& operator=(const Vector2& v);
		sf::Vector2f ToSFMLVector2f();
		sf::Vector2i ToSFMLVector2i();

		// Operators
		Vector2 operator+(Vector2 otherVector);
		Vector2 operator-(Vector2 otherVector);
		std::string to_string();
};

