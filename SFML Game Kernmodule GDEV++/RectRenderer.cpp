#include "RectRenderer.h"

RectRenderer::RectRenderer()
{
	width = 100;
	height = 100;
}

RectRenderer::RectRenderer(int rectWidth, int rectHeight, sf::Color shapeColor)
{
	width = rectWidth;
	height = rectHeight;
	Vector2 sizeVector = Vector2(rectWidth, rectHeight);
	shape.setSize(sizeVector.ToSFMLVector2f());
	shape.setFillColor(shapeColor);
}

void RectRenderer::drawShape(sf::RenderWindow& window)
{
	shape.setPosition(shapePosition.ToSFMLVector2f());
	window.draw(shape);
}
