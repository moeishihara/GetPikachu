/**@file game.cpp
 * @brief Contains the implementation for the Game class
 */

#include "game.h"
#include "ui_game.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

//external global varaible Game* game
extern Game* game;

/**This constructor creates a new scene for the game to take place in
 * @brief Game::Game constructor creates a new QGraphicsScene, sets its Pixmap and sets its size
 * @param parent of Game is QGraphicsView
 */
Game::Game(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    // create a new QGraphicsScene
    scene = new QGraphicsScene();
    // set the size of the scene
    scene->setSceneRect(0,0,1200,500);
    // set the background
    setBackgroundBrush(QBrush(QImage(":/new/prefix1/country-field.png").scaledToWidth(1200)));

    setScene(scene);
    //turn off vertical and horizontal scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //set size of the scene
    setFixedSize(1200, 500);

    // set up all music
    menu_music = new QMediaPlayer();
    menu_music->setMedia(QUrl("qrc:/sounds/sound/101-opening.mp3"));
    game_music = new QMediaPlayer();
    game_music->setMedia(QUrl("qrc:/sounds/sound/107-battle-vs-wild-pokemon-.mp3"));
    win_music = new QMediaPlayer();
    win_music->setMedia(QUrl("qrc:/sounds/sound/108-victory-vs-wild-pokemon-.mp3"));
    lose_music = new QMediaPlayer();
    lose_music->setMedia(QUrl("qrc:/sounds/sound/fail-trombone-02.mp3"));
}

/**This is the destructor for the Game class
 * @brief Game::~Game destroys ui
 */
Game::~Game()
{
    delete ui;
}

/**This function displays the main menu at the beginning of the game.
 * @brief Game::displayMainMenu() clears the scene, shows the title, shows the instructions, and has QRadioButtons
 *        that let the player choose the level of difficulty and a new game QPushButton that starts the game.
 */
