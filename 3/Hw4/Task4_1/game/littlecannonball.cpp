#include "game/littlecannonball.h"

#include <QImage>
#include <QPixmap>

LittleCannonBall::LittleCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    CannonBall(size, 50, 0, cannonBallItem)
{}

QPixmap LittleCannonBall::getPixmap()
{
    QPixmap cannonBallPixmap;
    cannonBallPixmap.convertFromImage(QImage(":/images/images/cannonball.png").scaled(20,20, Qt::KeepAspectRatio));
    return cannonBallPixmap;
}
