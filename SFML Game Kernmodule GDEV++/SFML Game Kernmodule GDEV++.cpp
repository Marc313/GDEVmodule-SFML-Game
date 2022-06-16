#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h";

int main()
{
    Game game = Game();

    /*Player player = Player(50.0f, sf::Color::Green);
    EnemyManager enemyManager = EnemyManager(5);
    ScoreManager scoreManager = ScoreManager();*/

    while (game.isRunning())
    {
        // Update
        game.onUpdate();

        /*renderWindow.clear();

        player.onUpdate(renderWindow);
        enemyManager.onUpdate(renderWindow);
        scoreManager.onUpdate(renderWindow)

        renderWindow.display();*/
    }

    return 0;
}