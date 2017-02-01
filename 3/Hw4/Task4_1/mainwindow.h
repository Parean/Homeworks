#pragma once

#include "game/gamelogic.h"
#include "network/client.h"
#include "network/server.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QShortcut>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * The class implements the main window of application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startGame();
    void connectToServer();
    void createClient();
    void createServer();
    void deleteButtons();
    void gameOver(const QString &message);

    /**
     * @brief connectControllers
     * Need to lock and unlock ability to move for user
     */
    void connectControllers();
    void disconnectControllers();

private:
    QList<QLabel *> labels;
    QList<QLineEdit *> lineEdits;
    GameLogic *gameLogic = new GameLogic();
    NetworkElement *networkElement = nullptr;
    QGraphicsView *view = nullptr;
    QPushButton *clientButton = new QPushButton("Client");
    QPushButton *serverButton = new QPushButton("Server");
    QPushButton *connectButton = nullptr;
    QWidget *centralWidget = new QWidget(this);

    ///Variables for user control
    QShortcut *left = new QShortcut(Qt::Key_Left, this);
    QShortcut *right = new QShortcut(Qt::Key_Right, this);
    QShortcut *up = new QShortcut(Qt::Key_Up, this);
    QShortcut *down = new QShortcut(Qt::Key_Down, this);
    QShortcut *space = new QShortcut(Qt::Key_Space, this);
    QShortcut *tab = new QShortcut(Qt::Key_Tab, this);

};
