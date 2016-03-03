#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**
     * It connects the slider and progress bar so
     * that if you move the slider, the progress bar move appropriately
     */
    connect(ui->verticalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}
