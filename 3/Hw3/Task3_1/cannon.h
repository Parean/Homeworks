#pragma once

#include "scenesize.h"
#include "littlecannonball.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

enum rotateDirection
{
    counterclockwise = -1,
    clockwise = 1
};


class Cannon
{
public:
    Cannon(SceneSize size);
    ~Cannon();

    QGraphicsPixmapItem *getCannon();
    void rotate(rotateDirection direction);
    void flip();

    void setInitialPos();
    void setX(moveDirection direction);
    void setY();

private:
    int  shift = 5;
    int  criticalAngle = 30;
    QGraphicsPixmapItem *cannon = nullptr;
    SceneSize sceneSize;

};
