#pragma once

#include "scene.h"

#include <QGraphicsScene>
#include <QString>

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
    void changeControllersConnection();
    void rotateCannonUp();
    void rotateCannonDown();
    void moveCannonRight();
    void moveCannonLeft();
    void cannonShot();
    void gameOver();

signals:
    /**
     * Emited to lock and unlock the ability to move
     */
    void connectControllers();
    void disconnectControllers();

    /**
     * @brief gameOver
     * Emited when game over and contains message with results of game
     */
    void gameOver(const QString &) const;
    void rotateCurrentCannonUp(events event);
    void rotateCurrentCannonDown(events event);
    void moveCurrentCannonRight(events event);
    void moveCurrentCannonLeft(events event);
    void currentCannonShot(events event);

private:
    Scene *scene = nullptr;
    int numOfMoves = 0;
    bool isControllersConnected = true;
};
