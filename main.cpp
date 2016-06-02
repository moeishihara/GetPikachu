/**@mainpage Game
 * @author Moe Ishihara
 * @purpose homework for PIC 10C class, Spring 2016
 * @date 06-01-2016
 *
 * This program creates a GUI modeling a platform game featuring Pokemon.
 * @brief The player must catch 5 Pikachus without touching enemies for three times.
 */

#include "game.h"
#include <QApplication>

// create a global variable Game* game
Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
