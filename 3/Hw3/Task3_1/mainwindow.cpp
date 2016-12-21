#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(730, 520);
    view = new QGraphicsView(gameLogic.getScene(), this);
    setCentralWidget(view);

    connect(left, &QShortcut::activated, &gameLogic, &GameLogic::moveCannonLeft);
    connect(right, &QShortcut::activated, &gameLogic, &GameLogic::moveCannonRight);
    connect(up, &QShortcut::activated, &gameLogic, &GameLogic::rotateCannonUp);
    connect(down, &QShortcut::activated, &gameLogic, &GameLogic::rotateCannonDown);
    connect(space, &QShortcut::activated, &gameLogic, &GameLogic::cannonShot);
}

MainWindow::~MainWindow()
{
    delete left;
    delete right;
    delete up;
    delete down;
    delete space;
    delete view;
}
