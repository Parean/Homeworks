#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(730, 520);
    view = new QGraphicsView(gameLogic.getScene(), this);
    setCentralWidget(view);

    connect(up, SIGNAL(activated()), &gameLogic, SLOT(rotateCannonUp()));
    connect(down, SIGNAL(activated()), &gameLogic, SLOT(rotateCannonDown()));
    connect(left, SIGNAL(activated()), &gameLogic, SLOT(moveCannonLeft()));
    connect(right, SIGNAL(activated()), &gameLogic, SLOT(moveCannonRight()));
}

MainWindow::~MainWindow()
{
    delete view;
}
