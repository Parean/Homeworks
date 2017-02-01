#include "network/client.h"

Client::Client(GameLogic *game, QObject *parent):
    NetworkElement(game, parent)
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::getMessage);
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::sessionOpened);
}

Client::~Client()
{
    delete tcpSocket;
}

void Client::connectToServer(const QString &ip, quint16 port)
{
    tcpSocket->connectToHost(ip, port);
}

void Client::sessionOpened()
{
    emit connected();
}
