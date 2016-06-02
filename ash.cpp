/**@file ash.cpp
 * @brief Contains the implementation for the Ash class
 */

#include "ash.h"
#include "snorlax.h"
#include "game.h"
#include <QGraphicsScene>
#include <QList>

//external global varaible Game* game
extern Game* game;

/**This constructor sets the Pixmap for Ash
 * @brief Ash::Ash sets the Pixmap for a Ash object.
 * @param parent makes QGraphicsPixmapItem a parent of Ash
 */
Ash::Ash(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/prefix1/Ash.png"));
    setScale(.08);
    setPos(0,465-boundingRect().height()*0.08);

    ash_timer = new QTimer(this);
    connect(ash_timer, SIGNAL(timeout()), this, SLOT(moveEvent()));

    // start the timer
    ash_timer->start(40);

    // add sound
    jump_sound = new QMediaPlayer();
    jump_sound->setMedia(QUrl("qrc:/sounds/sound/Mario_Jumping-Mike_Koenig-989896458.mp3"));
}

/**This is the keyPressEvent function that responds to keys being pressed on the keyboard.
 * @brief Ash::keyPressEvent will move Ash depending on the key pressed.
 * @param event is the key that is pressed
 */
void Ash::keyPressEvent(QKeyEvent *event){
    //if A key is pressed, and Ash's x position is greater than 0, move left 10 pixels
    if(event->key()==Qt::Key_A) moveLeft = true;
    //if D key is pressed, and Ash's y position is less than 1150, move right 10 pixels
    else if(event->key()==Qt::Key_D) moveRight = true;
    //if space key is pressed, jump
    else if(event->key()==Qt::Key_Space) jump();
}

/**This is the keyReleaseEvent function that responds to keys being released on the keyboard.
 * @brief Ash::keyReleaseEvent will stop Ash moving right or left depending on the key released.
 * @param event is the key that is released
 */
void Ash::keyReleaseEvent(QKeyEvent * event){
    if (event->key() == Qt::Key_D) moveRight = false;
    else if (event->key() == Qt::Key_A) moveLeft = false;
}

/**This is the jump function that responds to the shift key being pressed on the keyboard.
 * @brief Ash::jump() will make Ash jump when the shit key is pressed.
 */
void Ash::jump(){
    if (isJumping == false) {
        y_velocity = -15;
        isJumping = true;
    }
}

/**This is the function that detects if Ash is on Snorlax.
 * @brief Ash::onSnorlax() will check if it collides with snorlax and react to collision
 * @returns true if colliding item is Snorlax
 */
bool Ash::onSnorlax() {
    QList<QGraphicsItem*> colliding_items = collidingItems();

    // if one of the colliding items is a snorlax, jump higher than usual
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Snorlax)) return true;
    }
    return false;
}

/**This is a public slot that manages Ash's movement.
 * @brief Ash::moveEvent() will move Ash according to various signals
 */
void Ash::moveEvent(){
    // check if ash is neither win nor lose
    if (!game->ash_win && !game->ash_lose) {
        if (moveLeft) {
            if (pos().x()>0) setPos(x()-x_velocity,y());
        }
        else if (moveRight) {
            if (pos().x()<1150) setPos(x()+x_velocity,y());
        }
        if (isJumping) {
            y_velocity += gravity;
            setPos(x(),y()+y_velocity);
            // super jump if on snorlax
            if (onSnorlax()) {
                y_velocity = -17;
                // play jump sound
                if (jump_sound->state() == QMediaPlayer::PlayingState) jump_sound->setPosition(0);
                else if (jump_sound->state() == QMediaPlayer::StoppedState) jump_sound->play();
            }
            if (pos().y() > 465-boundingRect().height()*0.08) {
                setPos(x(),465-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
            if (pos().y()>=372-boundingRect().height()*0.08 && pos().y()<380-boundingRect().height()*0.08 && pos().x()>=285 && pos().x()<=431.8) {
                setPos(x(),372-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
            if (pos().y()>=290-boundingRect().height()*0.08 && pos().y()<293-boundingRect().height()*0.08 && pos().x()>=35 && pos().x()<=181.8) {
                setPos(x(),290-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
            if (pos().y()>=372-boundingRect().height()*0.08 && pos().y()<380-boundingRect().height()*0.08 && pos().x()>=585 && pos().x()<=860){
                setPos(x(),372-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
            if (pos().y()>=250-boundingRect().height()*0.08 && pos().y()<260-boundingRect().height()*0.08 && pos().x()>=985 && pos().x()<=1131.8) {
                setPos(x(),250-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
            if (pos().y()>=180-boundingRect().height()*0.08 && pos().y()<190-boundingRect().height()*0.08 && pos().x()>=685 && pos().x()<=831.8) {
                setPos(x(),180-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
            if (pos().y()>=100-boundingRect().height()*0.08 && pos().y()<110-boundingRect().height()*0.08 && pos().x()>=485 && pos().x()<=631.8) {
                setPos(x(),100-boundingRect().height()*0.08);
                y_velocity = 0;
                isJumping = false;
            }
        }

        if (!isJumping) {
            if (pos().y() == 100-boundingRect().height()*0.08 && (pos().x() <485 || pos().x()>631.8)) isJumping = true;
            else if (pos().y() == 180-boundingRect().height()*0.08 && (pos().x()>831.8 || pos().x() <685)) isJumping = true;
            else if (pos().y() == 250-boundingRect().height()*0.08 && (pos().x() <985 || pos().x()>1131.8)) isJumping = true;
            else if (pos().y() == 290-boundingRect().height()*0.08 && (pos().x() <35 || pos().x() >181.8)) isJumping = true;
            else if (pos().y() == 372-boundingRect().height()*0.08 && (pos().x() <285 || (pos().x()>431.8 && pos().x()<585) || pos().x()>860)) isJumping = true;
        }
    }
}

/**This function changes Ash's pixmap.
 * @brief changes Ash's pixmap and returns to the original after 500 milliseconds
 */
void Ash::damaged(){
    setPixmap(QPixmap(":/new/prefix1/Ash_damaged.png"));
    QTimer::singleShot(500,this,SLOT(originalPixmap()));
}


/**This is a public slot that sets Ash's Pixmap to the original one.
 * */
void Ash::originalPixmap(){
    setPixmap(QPixmap(":/new/prefix1/Ash.png"));
}
