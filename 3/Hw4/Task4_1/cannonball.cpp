#include "cannonball.h"

#include <QtMath>

CannonBall::CannonBall(SceneSize &size, QGraphicsPixmapItem *cannonItem, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    QObject(parent),
    cannonBall(cannonBallItem),
    cannon(cannonItem),
    sceneSize(size)
{}

CannonBall::CannonBall(SceneSize &size, int v, int r, QGraphicsPixmapItem *cannonItem, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    QObject(parent),
    cannonBall(cannonBallItem),
    cannon(cannonItem),
    sceneSize(size),
    v0(v),
    radiusOfDestruction(r)
{}

CannonBall::~CannonBall()
{
    delete cannonBall;
}

QGraphicsPixmapItem *CannonBall::getCannonBallItem()
{
    return cannonBall;
}

void CannonBall::appear(moveDirection dir, int x, int y, double angle)
{
    direction = dir;
    x0 = x;
    y0 = y;
    vx = v0 * qCos(angle);
    vy = v0 * qSin(angle);
    t = 0;

    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
    timer.start(20);

    updatePos();
}

void CannonBall::updatePos()
{
    t += 0.1f;

    cannonBall->setPos(x0 + t * vx * direction, y0 - (vy - (g / 2) * t) * t);
    if ((!(cannonBall->collidesWithItem(cannon))) && !cannonBall->collidingItems().isEmpty() ||
            cannonBall->x() < 0 || cannonBall->x() > sceneSize.width)
    {
        timer.stop();
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
        QRectF areaOfDestruction(cannonBall->pos().x() - radiusOfDestruction, cannonBall->pos().y() - radiusOfDestruction,
                   2 * radiusOfDestruction, 2 * radiusOfDestruction);
        emit isHitOtherCannon(areaOfDestruction);
        emit cannonBallHit();
    }
}
