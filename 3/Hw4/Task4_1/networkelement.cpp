#include "networkelement.h"

NetworkElement::NetworkElement(GameLogic *game, QObject *parent):
    QObject(parent),
    gameLogic(game)
{
    connect(gameLogic, &GameLogic::currentCannonShot, this, &NetworkElement::sendMessage);
    connect(gameLogic, &GameLogic::moveCurrentCannonLeft, this, &NetworkElement::sendMessage);
    connect(gameLogic, &GameLogic::moveCurrentCannonRight, this, &NetworkElement::sendMessage);
    connect(gameLogic, &GameLogic::rotateCurrentCannonDown, this, &NetworkElement::sendMessage);
    connect(gameLogic, &GameLogic::rotateCurrentCannonUp, this, &NetworkElement::sendMessage);

    connect(this, &NetworkElement::currentCannonMovedLeft, gameLogic, &GameLogic::moveCannonLeft);
    connect(this, &NetworkElement::currentCannonMovedRight, gameLogic, &GameLogic::moveCannonRight);
    connect(this, &NetworkElement::currentCannonRotatedDown, gameLogic, &GameLogic::rotateCannonDown);
    connect(this, &NetworkElement::currentCannonRotatedUp, gameLogic, &GameLogic::rotateCannonUp);
    connect(this, &NetworkElement::currentCannonShot, gameLogic, &GameLogic::cannonShot);
}

NetworkElement::~NetworkElement()
{
    delete tcpSocket;
}

void NetworkElement::sendMessage(events event)
{
    if (isSourceOfMessage)
    {
        isSourceOfMessage = false;
        return;
    }

    QByteArray outBuffer;
    QDataStream outStream(&outBuffer, QIODevice::WriteOnly);
    outStream << event;
    tcpSocket->write(outBuffer);
}

void NetworkElement::getMessage()
{
    QDataStream in(tcpSocket);
    int event;
    in >> event;

    isSourceOfMessage = true;

    switch (event)
    {
    case moveLeft:
    {
        emit currentCannonMovedLeft();
        break;
    }
    case moveRight:
    {
        emit currentCannonMovedRight();
        break;
    }
    case rotateDown:
    {
        emit currentCannonRotatedDown();
        break;
    }
    case rotateUp:
    {
        emit currentCannonRotatedUp();
        break;
    }
    case shot:
    {
        emit currentCannonShot();
    }
    }
}



