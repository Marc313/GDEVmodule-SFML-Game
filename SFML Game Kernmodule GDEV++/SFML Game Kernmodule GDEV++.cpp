#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h";

int main()
{
    Game game = Game();

    while (game.isRunning())
    {
        // Update
        game.onUpdate();
    }

    return 0;
}