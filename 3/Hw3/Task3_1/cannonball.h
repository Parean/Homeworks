#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>


enum moveDirection
{
    left = -1,
    right = 1
};

class CannonBall : public QObject
{
    Q_OBJECT
public:
    virtual void appear(moveDirection direction) = 0;
    virtual void updatePos() = 0;
    
private:
    QGraphicsPixmapItem *cannonBall = nullptr;
};

