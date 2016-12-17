#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(700, 500);

    QPixmap landscape;
    landscape.convertFromImage(QImage(":/images/images/landscape.png"));
    scene.addPixmap(landscape);
    setCentralWidget(graphicsView);
}

MainWindow::~MainWindow()
{

}
