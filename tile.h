/**@file tile.h
 * @brief declaration for the tile class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPainter>

/**@class Tile
 * This class deals with the tiles in the game.
 * @brief The Tile class constructs the tiles for the game.
 */

class Tile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Tile(QGraphicsItem *parent = 0);

signals:

public slots:
};

#endif // TILE_H
