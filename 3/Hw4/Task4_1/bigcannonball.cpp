#include "bigcannonball.h"

#include <QImage>
#include <QPixmap>

BigCannonBall::BigCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonItem, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    CannonBall(size, 30, 40, cannonItem, cannonBallItem)
{}

QPixmap BigCannonBall::getPixmap()
{
    QPixmap cannonBallPixmap;
    cannonBallPixmap.convertFromImage(QImage(":/images/images/cannonball.png").scaled(25, 25, Qt::KeepAspectRatio));
    return cannonBallPixmap;
}
