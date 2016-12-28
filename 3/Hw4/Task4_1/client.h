#pragma once

#include "networkelement.h"

class Client : public NetworkElement
{
    Q_OBJECT
public:
    Client(GameLogic *game, QObject *parent = 0);
    ~Client();

private slots:
    void connectToServer();
    void sessionOpened();
};

