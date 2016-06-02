/**@file ash.h
 * @brief declaration for the ash class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef ASH_H
#define ASH_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMediaPlayer>

/**@class Ash
 * This class deals with the player Ash in the game.
 * @brief The Ash class constructs the player for the first task and moves an object of type Ash.
 */

class Ash : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ash(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void jump();
    bool onSnorlax();
    void damaged();

signals:

public slots:
    void moveEvent();
    void originalPixmap();

private:
    QTimer* ash_timer;
    double x_velocity = 10;
    double y_velocity = 0;
    double gravity = 1.2;
    bool isJumping = false;
    bool moveRight = false;
    bool moveLeft = false;
    QMediaPlayer* jump_sound;
};


#endif // ASH_H
