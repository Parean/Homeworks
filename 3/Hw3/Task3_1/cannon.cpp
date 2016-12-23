#include "cannon.h"

#include <QPixmap>
#include <QImage>
#include <QtMath>

Cannon::Cannon(SceneSize &size, QGraphicsPixmapItem *cannonItem, CannonBall *core):
    sceneSize(size),
    cannon(cannonItem),
    cannonBall(core)
{
    cannon->setTransformOriginPoint(30, 40);
    cannon->setX(120);
    setY();
}

Cannon::~Cannon()
{
    delete cannon;
}

QPixmap Cannon::getPixmap()
{
    QPixmap cannonPixmap;
    cannonPixmap.convertFromImage(QImage(":/images/images/cannon.png").scaled(70,70, Qt::KeepAspectRatio));
    return cannonPixmap;
}

QGraphicsPixmapItem *Cannon::getCannonBallItem()
{
    return cannonBall->getCannonBallItem();
}

void Cannon::shot(moveDirection direction)
{
    QPoint initialPoint;
    if (direction == right)
    {
        initialPoint.setX(60);
        initialPoint.setY(-5);
    }
    else
    {
        initialPoint.setX(75);
        initialPoint.setY(-2);
    }

    int x0 = cannon->mapToScene(initialPoint).x();
    int y0 = cannon->mapToScene(initialPoint).y();

    double angle = 20 - cannon->rotation();
    angle = qDegreesToRadians(angle);
    cannonBall->appear(direction, x0, y0, angle);

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
