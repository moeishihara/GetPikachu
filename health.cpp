/**@file health.cpp
 * @brief Contains the implementation for the Health class
 */

#include "health.h"
#include "game.h"

//external global varaible Game* game
extern Game* game;

/**This constructor sets the Pixmap for Health
 * @brief Health::Health sets the Pixmap for a Health object.
 * @param parent makes QLabel a parent of Health
 */
Health::Health(QLabel *parent) :  QLabel(parent)
{
    setPixmap(QPixmap(":/new/prefix1/Pokeball.PNG"));
    setStyleSheet("QLabel {background-color: rgba(0,0,0,0%)}");
    setScaledContents(true);
    setMaximumSize(40,40);
    setMinimumSize(40,40);
}

/**This function displays the window after winning the game.
 * @brief Game::win() creates a panel to obscure the background and places a message on the screen along with quit and retry buttons.
 */
void Health::removed(){
    // hide them from the scene
    hide();
    return;
}
