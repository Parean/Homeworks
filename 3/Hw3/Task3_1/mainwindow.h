#pragma once

#include "gamelogic.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QShortcut>

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

private:
    GameLogic gameLogic;
    QGraphicsView *view = nullptr;

    //Variables for user control
    QShortcut *left = new QShortcut(Qt::Key_Left, this);
    QShortcut *right = new QShortcut(Qt::Key_Right, this);
    QShortcut *up = new QShortcut(Qt::Key_Up, this);
    QShortcut *down = new QShortcut(Qt::Key_Down, this);
    QShortcut *space = new QShortcut(Qt::Key_Space, this);
};
