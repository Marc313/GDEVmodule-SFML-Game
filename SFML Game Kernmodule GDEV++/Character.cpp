#include "Character.h";
#include <IOStream>
using namespace std;

Character::Character() 
{
    startPos = Vector2();
    position = startPos;
}

Character& Character::operator=(const Character& character)
{
    startPos = character.startPos;
    position = character.position;
    velocity = character.velocity;
    cout << "Character Assignment Operator" << endl;

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

    std::cout << "Movement" + movement.to_string();

    return position + movement;
}

void Character::onUpdate(sf::RenderWindow& window)
{
    
}
