/**@file tile.cpp
 * @brief Contains the implementation for the tile class
 */

#include "tile.h"
#include "game.h"
#include <QGraphicsScene>

//external global varaible Game* game
extern Game* game;

/**This constructor sets the Pixmap for Tile
 * @brief Tile::Tile sets the Pixmap for a Tile object.
 * @param parent makes QGraphicsPixmapItem a parent of Tile
 */

Tile::Tile(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/prefix1/bronze_tile_walkway.png"));
    setScale(.2);
}
