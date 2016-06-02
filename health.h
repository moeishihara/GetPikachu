/**@file health.h
 * @brief declaration for the health class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef HEALTH_H
#define HEALTH_H

#include <QLabel>

/**@class Health
 * This class deals with the health of Ash.
 * @brief The Health class constructs an object type.
 */

class Health : public QLabel
{
    Q_OBJECT
public:
    explicit Health(QLabel *parent = 0);
    void removed();

signals:

public slots:
};
#endif // HEALTH_H
