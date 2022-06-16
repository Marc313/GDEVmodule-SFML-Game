#pragma once
#include "ShapeRenderer.h"

class RectRenderer : public ShapeRenderer
{
	public:
		int width;
		int height;

		RectRenderer();
		RectRenderer(int rectWidth, int rectHeight, sf::Color shapeColor);
		void drawShape(sf::RenderWindow& window);

	private:
		sf::RectangleShape shape;
};

