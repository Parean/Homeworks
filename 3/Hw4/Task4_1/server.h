#pragma once

#include "networkelement.h"

#include <QObject>
#include <QtNetwork>
#include <QNetworkSession>
#include <QTcpServer>

class Server : public NetworkElement
{
    Q_OBJECT
public:
    Server(GameLogic *game, QObject *parent = 0);
    ~Server();

private slots:
    void connectToClient();
    void sessionOpened();

private:
    QTcpServer *tcpServer = nullptr;
    QNetworkSession *networkSession = nullptr;
};
