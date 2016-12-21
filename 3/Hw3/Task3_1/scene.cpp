#include "scene.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>

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
        QGraphicsPixmapItem *cannonItem = new QGraphicsPixmapItem(Cannon::getPixmap());
        QGraphicsPixmapItem *cannonBallItem = new QGraphicsPixmapItem(LittleCannonBall::getPixmap());
        CannonBall *cannonBall = new LittleCannonBall(sceneSize, cannonItem, cannonBallItem);
        connect(cannonBall, &CannonBall::cannonBallHit, this, &Scene::cannonBallHit);

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
    cannons[id]->shot(direction);
}

void Scene::cannonBallHit()
{
    scene->removeItem(flyingCannonBall);
    flyingCannonBall = nullptr;
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
    if(direction == right)
    {
        direction = left;
        cannons[id]->flip();
    }

    cannons[id]->setX(left);
}

void Scene::moveCannonRight(int id)
{
    if(direction == left)
    {
        direction = right;
        cannons[id]->flip();
    }
    cannons[id]->setX(right);
}
