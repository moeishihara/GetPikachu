/**@file snorlax.cpp
 * @brief Contains the implementation for the snorlax class
 */

#include "snorlax.h"
#include "ash.h"
#include "game.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>

//external global varaible Game* game
extern Game* game;

/**This constructor sets the Pixmap for Snorlax
 * @brief Snorlax::Snorlax sets the Pixmap for a Snorlax object.
 * @param parent makes QGraphicsPixmapItem a parent of Snorlax
 */
Snorlax::Snorlax(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/prefix1/Snorlax.gif"));
    setScale(.2);
    setPos(800,345);
}

/**This constructor sets the Pixmap for Button
 * @brief Button::Button sets the Pixmap for a Button object.
 * @param parent makes QGraphicsPixmapItem a parent of Button
 */
Button::Button(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/prefix1/Button.png"));
    setScale(.13);
    setPos(20,270);

    // make/connect a timer to turnedOn()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(turnedOn()));

    // start the timer
    timer->start(100);

    // add button sound
    button_sound = new QMediaPlayer();
    button_sound->setMedia(QUrl("qrc:/sounds/sound/beep18.mp3"));
}

/**@ implement Ash turning on the button
 * @ check if it collides with the player and react to collision
 * @ delete if collision
*/
void Button::turnedOn(){
    QList<QGraphicsItem*> colliding_items = collidingItems();

    // if one of the colliding items is an player, increast the score
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Ash)){
            // play button sound
            button_sound->play();
            // create a new Snorlax
            Snorlax* snorlax2 = new Snorlax;
            snorlax2->setPos(100,260);
            game->scene->addItem(snorlax2);
            // remove them from the scene (still on the heap)
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete this;
            return;
        }
     }
}
