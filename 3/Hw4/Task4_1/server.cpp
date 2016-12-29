#include <QNetworkConfigurationManager>
#include <QFile>

#include "server.h"

Server::Server(GameLogic *game, QObject *parent):
    NetworkElement(game, parent)
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::connectToClient);

    QFile port("port.txt");
    port.open(QIODevice::WriteOnly);
    port.write(QString::number(tcpServer->serverPort()).toLocal8Bit().data());
    port.close();
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
