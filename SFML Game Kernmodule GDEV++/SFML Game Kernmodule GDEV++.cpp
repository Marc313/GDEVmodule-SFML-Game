#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h";

int main()
{
    Game game = Game();

    float oldTime = 0;
    while (game.isRunning())
    {
        float newTime = clock();
        float deltaTime = newTime - oldTime;
        oldTime = newTime;

        // Update
        game.onUpdate(deltaTime);
    }

    return 0;
}