#include "littlecannonball.h"

#include <QImage>
#include <QPixmap>

LittleCannonBall::LittleCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonItem, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    CannonBall(size, 50, 1, cannonItem, cannonBallItem)
{}

QPixmap LittleCannonBall::getPixmap()
{
    QPixmap cannonBallPixmap;
    cannonBallPixmap.convertFromImage(QImage(":/images/images/littlecannonball.png").scaled(20,20, Qt::KeepAspectRatio));
    return cannonBallPixmap;
}
