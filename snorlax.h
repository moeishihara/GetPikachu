/**@file snorlax.h
 * @brief declaration for the snorlax class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef SNORLAX_H
#define SNORLAX_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMediaPlayer>

/**@class Snorlax
 * This class deals with the Snorlax helping Ash jump.
 * @brief The Snorlax class constructs the snorlax in the game.
 */

class Snorlax : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Snorlax(QGraphicsItem *parent = 0);
};

/**@class Button
 * This class deals with the button in hard mode.
 * @brief The Button class constructs the button in the hard mode.
 */
class Button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Button(QGraphicsItem *parent = 0);
public slots:
    void turnedOn();
private:
    QMediaPlayer* button_sound;
};

#endif // SNORLAX_H
