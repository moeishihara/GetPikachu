/**@file beedril.h
 * @brief declaration for the beedril class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef BEEDRIL_H
#define BEEDRIL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>
#include "ash.h"

/**@class Beedril
 * This class deals with the moving enemy Beedril in the game.
 * @brief The Beedril class constructs an object type.
 */
class Beedril : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Beedril(QGraphicsItem *parent = 0);
    void setAsh(Ash* player);
    void set_vertical();
    void start_movement();

signals:

public slots:
    void attack();
    void up();
    void down();
    void left();
    void right();
    void move_vertical();
    void move_horizontal();

private:
    QTimer* beedril_timer;
    QTimer* movement_timer;
    bool isVertical = false;
    QMediaPlayer* attack_sound;
    Ash* ash;
};

#endif // BEEDRIL_H
