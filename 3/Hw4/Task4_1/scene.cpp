#include "scene.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTime>

Scene::Scene(int numPlayers, QObject *parent):
    QObject(parent),
    numCannons(numPlayers)
{
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
        QGraphicsPixmapItem *cannonItem = nullptr;
        if(i)
        {
            cannonItem = new QGraphicsPixmapItem(Cannon::getOnePixmap());
        }
        else
        {
            cannonItem = new QGraphicsPixmapItem(Cannon::getTwoPixmap());
        }

        CannonBall *cannonBall = nullptr;
        if(i)
        {
            QGraphicsPixmapItem *cannonBallItem = new QGraphicsPixmapItem(LittleCannonBall::getPixmap());
            littleCannonBall = cannonBall = new LittleCannonBall(sceneSize, cannonItem, cannonBallItem);
        }
        else
        {
            QGraphicsPixmapItem *cannonBallItem = new QGraphicsPixmapItem(BigCannonBall::getPixmap());
            bigCannonBall = cannonBall = new BigCannonBall(sceneSize, cannonItem, cannonBallItem);
        }
        connect(cannonBall, &CannonBall::cannonBallHit, this, &Scene::cannonBallHit);
        connect(cannonBall, &CannonBall::isHitOtherCannon, this, &Scene::checkHitOtherCannon);

        scene->addItem(cannonItem);
        Cannon *cannon = new Cannon(sceneSize, cannonItem, cannonBall, 500*i+120);
        cannons.append(cannon);
    }
}

void Scene::cannonShot(int id)
{
    emit changeControllersConnection();
    if(flyingCannonBall)
        return;
    currentId = id;
    flyingCannonBall = cannons[id]->getCannonBallItem();
    scene->addItem(flyingCannonBall);
    cannons[id]->shot();
}

void Scene::cannonBallHit()
{
    scene->removeItem(flyingCannonBall);
    flyingCannonBall = nullptr;
}

void Scene::checkHitOtherCannon(QRectF &areaOfDestruction)
{
    QList<QGraphicsItem*> *itemsInAreaOfDestruction = nullptr;
    auto height = areaOfDestruction.height();
    if (height > 5)
    {
        itemsInAreaOfDestruction = new QList<QGraphicsItem*>(scene->items(areaOfDestruction));
    }
    else
    {
        itemsInAreaOfDestruction = new QList<QGraphicsItem*>(flyingCannonBall->collidingItems());
    }
    for (int i = 0; i < itemsInAreaOfDestruction->size(); i++)
    {
        if (itemsInAreaOfDestruction->at(i) != cannons[currentId]->getCannonItem() && itemsInAreaOfDestruction->at(i)->data(0).toString() == "Cannon")
        {
            emit gameOver();
        }
    }
    delete itemsInAreaOfDestruction;
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
