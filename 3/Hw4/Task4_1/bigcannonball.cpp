#include "bigcannonball.h"

#include <QImage>
#include <QPixmap>

BigCannonBall::BigCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonItem, QGraphicsPixmapItem *cannonBallItem, QObject *parent):
    CannonBall(size, 25, 50, cannonItem, cannonBallItem)
{}

QPixmap BigCannonBall::getPixmap()
{
    QPixmap cannonBallPixmap;
    cannonBallPixmap.convertFromImage(QImage(":/images/images/Bigcannonball.png").scaled(40,40, Qt::KeepAspectRatio));
    return cannonBallPixmap;
}