void Game::displayMainMenu(){
    scene->clearFocus();
    scene->clear();

    main_widget = new QWidget;
    main_widget->setFixedSize(800,400);

    QLabel* title = new QLabel;
    title->setPixmap(QPixmap(":/new/prefix1/title.png").scaledToHeight(100));
    title->setAlignment(Qt::AlignCenter);

    // ash instruction
    inst_ash = new QLabel(this);
    inst_ash->setPixmap(QPixmap(":/new/prefix1/Ash.png"));
    inst_ash->setScaledContents(true);
    inst_ash->setMinimumSize(40,40);
    inst_ash->setMaximumSize(40,40);

    ash_explanation = new QLabel("Player Ash");
    ash_layout = new QHBoxLayout;
    ash_layout->addWidget(inst_ash);
    ash_layout->addWidget(ash_explanation);

    // pikachu instruction
    inst_pikachu = new QLabel(this);
    inst_pikachu->setPixmap(QPixmap(":/new/prefix1/Pikachu.png"));
    inst_pikachu->setScaledContents(true);
    inst_pikachu->setMinimumSize(40,40);
    inst_pikachu->setMaximumSize(40,40);

    pikachu_explanation = new QLabel("Ash's best friend");
    pikachu_layout = new QHBoxLayout;
    pikachu_layout->addWidget(inst_pikachu);
    pikachu_layout->addWidget(pikachu_explanation);

    // snorlax instruction
    inst_snorlax = new QLabel(this);
    inst_snorlax->setPixmap(QPixmap(":/new/prefix1/Snorlax.gif"));
    inst_snorlax->setScaledContents(true);
    inst_snorlax->setMinimumSize(40,40);
    inst_snorlax->setMaximumSize(40,40);

    snorlax_explanation = new QLabel("Helps Ash jump higher");
    snorlax_layout = new QHBoxLayout;
    snorlax_layout->addWidget(inst_snorlax);
    snorlax_layout->addWidget(snorlax_explanation);

    // muk instruction
    inst_muk = new QLabel(this);
    inst_muk->setPixmap(QPixmap(":/new/prefix1/Muk.png"));
    inst_muk->setScaledContents(true);
    inst_muk->setMinimumSize(40,40);
    inst_muk->setMaximumSize(40,40);

    muk_explanation = new QLabel("Don't touch");
    muk_layout = new QHBoxLayout;
    muk_layout->addWidget(inst_muk);
    muk_layout->addWidget(muk_explanation);

    // beedril instruction
    inst_beedril = new QLabel(this);
    inst_beedril->setPixmap(QPixmap(":/new/prefix1/Beedrill.png"));
    inst_beedril->setScaledContents(true);
    inst_beedril->setMinimumSize(40,40);
    inst_beedril->setMaximumSize(40,40);

    beedril_explanation = new QLabel("Don't touch");
    beedril_layout = new QHBoxLayout;
    beedril_layout->addWidget(inst_beedril);
    beedril_layout->addWidget(beedril_explanation);

    // add first half of the instruction to a layout
    QVBoxLayout* inst1 = new QVBoxLayout;
    inst1->addLayout(ash_layout);
    inst1->addLayout(pikachu_layout);
    inst1->addLayout(snorlax_layout);
    inst1->addLayout(muk_layout);
    inst1->addLayout(beedril_layout);

    // D button instruction
    d_button = new QLabel("D");
    d_button->setScaledContents(true);
    d_button->setMinimumSize(40,40);
    d_button->setMaximumSize(40,40);
    d_button->setStyleSheet("border: 2px solid black");

    d_button_explanation = new QLabel("Move Ash to the right");
    d_button_layout = new QHBoxLayout;
    d_button_layout->addWidget(d_button);
    d_button_layout->addWidget(d_button_explanation);

    // A button instruction
    a_button = new QLabel("A");
    a_button->setScaledContents(true);
    a_button->setMinimumSize(40,40);
    a_button->setMaximumSize(40,40);
    a_button->setStyleSheet("border: 2px solid black");


    a_button_explanation = new QLabel("Move Ash to the left");
    a_button_layout = new QHBoxLayout;
    a_button_layout->addWidget(a_button);
    a_button_layout->addWidget(a_button_explanation);

    // Space button instruction
    space = new QLabel("Space");
    space->setScaledContents(true);
    space->setMinimumSize(80,40);
    space->setMaximumSize(80,40);
    space->setStyleSheet("border: 2px solid black");


    space_explanation = new QLabel("Jump!");
    space_layout = new QHBoxLayout;
    space_layout->addWidget(space);
    space_layout->addWidget(space_explanation);

    // health instruction
    inst_health = new QLabel(this);
    inst_health->setPixmap(QPixmap(":/new/prefix1/Pokeball.PNG"));
    inst_health->setScaledContents(true);
    inst_health->setMinimumSize(40,40);
    inst_health->setMaximumSize(40,40);

    health_explanation = new QLabel("Game over when lose 3 Pokeballs");
    health_layout = new QHBoxLayout;
    health_layout->addWidget(inst_health);
    health_layout->addWidget(health_explanation);

    // score instruction
    inst_score = new QLabel(this);
    inst_score->setPixmap(QPixmap(":/new/prefix1/wild_pikachu.png"));
    inst_score->setScaledContents(true);
    inst_score->setMinimumSize(40,40);
    inst_score->setMaximumSize(40,40);

    score_explanation = new QLabel("Win when get 5 Pikachus");
    score_layout = new QHBoxLayout;
    score_layout->addWidget(inst_score);
    score_layout->addWidget(score_explanation);

    // add second half of the instruction to a layout
    QVBoxLayout* inst2 = new QVBoxLayout;
    inst2->addLayout(d_button_layout);
    inst2->addLayout(a_button_layout);
    inst2->addLayout(space_layout);
    inst2->addLayout(health_layout);
    inst2->addLayout(score_layout);

    // add all instructions to a layout
    QHBoxLayout* inst = new QHBoxLayout;
    inst->addLayout(inst1);
    inst->addLayout(inst2);


    easy = new QRadioButton("Easy");
    easy->setChecked(true);
    hard = new QRadioButton("Hard");

    // add all QRadioButtons to a layout
    QVBoxLayout* radioButtons = new QVBoxLayout;
    radioButtons->addWidget(easy);
    radioButtons->addWidget(hard);

    newGame = new QPushButton;
    newGame->setText("New Game");
    connect(newGame,SIGNAL(clicked()),this,SLOT(game_begin()));

    // add all buttons to a layout
    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->addLayout(radioButtons);
    buttons->addWidget(newGame);

    // add everything to a layout
    QVBoxLayout* everything = new QVBoxLayout;
    everything->addWidget(title);
    everything->addLayout(inst);
    everything->addLayout(buttons);

    // set the layout of the main widget
    main_widget->setLayout(everything);

    // play menu music
    menu_music->play();

    main_widget->show();

}

