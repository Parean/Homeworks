#pragma once

#include "cannon.h"
#include "scenesize.h"

#include <QGraphicsScene>
#include <QList>

class Scene
{
public:
    Scene(int numPlayers = 1);
    ~Scene();

    void addCannons();
    QGraphicsScene *getScene();

    void rotateCannonUp(int id = 0);
    void rotateCannonDown(int id = 0);

    void moveCannonRight(int id = 0);
    void moveCannonLeft(int id = 0);
    void cannonShot();

private:
    int numCannons;
    moveDirection direction = right;
    QGraphicsScene *scene = new QGraphicsScene;
    QList<Cannon *> cannons;
};
