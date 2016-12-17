#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsScene scene;
    QGraphicsView *graphicsView = new QGraphicsView(&scene, this);

    QShortcut *up = new QShortcut(Qt::Key_Up, this);
    QShortcut *down = new QShortcut(Qt::Key_Down, this);
    QShortcut *left = new QShortcut(Qt::Key_Left, this);
    QShortcut *right = new QShortcut(Qt::Key_Right, this);
    QShortcut *space = new QShortcut(Qt::Key_Space, this);
};
