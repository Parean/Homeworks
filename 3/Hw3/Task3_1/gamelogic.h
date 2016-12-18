#pragma once

#include "scene.h"

#include <QGraphicsScene>

class GameLogic: public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = 0);
    ~GameLogic();

    QGraphicsScene *getScene();

public slots:
    void rotateCannonUp();
    void rotateCannonDown();
    void moveCannonRight();
    void moveCannonLeft();

private:
    Scene *scene = nullptr;
};
