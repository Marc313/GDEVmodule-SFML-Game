#include "Game.h";
#include "Time.h"

int main()
{
    Game game = Game();

    float oldTime = 0;
    while (game.isRunning())
    {
        // Update
        Time::calculateDeltaTime();
        game.onUpdate();
    }

    return 0;
}


