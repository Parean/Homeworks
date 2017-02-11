#include "network/server.h"

#include <QNetworkConfigurationManager>
#include <QFile>

Server::Server(GameLogic *game, QObject *parent):
    NetworkElement(game, parent)
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::connectToClient);
}

QString Server::getIP() const
{
    return tcpServer->serverAddress().toString();
}

quint16 Server::getPort() const
{
    return tcpServer->serverPort();
}

Server::~Server()
{
    delete tcpServer;
}

void Server::connectToClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Server::getMessage);
    emit connected();
}
