/**@file beedril.cpp
 * @brief Contains the implementation for the Beedril class
 */

#include "beedril.h"
#include "game.h"
#include <QGraphicsScene>
#include <QList>

//external global varaible Game* game
extern Game* game;


/**This constructor sets the Pixmap for Beedril
 * @brief Beedril::Beedril sets the Pixmap for a Beedril object.
 * @param parent makes QGraphicsPixmapItem a parent of Beedril
 */
Beedril::Beedril(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/new/prefix1/Beedrill.png"));
    setScale(.25);

    // make/connect a timer to attack()
    beedril_timer = new QTimer(this);
    connect(beedril_timer, SIGNAL(timeout()), this, SLOT(attack()));

    // start the timer
    beedril_timer->start(100);

    // add attack sound
    attack_sound = new QMediaPlayer();
    attack_sound->setMedia(QUrl("qrc:/sounds/sound/Strong_Punch-Mike_Koenig-574430706.mp3"));
}

/**@ set Ash
*/
void Beedril::setAsh(Ash* player){
    ash = player;
}

/**@ implement Beedril attacking Ash
 * @ check if it collides with the player and react to collision
 * @ decrease a health if collision
*/
void Beedril::attack(){
    if (!game->ash_win && !game->ash_lose) {
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
                beedril_timer->stop();
                QTimer::singleShot(600,beedril_timer,SLOT(start()));
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

/**@ determines if the movement is vertical
*/
void Beedril::set_vertical() {
    isVertical = true;
}

/**@ creates and connect QTimer based on the movement
*/
void Beedril::start_movement(){
    // make/connect the movement_timer
    movement_timer = new QTimer(this);
    if (isVertical) {
        move_vertical();
        connect (movement_timer, SIGNAL(timeout()), this, SLOT(move_vertical()));
    }
    else {
        move_horizontal();
        connect (movement_timer, SIGNAL(timeout()), this, SLOT(move_horizontal()));
    }
    // start the movement timer
    movement_timer->start(3200);
}


/**@ implement the micro movements of Beedril
*/
void Beedril::up(){
    setPos(x(),y()-30);
}

void Beedril::down(){
    setPos(x(),y()+30);
}

void Beedril::left(){
    setPos(x()-30,y());
}

void Beedril::right(){
    setPos(x()+30,y());
}

/**@ implement vertical animation of Beedril
*/
void Beedril::move_vertical(){
    if (!game->ash_win && !game->ash_lose) {
        QTimer::singleShot(200,this,SLOT(up()));
        QTimer::singleShot(600,this,SLOT(up()));
        QTimer::singleShot(1000,this,SLOT(down()));
        QTimer::singleShot(1400,this,SLOT(down()));
        QTimer::singleShot(1800,this,SLOT(down()));
        QTimer::singleShot(2200,this,SLOT(down()));
        QTimer::singleShot(2600,this,SLOT(up()));
        QTimer::singleShot(3000,this,SLOT(up()));
    }
}


/**@ implement horizontal animation of Beedril
*/
void Beedril::move_horizontal(){
    if (!game->ash_win && !game->ash_lose) {
        QTimer::singleShot(200,this,SLOT(left()));
        QTimer::singleShot(600,this,SLOT(left()));
        QTimer::singleShot(1000,this,SLOT(right()));
        QTimer::singleShot(1400,this,SLOT(right()));
        QTimer::singleShot(1800,this,SLOT(right()));
        QTimer::singleShot(2200,this,SLOT(right()));
        QTimer::singleShot(2600,this,SLOT(left()));
        QTimer::singleShot(3000,this,SLOT(left()));
    }
}
