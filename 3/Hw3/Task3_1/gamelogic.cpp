#include "gamelogic.h"

GameLogic::GameLogic(QObject *parent): QObject(parent)
{
    scene = new Scene();
}

GameLogic::~GameLogic()
{
    delete scene;
}

QGraphicsScene *GameLogic::getScene()
{
    return scene->getScene();
}

void GameLogic::rotateCannonUp()
{
    scene->rotateCannonUp();
}

void GameLogic::rotateCannonDown()
{
    scene->rotateCannonDown();
}

void GameLogic::moveCannonLeft()
{
    scene->moveCannonLeft();
}

void GameLogic::moveCannonRight()
{
    scene->moveCannonRight();
}

void GameLogic::cannonShot()
{
    scene->cannonShot();
}
