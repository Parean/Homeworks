#pragma once

#include "network/networkelement.h"

#include <QObject>
#include <QtNetwork>
#include <QNetworkSession>
#include <QTcpServer>

/**
 * @brief The Server class
 * Represents server to which the client can connect
 */
class Server : public NetworkElement
{
    Q_OBJECT
public:
    Server(GameLogic *game, QObject *parent = 0);
    ~Server();

    /**
     * @brief getIP
     * @return current ip for connection
     */
    QString getIP() const;

    /**
     * @brief getPort
     * @return current port for connection
     */
    quint16 getPort() const;

private slots:
    void connectToClient();

private:
    QTcpServer *tcpServer = nullptr;
};
