#include "game/cannonball.h"

#include <QtMath>

CannonBall::CannonBall(SceneSize &size, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    QObject(parent),
    cannonBall(cannonBallItem),
    sceneSize(size)
{}

CannonBall::CannonBall(SceneSize &size, int v, int r, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    QObject(parent),
    cannonBall(cannonBallItem),
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

void CannonBall::appear(moveDirection dir, int x, int y, double angle, QGraphicsPixmapItem *cannonItem)
{
    cannon = cannonItem;
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
        QRectF areaOfDestruction(cannonBall->pos().x() + 10 - radiusOfDestruction, cannonBall->pos().y() + 15 - radiusOfDestruction,
                   2 * radiusOfDestruction, 2 * radiusOfDestruction); //+10 and +15 – it is adjustment due to the asymmetry of the cannonball image
        emit isHitOtherCannon(areaOfDestruction);
        emit cannonBallHit();
    }
}
