#pragma once

#include "cannonball.h"

#include <QObject>
#include <QGraphicsPixmapItem>

/**
 * @brief The BigCannonBall class
 * Class implements a Big cannonball
 */
class BigCannonBall : public CannonBall
{
    Q_OBJECT
public:
    BigCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonBallItem, QObject *parent = 0);
    ~BigCannonBall(){}

    /**
     * @brief getPixmap
     * @return the default pixmap element that can be used to initialize the cannonBall
     */
    static QPixmap getPixmap();
};

