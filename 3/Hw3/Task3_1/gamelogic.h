#pragma once

#include "scene.h"

#include <QGraphicsScene>

/**
 * @brief The GameLogic class
 * This class contains the logic of the game
 */
class GameLogic: public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = 0);
    ~GameLogic();

    QGraphicsScene *getScene();

public slots:
    void rotateCannonUp();
    void rotateCannonDown();
    void moveCannonRight();
    void moveCannonLeft();
    void cannonShot();

private:
    Scene *scene = nullptr;
};