/**This is a public slot that adds all of the necessary components for game play to the scene.
 * @brief Game::game_begin() adds objects of classes Ash, Pikachu, Snorlax, Muk,
 *        Beedrill, Tile, Score, and Health to the scene and then begins the game.
 */
void Game::game_begin() {
    // play game music
    game_music->play();

    // stop menu music
    menu_music->stop();

    // close the main manu
    main_widget->close();

    //if retrying game again, clear away the game over window
    scene->clearFocus();
    scene->clear();

    // set the level
    if (hard->isChecked()) isHard = true;

    // Create an Ash object player
    player_ash = new Ash;
    // make the player focusable and set it to be the current focus
    player_ash->setFlag(QGraphicsItem::ItemIsFocusable);
    player_ash->setFocus();
    // add the player to the scene
    scene->addItem(player_ash);

    // Create five Pikachu objects
    pikachu1 = new Pikachu;
    if (!isHard) pikachu1->setPos(50,240);
    else pikachu1->setPos(100,70);
    pikachu1->setSound(QUrl("qrc:/sounds/sound/pikachuuu.wav"));
    scene->addItem(pikachu1);

    pikachu2 = new Pikachu;
    if (!isHard) pikachu2->setPos(250,412);
    else pikachu2->setPos(180,412);
    pikachu2->setSound(QUrl("qrc:/sounds/sound/pika.wav"));
    scene->addItem(pikachu2);

    pikachu3 = new Pikachu;
    pikachu3->setPos(543,45);
    pikachu3->setSound(QUrl("qrc:/sounds/sound/pikachu.wav"));
    scene->addItem(pikachu3);

    pikachu4 = new Pikachu;
    if (!isHard) pikachu4->setPos(610,323);
    else pikachu4->setPos(500,350);
    pikachu4->setSound(QUrl("qrc:/sounds/sound/pikapi.wav"));
    scene->addItem(pikachu4);

    pikachu5 = new Pikachu;
    if (!isHard) pikachu5->setPos(1150,410);
    else pikachu5->setPos(1100,410);
    pikachu5->setSound(QUrl("qrc:/sounds/sound/pika.wav"));
    scene->addItem(pikachu5);

    // Create a snorlax
    snorlax = new Snorlax;
    scene->addItem(snorlax);

    // Create a button in hard mode
    if (isHard) {
        Button* button = new Button;
        scene->addItem(button);
    }

    // Create two muk objects
    muk1 = new Muk;
    muk1->setAsh(player_ash);
    muk1->setPos(100,412);
    if(isHard) muk1->start_movement();
    scene->addItem(muk1);

    muk2 = new Muk;
    muk2->setAsh(player_ash);
    muk2->setPos(740,130);
    if (isHard) muk2->start_movement();
    scene->addItem(muk2);

    if (isHard) {
        Muk* muk3 = new Muk;
        muk3->setAsh(player_ash);
        muk3->setPos(480,412);
        muk3->start_movement();
        scene->addItem(muk3);
    }

    // Create two beedril objects
    beedril1 = new Beedril;
    beedril1->setAsh(player_ash);
    beedril1->setPos(480,250);
    beedril1->set_vertical();
    beedril1->start_movement();
    scene->addItem(beedril1);

    beedril2 = new Beedril;
    beedril2->setAsh(player_ash);
    beedril2->setPos(1000,400);
    beedril2->start_movement();
    scene->addItem(beedril2);

    if (isHard) {
        Beedril* beedril3 = new Beedril;
        beedril3->setAsh(player_ash);
        beedril3->setPos(100,115);
        beedril3->start_movement();
        scene->addItem(beedril3);
    }

    // set up a score box
    score1 = new Score;
    score1->setGeometry(1000,0,40,40);
    scene->addWidget(score1);

    score2 = new Score;
    score2->setGeometry(1040,0,40,40);
    scene->addWidget(score2);

    score3 = new Score;
    score3->setGeometry(1080,0,40,40);
    scene->addWidget(score3);

    score4 = new Score;
    score4->setGeometry(1120,0,40,40);
    scene->addWidget(score4);

    score5 = new Score;
    score5->setGeometry(1160,0,40,40);
    scene->addWidget(score5);

    // set up health points
    health1 = new Health;
    health1->setGeometry(0,0,40,40);
    scene->addWidget(health1);

    health2 = new Health;
    health2->setGeometry(40,0,40,40);
    scene->addWidget(health2);

    health3 = new Health;
    health3->setGeometry(80,0,40,40);
    scene->addWidget(health3);

    // set up tiles
    tile1 = new Tile;
    tile1->setPos(0,465);
    scene->addItem(tile1);

    tile2 = new Tile;
    tile2->setPos(tile1->boundingRect().width()*0.2,465);
    scene->addItem(tile2);

    tile3 = new Tile;
    tile3->setPos(tile1->boundingRect().width()*0.4,465);
    scene->addItem(tile3);

    tile4 = new Tile;
    tile4->setPos(tile1->boundingRect().width()*0.6,465);
    scene->addItem(tile4);

    tile5 = new Tile;
    tile5->setPos(tile1->boundingRect().width()*0.8,465);
    scene->addItem(tile5);

    tile6 = new Tile;
    tile6->setPos(tile1->boundingRect().width(),465);
    scene->addItem(tile6);

    tile7 = new Tile;
    tile7->setPos(tile1->boundingRect().width()*1.2,465);
    scene->addItem(tile7);

    tile8 = new Tile;
    tile8->setPos(tile1->boundingRect().width()*1.4,465);
    scene->addItem(tile8);

    tile9 = new Tile;
    tile9->setPos(tile1->boundingRect().width()*1.6,465);
    scene->addItem(tile9);

    tile10 = new Tile;
    tile10->setPos(tile1->boundingRect().width()*1.8,465);
    scene->addItem(tile10);

    tile11 = new Tile;
    tile11->setPos(300,372);
    scene->addItem(tile11);

    tile12 = new Tile;
    tile12->setPos(50,290);
    scene->addItem(tile12);

    tile13 = new Tile;
    tile13->setPos(600,372);
    scene->addItem(tile13);

    tile14 = new Tile;
    tile14->setPos(600+tile1->boundingRect().width()*0.2,372);
    scene->addItem(tile14);

    tile15 = new Tile;
    tile15->setPos(1000,250);
    scene->addItem(tile15);

    tile16 = new Tile;
    tile16->setPos(700,180);
    scene->addItem(tile16);

    tile17 = new Tile;
    tile17->setPos(500,100);
    scene->addItem(tile17);

    //show the scene
    show();

    QTimer* statustimer = new QTimer(this);
    connect(statustimer, SIGNAL(timeout()), this, SLOT(update_score()));
    connect(statustimer,SIGNAL(timeout()),this,SLOT(update_health()));
    statustimer->start(100);
}

