#include "gamelogic.h"

GameLogic::GameLogic(QObject *parent): QObject(parent)
{
    scene = new Scene(2);
    connect(scene, SIGNAL(gameOver()), this, SLOT(gameOver()));
    connect(scene, &Scene::changeControllersConnection, this, &GameLogic::changeControllersConnection);
}

GameLogic::~GameLogic()
{
    delete scene;
}

QGraphicsScene *GameLogic::getScene()
{
    return scene->getScene();
}

void GameLogic::changeControllersConnection()
{
    isControllersConnected = !isControllersConnected;
    if(isControllersConnected)
    {
        emit connectControllers();
    }
    else
    {
        emit disconnectControllers();
    }
}

void GameLogic::rotateCannonUp()
{
    scene->rotateCannonUp(numOfMoves % 2);
    emit rotateCurrentCannonUp(rotateUp);
}

void GameLogic::rotateCannonDown()
{
    scene->rotateCannonDown(numOfMoves % 2);
    emit rotateCurrentCannonDown(rotateDown);
}

void GameLogic::moveCannonLeft()
{
    scene->moveCannonLeft(numOfMoves % 2);
    emit moveCurrentCannonLeft(moveLeft);
}

void GameLogic::moveCannonRight()
{
    scene->moveCannonRight(numOfMoves % 2);
    emit moveCurrentCannonRight(moveRight);
}

void GameLogic::gameOver()
{
    QString message;
    if (!isControllersConnected)
        message.append("Вы победили");
    else
        message.append("Вы проиграли");

    emit gameOver(message);
}

void GameLogic::cannonShot()
{
    scene->cannonShot(numOfMoves % 2);
    emit currentCannonShot(shot);
    numOfMoves++;
}
