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

    QPixmap bangPixmap;
    bangPixmap.convertFromImage(QImage(":/images/images/landscape.png"));
    bang = new QGraphicsPixmapItem(bangPixmap);

    scene->addWidget(leftLabel);
    scene->addWidget(rightLabel);
    rightLabel->move(600, 0);
    labels.append(leftLabel);
    labels.append(rightLabel);

    addCannons();
}

Scene::~Scene()
{
    cannons.clear();
    labels.clear();
    delete scene;
}

void Scene::addCannons()
{
    SceneSize sceneSize(scene->width(), scene->height());

    QGraphicsPixmapItem *cannonBallItem = new QGraphicsPixmapItem(LittleCannonBall::getPixmap());
    littleCannonBall = new LittleCannonBall(sceneSize, cannonBallItem);
    cannonBallItem = new QGraphicsPixmapItem(BigCannonBall::getPixmap());
    bigCannonBall  = new BigCannonBall(sceneSize, cannonBallItem);

    for (int i = 0; i < numCannons; i++)
    {
        QGraphicsPixmapItem *cannonItem = nullptr;
        if(i)
        {
            cannonItem = new QGraphicsPixmapItem(Cannon::getOnePixmap());
            connect(littleCannonBall, &CannonBall::cannonBallHit, this, &Scene::cannonBallHit);
            connect(littleCannonBall, &CannonBall::isHitOtherCannon, this, &Scene::checkHitOtherCannon);
        }
        else
        {
            cannonItem = new QGraphicsPixmapItem(Cannon::getTwoPixmap());
            connect(bigCannonBall, &CannonBall::cannonBallHit, this, &Scene::cannonBallHit);
            connect(bigCannonBall, &CannonBall::isHitOtherCannon, this, &Scene::checkHitOtherCannon);
        }

        scene->addItem(cannonItem);
        Cannon *cannon = new Cannon(sceneSize, cannonItem, littleCannonBall, 400*i+120);
        cannons.append(cannon);
    }
    moveCannonLeft(1);
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
    scene->addRect(areaOfDestruction);

    if (height)
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

void Scene::setCannonBall(int id)
{
    if(cannons[id]->isBigCannonBall())
    {
        cannons[id]->setCannonBall(littleCannonBall, false);
        labels[id]->setText("Little cannonball");
    }
    else
    {
        cannons[id]->setCannonBall(bigCannonBall, true);
        labels[id]->setText("Big cannonball");
    }
}

