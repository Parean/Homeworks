#include "client.h"

Client::Client(GameLogic *game, QObject *parent):
    NetworkElement(game, parent)
{
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::getMessage);
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::sessionOpened);
}

Client::~Client()
{
    delete tcpSocket;
}

void Client::connectToServer()
{
    QFile port("port.txt");
    port.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray data = port.readAll();
    port.remove();

    tcpSocket->connectToHost("localhost", data.toInt());
}

void Client::sessionOpened()
{
    emit connectedToOtherNetworkEntity();
}
