/**@file score.cpp
 * @brief Contains the implementation for the Score class
 */

#include "score.h"
#include "game.h"

//external global varaible Game* game
extern Game* game;

/**This constructor sets the Pixmap for Score
 * @brief Score::Score sets the Pixmap for a Score object.
 * @param parent makes QLabel a parent of Score
 */
Score::Score(QLabel *parent) :  QLabel(parent)
{
    setPixmap(QPixmap(":/new/prefix1/wild_pikachu.png"));
    setStyleSheet("QLabel {background-color: rgba(0,0,0,0%)}");
    setScaledContents(true);
    setMaximumSize(40,40);
    setMinimumSize(40,40);
}

/**This function changes the Pixmap of a Score object
 * @brief Score::changePixmap() sets a different Pixmap for a Score object .
 */
void Score::changePixmap(){
    setPixmap(QPixmap(":/new/prefix1/your_pikachu.png"));
}
