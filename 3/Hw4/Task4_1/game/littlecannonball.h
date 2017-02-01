#pragma once

#include "game/cannonball.h"

#include <QObject>
#include <QGraphicsPixmapItem>

/**
 * @brief The LittleCannonBall class
 * Class implements a little cannonball
 */
class LittleCannonBall : public CannonBall
{
    Q_OBJECT
public:
    LittleCannonBall(SceneSize &size, QGraphicsPixmapItem *cannonBallItem, QObject *parent = 0);
    ~LittleCannonBall(){}

    /**
     * @brief getPixmap
     * @return the default pixmap element that can be used to initialize the cannonBall
     */
    static QPixmap getPixmap();
};

