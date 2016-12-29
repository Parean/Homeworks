#pragma once

#include "cannon.h"
#include "littlecannonball.h"
#include "bigcannonball.h"
#include "scenesize.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QObject>
#include <QRect>
#include <QLabel>

/**
 * @brief The Scene class
 * Class responsible for visual displaying  of the game
 */
class Scene: public QObject
{
    Q_OBJECT
public:
    explicit Scene(int numPlayers = 1, QObject *parent = 0);
    ~Scene();

    /**
     * @brief addCannons
     * Initializes cannons and add cannon`s pixmap items to the scene
     */
    void addCannons();

    /**
     * @brief getScene
     * @return scene
     */
    QGraphicsScene *getScene();

    /**
     * @brief rotateCannonUp
     * It rotate up the correct cannon
     */
    void rotateCannonUp(int id = 0);

    /**
     * @brief rotateCannonUp
     * It rotate down the correct cannon
     */
    void rotateCannonDown(int id = 0);

    /**
     * @brief rotateCannonUp
     * It move right the correct cannon
     */
    void moveCannonRight(int id = 0);

    /**
     * @brief rotateCannonUp
     * It move left the correct cannon
     */
    void moveCannonLeft(int id = 0);

    /**
     * @brief cannonShot
     * It puts cannonball on the scene
     */
    void cannonShot(int id = 0);

    void setCannonBall(int id);


private slots:
    /**
     * @brief cannonBallHit
     * It remove cannonball from the scene
     */
    void cannonBallHit();
    void checkHitOtherCannon(QRectF &areaOfDestruction);

signals:
    void gameOver();
    void changeControllersConnection();
    void changeCannonBallLabel();

private:
    int numCannons = 0;
    int currentId = 0;
    QList<Cannon *> cannons;
    QTimer timer;


    QLabel *leftLabel = new QLabel("Little cannonball");
    QLabel *rightLabel = new QLabel("Little cannonball");
    QList<QLabel *> labels;
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsPixmapItem *flyingCannonBall = nullptr;
    QGraphicsPixmapItem *bang = nullptr;
    CannonBall *littleCannonBall = nullptr;
    CannonBall *bigCannonBall = nullptr;
};
