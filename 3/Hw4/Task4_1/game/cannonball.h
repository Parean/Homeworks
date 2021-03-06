#pragma once

#include "game/scenesize.h"

#include <QObject>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QRectF>


enum moveDirection
{
    leftDirection = -1,
    rightDirection = 1
};

/**
 * @brief The CannonBall class
 * The base class implements a cannonball
 */
class CannonBall : public QObject
{
    Q_OBJECT
public:
    explicit CannonBall(SceneSize &size, QGraphicsPixmapItem *cannonBallItem, QObject *parent = 0);
    ~CannonBall();

    /**
     * @brief getCannonBallItem
     * @return a graphical representation of cannonball
     */
    QGraphicsPixmapItem *getCannonBallItem();

    /**
     * @brief appear
     * It Specifies the initial position of the cannonball on the scene
     */
    void appear(moveDirection dir, int x, int y, double angle, QGraphicsPixmapItem *cannonItem);

protected:

    /**
     * @brief CannonBall
     * This constructor allows you to change the initial velocity and radius from the inherited classes
     */
    CannonBall(SceneSize &size, int v, int r, QGraphicsPixmapItem *cannonBallItem, QObject *parent = 0);

private slots:

    /**
     * @brief updatePos
     * It specifies the actual position of the cannonball on the scene
     */
    void updatePos();

signals:

    /**
     * @brief isHitOtherCannon
     * Emited to check whether the target struck
     */
    void isHitOtherCannon(QRectF &areaOfDestructuion);

private:
    QTimer timer;
    const int g = 10;

    int radiusOfDestruction = 0;
    int x0 = 0;
    int y0 = 0;
    int v0 = 30; //Initial velocity
    int vx = 0;  //The projection of the velocity on the X axis
    int vy = 0;  //The projection of the velocity on the Y axis
    float t = 0;
    QGraphicsPixmapItem *cannonBall = nullptr;
    QGraphicsPixmapItem *cannon = nullptr;
    moveDirection direction;
    SceneSize sceneSize;
};

