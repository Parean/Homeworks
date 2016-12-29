#pragma once

#include "gamelogic.h"

#include <QtNetwork>
#include <QTcpSocket>
#include <QObject>

/**
 * @brief The NetworkElement class
 * Represents network element that can get and send messages
 */
class NetworkElement: public QObject
{
    Q_OBJECT
public:
    explicit NetworkElement(GameLogic *game, QObject *parent = 0);
    ~NetworkElement() {}

protected slots:
    /**
     * @brief sendMessage
     * It sends message to other Network element
     */
    void sendMessage(events event);

    /**
     * @brief getMessage
     * It gets message from other Network element
     */
    void getMessage();


signals:
    /**
     * @brief connected
     * Emited when element was connected
     */
    void connected();
    void currentCannonRotatedUp();
    void currentCannonRotatedDown();
    void currentCannonMovedRight();
    void currentCannonMovedLeft();
    void currentCannonShot();
    void currentCannonBallChanged();

protected:
    QTcpSocket *tcpSocket = nullptr;
    GameLogic *gameLogic = nullptr;

private:
    bool isSourceOfMessage = false;
};

