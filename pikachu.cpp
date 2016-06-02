/**@file pikachu.cpp
 * @brief Contains the implementation for the Pikachu class
 */

#include "pikachu.h"
#include "game.h"
#include "ash.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

//external global varaible Game* game
extern Game* game;

/**
 * This constructor sets the Pixmap for Pikachu
 * @brief Pikachu::Pikachu sets the Pixmap for a Pikachu object.
 * @param parent makes QGraphicsPixmapItem a parent of Pikachu
 */
Pikachu::Pikachu(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/new/prefix1/Pikachu.png"));
    setScale(.2);

    // make/connect a timer to caught()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(caught()));

    // start the timer
    timer->start(100);

    // add score sound
    score_sound = new QMediaPlayer();
}

/**@ sets sound file
*/
void Pikachu::setSound(QUrl sound) {
    score_sound->setMedia(sound);
}

/**@ implement Ash catching a Pikachu
 * @ check if it collides with the player and react to collision
 * @ delete if collision
*/
void Pikachu::caught(){
    QList<QGraphicsItem*> colliding_items = collidingItems();

    // if one of the colliding items is an player, increast the score
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Ash)){
            // play sound
            score_sound->play();
            // increase score
            game->score++;
            // remove them from the scene (still on the heap)
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete this;
            return;
        }
     }
}
