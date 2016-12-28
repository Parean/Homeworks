#pragma once

#include "networkelement.h"

#include <QObject>

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

