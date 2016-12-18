#include "cannon.h"

#include <QPixmap>
#include <QImage>

Cannon::Cannon(SceneSize size):
    sceneSize(size)
{
    QPixmap image;
    image.convertFromImage(QImage(":/images/images/cannon.png").scaled(70,70, Qt::KeepAspectRatio));
    cannon = new QGraphicsPixmapItem(image);
    cannon->setTransformOriginPoint(30, 50);
}

Cannon::~Cannon()
{
    delete cannon;
}

QGraphicsPixmapItem *Cannon::getCannon()
{
    return cannon;
}

void Cannon::setInitialPos()
{
    cannon->setX(120);
    setY();
}

void Cannon::rotate(rotateDirection direction)
{
    if (cannon->rotation()*direction > criticalAngle)
        return;

    cannon->setRotation(cannon->rotation() + shift*direction);
    setY();
}

void Cannon::flip()
{
    QTransform flipMaker;
    cannon->setTransform(flipMaker.scale(-1, 1).translate(-(cannon->boundingRect().width()), 0), true);
}


void Cannon::setX(moveDirection direction)
{
    qreal x = cannon->x() + direction*shift;
    if (x < 0 || x > sceneSize.width - cannon->boundingRect().width())
        return;

    cannon->setX(x);
    setY();
}

void Cannon::setY()
{
    qreal y = cannon->y();

    if (!cannon->collidingItems().isEmpty())
    {
        while (!cannon->collidingItems().isEmpty())
        {
            cannon->setY(--y);
        }
    }
    else
    {
        while (cannon->collidingItems().isEmpty())
        {
            cannon->setY(++y);
        }
    }
}
