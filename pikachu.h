/**@file pikachu.h
 * @brief declaration for the pikachu class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef PIKACHU_H
#define PIKACHU_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMediaPlayer>

/**@class Pikachu
 * This class deals with Pikachus in the game.
 * @brief The Pikachu class constructs an object type.
 */
class Pikachu : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Pikachu(QGraphicsItem *parent = 0);
    void setSound(QUrl sound);
signals:

public slots:
    void caught();
private:
    QMediaPlayer* score_sound;
};

#endif // PIKACHU_H

