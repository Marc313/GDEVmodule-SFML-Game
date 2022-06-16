#include "Vector2.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

sf::Vector2f Vector2::ToSFMLVector2f()
{
	return sf::Vector2f(x, y);
}

sf::Vector2i Vector2::ToSFMLVector2i()
{
	return sf::Vector2i(x, y);
}

Vector2 Vector2::operator+(Vector2 otherVector)
{
	return Vector2(x + otherVector.x, y + otherVector.y);
}

Vector2 Vector2::operator-(Vector2 otherVector)
{
	return Vector2(x - otherVector.x, y - otherVector.y);
}

std::string Vector2::to_string() {
	return "x: " + std::to_string(x) + " y: " + std::to_string(y) + "\n";
}

//Vector2 Vector2::operator+=(Vector2 otherVector)
//{
//	x + otherVector.x;
//	y + otherVector.y;
//}
//
//Vector2 Vector2::operator-=(Vector2 otherVector)
//{
//	x - otherVector.x;
//	y - otherVector.y;
//}

