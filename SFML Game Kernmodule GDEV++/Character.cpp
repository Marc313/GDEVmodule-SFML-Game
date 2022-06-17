#include "Character.h"
#include <IOStream>
using namespace std;

Character::Character() 
{
    collider = BoxCollider();
    physicsComponent = PhysicsComponent(1);
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
    physicsComponent = character.physicsComponent;

    return *this;
}

Vector2 Character::calculateNewPosition() {
    return position + physicsComponent.velocity;
}

void Character::onUpdate(sf::RenderWindow& window)
{
    
}
