#include "bigcannonball.h"

#include <QImage>
#include <QPixmap>

BigCannonBall::BigCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    CannonBall(size, 40, 30, cannonBallItem)
{}

QPixmap BigCannonBall::getPixmap()
{
    QPixmap cannonBallPixmap;
    cannonBallPixmap.convertFromImage(QImage(":/images/images/cannonball.png").scaled(25, 25, Qt::KeepAspectRatio));
    return cannonBallPixmap;
}
