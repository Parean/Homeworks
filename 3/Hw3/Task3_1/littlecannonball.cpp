#include "littlecannonball.h"

#include <QPixmap>

LittleCannonBall::LittleCannonBall()
{
    QPixmap image;
    image.convertFromImage(QImage(":/images/images/cannonball.png").scaled(20,20, Qt::KeepAspectRatio));
    cannonBall = new QGraphicsPixmapItem(image);
}
