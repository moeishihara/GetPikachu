/**@file muk.cpp
 * @brief Contains the implementation for the Muk class
 */

#include "muk.h"
#include "game.h"
#include <QGraphicsScene>
#include <QList>

//external global varaible Game* game
extern Game* game;

/**This constructor sets the Pixmap for Muk
 * @brief Muk::Muk sets the Pixmap for a Muk object.
 * @param parent makes QGraphicsPixmapItem a parent of Muk
 */
Muk::Muk(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/new/prefix1/Muk.png"));
    setScale(.5);

    // make/connect a timer to attack()
    muk_timer = new QTimer(this);
    connect(muk_timer, SIGNAL(timeout()), this, SLOT(attack()));

    // start the timer
    muk_timer->start(100);

    // add attack sound
    attack_sound = new QMediaPlayer();
    attack_sound->setMedia(QUrl("qrc:/sounds/sound/Strong_Punch-Mike_Koenig-574430706.mp3"));
}

/**@ set Ash
*/
void Muk::setAsh(Ash* player){
    ash = player;
}

/**@ implement Muk attacking Ash
 * @ check if it collides with the player and react to collision
 * @ decrease a health if collision
*/
void Muk::attack(){
    if (!game->ash_win && !game->ash_lose){
        QList<QGraphicsItem*> colliding_items = collidingItems();

        // if one of the colliding items is an player, decrease a health
        for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Ash)){
                // change ash's color
                ash->damaged();
                // play sound
                if (attack_sound->state() == QMediaPlayer::PlayingState) attack_sound->setPosition(0);
                else if (attack_sound->state() == QMediaPlayer::StoppedState) attack_sound->play();
                // decrease health
                game->health--;
                muk_timer->stop();
                 QTimer::singleShot(600,muk_timer,SLOT(start()));
                return;
            }
         }
    }
    else {
        scene()->removeItem(this);
        // delete them from the heap to save memory
        delete this;
        return;
    }
}

/**@ creates and connect QTimer based on the movement
 */
void Muk::start_movement(){
    // make/connect the movement_timer
    movement_timer = new QTimer(this);
    move_horizontal();
    connect (movement_timer, SIGNAL(timeout()), this, SLOT(move_horizontal()));

    // start the movement timer
    movement_timer->start(2800);
}

/**@ implement the micro movements of Beedril
*/
void Muk::left(){
    setPos(x()-25,y());
}

void Muk::right(){
    setPos(x()+25,y());
}

/**@ implement horizontal animation of Beedril
*/
void Muk::move_horizontal(){
    if (!game->ash_win && !game->ash_lose) {
        QTimer::singleShot(300,this,SLOT(left()));
        QTimer::singleShot(650,this,SLOT(left()));
        QTimer::singleShot(1000,this,SLOT(right()));
        QTimer::singleShot(1350,this,SLOT(right()));
        QTimer::singleShot(1700,this,SLOT(right()));
        QTimer::singleShot(2050,this,SLOT(right()));
        QTimer::singleShot(2400,this,SLOT(left()));
        QTimer::singleShot(2750,this,SLOT(left()));
    }
}
