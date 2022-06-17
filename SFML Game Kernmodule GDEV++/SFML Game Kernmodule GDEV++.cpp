#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h";

int main()
{
    Game game = Game();

    sf::Clock clock;
    float oldTime = 0;
    while (game.isRunning())
    {
        float newTime = clock.restart().asSeconds();
        float deltaTime = (newTime - oldTime);

        // Update
        game.onUpdate(deltaTime);
    }

    return 0;
}