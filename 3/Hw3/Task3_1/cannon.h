#pragma once

#include "scenesize.h"
#include "littlecannonball.h"

#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

enum rotateDirection
{
    counterclockwise = -1,
    clockwise = 1
};

/**
 * @brief The Cannon class
 * This class implements a cannon
 */
class Cannon
{
public:
    Cannon(SceneSize &size, QGraphicsPixmapItem *cannonItem, CannonBall *core);
    ~Cannon();

    /**
     * @brief getPixmap
     * @return Returns the default pixmap element that can be used to initialize the cannon
     */
    static QPixmap getPixmap();

    /**
     * @brief rotate
     * It rotates cannon in the predetermined direction
     */
    void rotate(rotateDirection direction);

    /**
     * @brief flip
     * It reflects cannon about the vertical axis
     */
    void flip();

    /**
     * @brief setX
     * It shifts cannon in the predetermined direction on the X axis
     */
    void setX(moveDirection direction);

    /**
     * @brief getCannonBallItem
     * @return cannonBallItem belongs to the cannon
     */
    QGraphicsPixmapItem *getCannonBallItem();

    /**
     * @brief shot
     * @param direction
     * The method is called when the user fires
     */
    void shot(moveDirection direction);

private:
    /**
     * @brief setY
     * It sets the correct location of the cannon on the Y axis
     */
    void setY();

private:
    int const shift = 5;
    int const criticalAngle = 30;
    SceneSize sceneSize;

    QGraphicsPixmapItem *cannon = nullptr;
    CannonBall *cannonBall = nullptr;
};