/**This is a public slot that updates the score
 * @brief Game::update_score() changes score objects's Pixmap according to the score
 */
void Game::update_score(){
    if (!ash_win && !ash_lose){
        if (score == 1)
            score1->changePixmap();
        else if (score == 2)
            score2->changePixmap();
        else if (score == 3)
            score3->changePixmap();
        else if (score == 4)
            score4->changePixmap();
        else if (score >= 5) {
            score = 5;
            score5->changePixmap();
            win();
        }
    }
}

/**This is a public slot that updates the health
 * @brief Game::update_health() removes Health objects according to the health
 */
void Game::update_health() {
    if (!ash_win && !ash_lose){
        if (health >= 3) health = 3;
        else if (health == 2) health3->removed();
        else if (health == 1) health2->removed();
        else if (health <= 0) {
            health = 0;
            health1->removed();
            lose();
        }
    }
}

/**This is a public slot that starts the game again
 * @brief Game::retry() closes the current attempt and opens another one, showing the main menu for the game
 */
void Game::retry(){
    win_music->stop();
    lose_music->stop();
    scene->removeItem(player_ash);
    close();
    game = new Game();
    game->show();
    game->displayMainMenu();
}

/**This function draws a panel depending on the inputs
 * @brief Game::drawPanel draws a panel at the position (x, y) with width of width, height of height, color of color, and opacity of opacity.
 * @param x is the x() position of the top left corner of the panel
 * @param y is the y() position of the top left corner of the panel
 * @param width is the integer width of the panel
 * @param height is the integer height of the panel
 * @param color is the color of the panel
 * @param opacity is the percent opaque the panel is, between 0 and 1.
 */
