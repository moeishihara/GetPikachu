/**@file muk.h
 * @brief declaration for the muk class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef MUK_H
#define MUK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>
#include "ash.h"

/**@class Muk
 * This class deals with the enemy Muk in the game.
 * @brief The Muk class constructs an object type.
 */
class Muk : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Muk(QGraphicsItem *parent = 0);
    void setAsh(Ash* player);
    void start_movement();

signals:

public slots:
    void attack();
    void left();
    void right();
    void move_horizontal();

private:
    QTimer* muk_timer;
    QTimer* movement_timer;
    QMediaPlayer* attack_sound;
    Ash* ash;
};

#endif // MUK_H
