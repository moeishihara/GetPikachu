/**@file score.h
 * @brief declaration for the Score class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef SCORE_H
#define SCORE_H

#include <QLabel>

/**@class Score
 * This class deals with the score of the game.
 * @brief The Score class constructs an object type.
 */

class Score : public QLabel
{
    Q_OBJECT
public:
    explicit Score(QLabel *parent = 0);
    void changePixmap();

signals:

public slots:
};

#endif // SCORE_H
