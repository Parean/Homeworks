#pragma once

#include "cannonball.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class LittleCannonBall : public CannonBall
{
    Q_OBJECT
public:
    LittleCannonBall();
    void appear(moveDirection direction){}
    void updatePos(){}

private:
    QGraphicsPixmapItem *cannonBall = nullptr;
};

