#include "Character.h"
#include <IOStream>
using namespace std;

Character::Character() 
{
    collider = BoxCollider();
    startPos = Vector2();
    position = startPos;
}

//Character::Character(Vector2 size, sf::Color shapeColor)
//{
//
//}

Character& Character::operator=(const Character& character)
{
    size = character.size;
    startPos = character.startPos;
    position = character.position;
    velocity = character.velocity;

    return *this;
}

Vector2 Character::calculateNewPosition() {
    float friction = physicsComponent.CalculateFriction();

    Vector2 movement;
    if (Math::Abs(velocity.x) > friction) {
        movement.x = velocity.x - friction;
    }
    if (Math::Abs(velocity.y) > friction) {
        movement.y = velocity.y - friction;
    }

    return position + movement;
}

void Character::onUpdate(sf::RenderWindow& window)
{
    
}
