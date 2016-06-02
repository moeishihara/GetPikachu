/**@file game.h
 * @brief declaration for the game window
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include "ash.h"
#include "pikachu.h"
#include "score.h"
#include "tile.h"
#include "snorlax.h"
#include "muk.h"
#include "beedril.h"
#include "health.h"

namespace Ui {
class Game;
}

/**@class Game
 * This class sets up the game and contains all of the major functions used to display the game and move between levels/screens.
 * @brief The Game class contains functions to start, win, lose, retry, and quit the game.
 */
class Game : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    virtual ~Game();

    // functions for main menu
    //void displayMainMenu();

    // functions for all
    void drawPanel(int x, int y, int width, int height, QBrush brush, double opacity);
    void win();
    void lose();

    // objects for all
    QGraphicsScene* scene;

    // objects for main menu
    QWidget* main_widget;
    QPushButton* newGame;
    QRadioButton* easy;
    QRadioButton* hard;
    QMediaPlayer* menu_music;
    QMediaPlayer* game_music;
    QMediaPlayer* win_music;
    QMediaPlayer* lose_music;

    // objects for instruction
    QLabel* inst_ash;
    QLabel* ash_explanation;
    QHBoxLayout* ash_layout;

    QLabel* inst_pikachu;
    QLabel* pikachu_explanation;
    QHBoxLayout* pikachu_layout;

    QLabel* inst_snorlax;
    QLabel* snorlax_explanation;
    QHBoxLayout* snorlax_layout;

    QLabel* inst_muk;
    QLabel* muk_explanation;
    QHBoxLayout* muk_layout;

    QLabel* inst_beedril;
    QLabel* beedril_explanation;
    QHBoxLayout* beedril_layout;

    QLabel* d_button;
    QLabel* d_button_explanation;
    QHBoxLayout* d_button_layout;

    QLabel* a_button;
    QLabel* a_button_explanation;
    QHBoxLayout* a_button_layout;

    QLabel* space;
    QLabel* space_explanation;
    QHBoxLayout* space_layout;

    QLabel* inst_health;
    QLabel* health_explanation;
    QHBoxLayout* health_layout;

    QLabel* inst_score;
    QLabel* score_explanation;
    QHBoxLayout* score_layout;

    // level
    bool isHard = false;

    // objects for game
    Ash* player_ash;
    Pikachu* pikachu1;
    Pikachu* pikachu2;
    Pikachu* pikachu3;
    Pikachu* pikachu4;
    Pikachu* pikachu5;
    Snorlax* snorlax;
    Muk* muk1;
    Muk* muk2;
    Beedril* beedril1;
    Beedril* beedril2;

    int score = 0;
    bool ash_win = false;
    Score* score1;
    Score* score2;
    Score* score3;
    Score* score4;
    Score* score5;

    int health = 3;
    bool ash_lose = false;
    Health* health1;
    Health* health2;
    Health* health3;

    Tile* tile1;
    Tile* tile2;
    Tile* tile3;
    Tile* tile4;
    Tile* tile5;
    Tile* tile6;
    Tile* tile7;
    Tile* tile8;
    Tile* tile9;
    Tile* tile10;
    Tile* tile11;
    Tile* tile12;
    Tile* tile13;
    Tile* tile14;
    Tile* tile15;
    Tile* tile16;
    Tile* tile17;


public slots:
    void displayMainMenu();
    void game_begin();
    void update_score();
    void update_health();
    void retry();

private:
    Ui::Game *ui;
};

#endif // GAME_H