void Game::drawPanel(int x, int y, int width, int height, QBrush brush, double opacity){
    QGraphicsRectItem* panel= new QGraphicsRectItem(x, y, width, height);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

/**This function displays the window after winning the game.
 * @brief Game::win() creates a panel to obscure the background and places a message on the screen along with quit and retry buttons.
 */
void Game::win(){
    // play win music
    win_music->play();

    // stop game music
    game_music->stop();

    ash_win = true;

    clearFocus();
    drawPanel(400,0,400,400,QBrush(QImage(":/new/prefix1/Ca1P-6TVAAE6x19.jpg").scaledToWidth(400)), 1);
    QGraphicsTextItem* message= new QGraphicsTextItem("YOU WON!!");
    message->setFont(QFont("Gill Sans",40));
    message->setPos(500, 100);
    scene->addItem(message);

    QPushButton* quit_button= new QPushButton("Quit");
    quit_button->setGeometry(450, 200, 80, 40);
    scene->addWidget(quit_button);

    QPushButton* retry_button = new QPushButton("Retry");
    retry_button->setGeometry(650,200,80,40);
    scene->addWidget(retry_button);

    QObject::connect(quit_button, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(retry_button,SIGNAL(clicked(bool)),this,SLOT(retry()));
}

/**This function displays the window after losing the game.
 * @brief Game::lose() creates a panel to obscure the background and places a message on the screen along with quit and retry buttons.
 */
void Game::lose(){
    // play lose music
    lose_music->play();

    // stop game music
    game_music->stop();

    ash_lose = true;
    clearFocus();
    drawPanel(400,0,400,400,QBrush(QImage(":/new/prefix1/sad_pika.png").scaledToWidth(400)), 1);
    QGraphicsTextItem* message= new QGraphicsTextItem("GAME OVER");
    message->setDefaultTextColor(Qt::red);
    message->setFont(QFont("Gill Sans",40));
    message->setPos(500, 75);
    scene->addItem(message);

    QPushButton* quit_button= new QPushButton("Quit");
    quit_button->setGeometry(450, 200, 80, 40);
    scene->addWidget(quit_button);

    QPushButton* retry_button = new QPushButton("Retry");
    retry_button->setGeometry(650,200,80,40);
    scene->addWidget(retry_button);

    QObject::connect(quit_button, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(retry_button,SIGNAL(clicked(bool)),this,SLOT(retry()));
}
