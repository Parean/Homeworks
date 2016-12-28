#pragma once

#include "scene.h"

#include <QGraphicsScene>

enum events
{
    rotateUp,
    rotateDown,
    moveLeft,
    moveRight,
    shot
};

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

signals:
    void rotateCurrentCannonUp(events event);
    void rotateCurrentCannonDown(events event);
    void moveCurrentCannonRight(events event);
    void moveCurrentCannonLeft(events event);
    void currentCannonShot(events event);

private:
    Scene *scene = nullptr;
    int numOfMoves = 0;
};
