#include <QNetworkConfigurationManager>
#include <QFile>

#include "server.h"

Server::Server(GameLogic *game, QObject *parent):
    NetworkElement(game, parent)
{
    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, &QNetworkSession::opened, this, &Server::sessionOpened);
        networkSession->open();
    }
    else
    {
        sessionOpened();
    }
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::connectToClient);
}


Server::~Server()
{
    if (networkSession)
    {
        delete networkSession;
    }
    if (tcpServer)
    {
        delete tcpServer;
    }
}


void Server::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();

    QFile port("port.txt");
    port.open(QIODevice::WriteOnly);
    port.write(QString::number(tcpServer->serverPort()).toLocal8Bit().data());
    port.close();
}


void Server::connectToClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Server::getMessage);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Server::sessionClosed);
    emit connectedToOtherNetworkEntity();
}
