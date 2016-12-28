#include "scene.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTime>

Scene::Scene(int numPlayers, QObject *parent):
    QObject(parent),
    numCannons(numPlayers)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    QPixmap landscape;
    landscape.convertFromImage(QImage(":/images/images/landscape.png"));
    scene->addItem(new QGraphicsPixmapItem(landscape));
    addCannons();
}

Scene::~Scene()
{
    cannons.clear();
    delete scene;
}

void Scene::addCannons()
{
    SceneSize sceneSize(scene->width(), scene->height());
    for (int i = 0; i < numCannons; i++)
    {
        QGraphicsPixmapItem *cannonItem = new QGraphicsPixmapItem(Cannon::getPixmap());
        QGraphicsPixmapItem *cannonBallItem = new QGraphicsPixmapItem(LittleCannonBall::getPixmap());
        CannonBall *cannonBall = new LittleCannonBall(sceneSize, cannonItem, cannonBallItem);
        connect(cannonBall, &CannonBall::cannonBallHit, this, &Scene::cannonBallHit);
        connect(cannonBall, &CannonBall::isHitOtherCannon, this, &Scene::checkHitOtherCannon);

        scene->addItem(cannonItem);
        Cannon *cannon = new Cannon(sceneSize, cannonItem, cannonBall);
        cannons.append(cannon);
    }
}

void Scene::cannonShot(int id)
{
    if(flyingCannonBall)
        return;

    flyingCannonBall = cannons[id]->getCannonBallItem();
    scene->addItem(flyingCannonBall);
    cannons[id]->shot();
}

void Scene::cannonBallHit()
{
    scene->removeItem(flyingCannonBall);
    flyingCannonBall = nullptr;
}

void Scene::checkHitOtherCannon(QRect &areaOfDestruction)
{
    QList<QGraphicsItem*> itemsInAreaOfDestruction(scene->items(areaOfDestruction));

    for (int i = 0; i < itemsInAreaOfDestruction.size(); i++)
    {
        if (itemsInAreaOfDestruction.at(i)->data(0).toString() == "Cannon")
        {
//            emit gameOver();
        }
    }

}

QGraphicsScene *Scene::getScene()
{
    return scene;
}

void Scene::rotateCannonUp(int id)
{
    cannons[id]->rotate(counterclockwise);
}

void Scene::rotateCannonDown(int id)
{
    cannons[id]->rotate(clockwise);
}

void Scene::moveCannonLeft(int id)
{
    cannons[id]->checkDirection(leftDirection);
    cannons[id]->setX();
}

void Scene::moveCannonRight(int id)
{
    cannons[id]->checkDirection(rightDirection);
    cannons[id]->setX();
}
