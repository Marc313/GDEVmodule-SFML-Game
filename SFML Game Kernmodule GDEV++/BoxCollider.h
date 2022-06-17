#pragma once

#include "Vector2.h"

class BoxCollider
{
	public:	
		// Variables (maybe should be private?)
		float bottomY;
		float topY;
		float leftX;
		float rightX;

		BoxCollider();
		BoxCollider(Vector2 size, Vector2 pos);
		BoxCollider& operator=(const BoxCollider& boxCollider);

		bool isCollidingWith(BoxCollider collider);
		//void updateSize(Vector2 newSize);
		void updatePosition(Vector2 newPos);
		void calculateCorners();

	private:
		Vector2 size;
		Vector2 position;
};

