#include "game/explosion.h"

#include <QPainter>

Explosion::Explosion(const QPointF &point)
{
    setPos(point);
    explosion = new QPixmap(":/images/images/explosion.png");
    connect(&timer, &QTimer::timeout, this, &Explosion::nextSprite);
    currentSpriteCoordinate -= explosion->height();
    timer.start(25);
}

QRectF Explosion::boundingRect() const
{
    return QRectF(-r, -r, 2 * r, 2 * r);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(), *explosion,
                        QRect(currentSpriteCoordinate, 0, explosion->height(), explosion->height()));
}

void Explosion::nextSprite()
{
    currentSpriteCoordinate += explosion->height();
    if (currentSpriteCoordinate >= explosion->width())
        deleteLater();
    else
        update(boundingRect());
}
