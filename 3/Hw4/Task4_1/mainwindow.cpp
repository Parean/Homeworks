#include "mainwindow.h"

#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    centralWidget->setLayout(layout);

    connect(clientButton, &QPushButton::clicked, this, &MainWindow::createClient);
    connect(serverButton, &QPushButton::clicked, this, &MainWindow::createServer);
    connect(gameLogic, &GameLogic::connectControllers, this, &MainWindow::connectControllers);
    connect(gameLogic, &GameLogic::disconnectControllers, this, &MainWindow::disconnectControllers);

    layout->addWidget(serverButton);
    layout->addWidget(clientButton);
    setCentralWidget(centralWidget);
}

void MainWindow::startGame()
{
    takeCentralWidget();
    labels.clear();
    lineEdits.clear();

    delete connectButton;
    delete centralWidget->layout();
    delete centralWidget;

    this->setFixedSize(730, 520);
    view = new QGraphicsView(gameLogic->getScene(), this);
    connect(gameLogic, SIGNAL(gameOver(const QString &)), this, SLOT(gameOver(const QString &)));

    setCentralWidget(view);
}

void MainWindow::connectControllers()
{
    connect(left, &QShortcut::activated, gameLogic, &GameLogic::moveCannonLeft);
    connect(right, &QShortcut::activated, gameLogic, &GameLogic::moveCannonRight);
    connect(up, &QShortcut::activated, gameLogic, &GameLogic::rotateCannonUp);
    connect(down, &QShortcut::activated, gameLogic, &GameLogic::rotateCannonDown);
    connect(space, &QShortcut::activated, gameLogic, &GameLogic::cannonShot);
    connect(tab, &QShortcut::activated, gameLogic, &GameLogic::changeCannonBall);
}


void MainWindow::disconnectControllers()
{
    disconnect(left, &QShortcut::activated, gameLogic, &GameLogic::moveCannonLeft);
    disconnect(right, &QShortcut::activated, gameLogic, &GameLogic::moveCannonRight);
    disconnect(up, &QShortcut::activated, gameLogic, &GameLogic::rotateCannonUp);
    disconnect(down, &QShortcut::activated, gameLogic, &GameLogic::rotateCannonDown);
    disconnect(space, &QShortcut::activated, gameLogic, &GameLogic::cannonShot);
    disconnect(tab, &QShortcut::activated, gameLogic, &GameLogic::changeCannonBall);
}

void MainWindow::gameOver(const QString &message)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
    this->close();
}

void MainWindow::deleteButtons()
{
    delete clientButton;
    delete serverButton;
}

void MainWindow::createClient()
{
    deleteButtons();
    connectButton = new QPushButton("Try connect");

    labels.append(new QLabel("IP"));
    labels.append(new QLabel("Port"));
    for(auto l : labels)
    {
        lineEdits.append(new QLineEdit());
        centralWidget->layout()->addWidget(l);
        centralWidget->layout()->addWidget(lineEdits.last());
    }
    centralWidget->layout()->addWidget(connectButton);

    networkElement = new Client(gameLogic);
    connect(connectButton, &QPushButton::clicked, this, &MainWindow::connectToServer);
    connect(networkElement, &NetworkElement::connected, this, &MainWindow::startGame);
    gameLogic->changeControllersConnection();
}

void MainWindow::connectToServer()
{
    dynamic_cast<Client *>(networkElement)->connectToServer(lineEdits.at(0)->text(), lineEdits.at(1)->text().toInt());
}

void MainWindow::createServer()
{
    deleteButtons();
    networkElement = new Server(gameLogic);

    labels.append(new QLabel("Waiting for client..."));
    labels.append(new QLabel(QString("IP: %1").arg(dynamic_cast<Server *>(networkElement)->getIP())));
    labels.append(new QLabel(QString("Port: %1").arg(dynamic_cast<Server *>(networkElement)->getPort())));

    for(auto l : labels)
    {
        centralWidget->layout()->addWidget(l);
    }

    connect(networkElement, &NetworkElement::connected, this, &MainWindow::connectControllers);
    connect(networkElement, &NetworkElement::connected, this, &MainWindow::startGame);
}

MainWindow::~MainWindow()
{
    delete left;
    delete right;
    delete tab;
    delete up;
    delete down;
    delete space;
    delete view;
    delete gameLogic;
    delete networkElement;
}
