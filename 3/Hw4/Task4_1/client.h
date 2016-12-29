#pragma once

#include "networkelement.h"

#include <QObject>

/**
 * @brief The Client class
 * Represents network elements than can connects to the server
 */
class Client : public NetworkElement
{
    Q_OBJECT
public:
    Client(GameLogic *game, QObject *parent = 0);
    ~Client();

public slots:
    void connectToServer();
    void sessionOpened();
};

