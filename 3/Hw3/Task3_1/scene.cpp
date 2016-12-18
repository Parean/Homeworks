#include "scene.h"

#include <QPixmap>
#include <QImage>
#include <QGraphicsPixmapItem>

Scene::Scene(int numPlayers):
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
        Cannon *cannon = new Cannon(sceneSize);
        cannons.append(cannon);
        scene->addItem(cannon->getCannon());
        cannon->setInitialPos();
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
