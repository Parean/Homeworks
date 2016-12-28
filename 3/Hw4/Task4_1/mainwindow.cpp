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
    connectControllers();
}

void MainWindow::startGame()
{
    takeCentralWidget();
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
}


void MainWindow::disconnectControllers()
{
    disconnect(left, &QShortcut::activated, gameLogic, &GameLogic::moveCannonLeft);
    disconnect(right, &QShortcut::activated, gameLogic, &GameLogic::moveCannonRight);
    disconnect(up, &QShortcut::activated, gameLogic, &GameLogic::rotateCannonUp);
    disconnect(down, &QShortcut::activated, gameLogic, &GameLogic::rotateCannonDown);
    disconnect(space, &QShortcut::activated, gameLogic, &GameLogic::cannonShot);
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
    centralWidget->layout()->addWidget(connectButton);
    networkElement = new Client(gameLogic);
    connect(connectButton, SIGNAL(clicked()), networkElement, SLOT(connectToServer()));
    connect(networkElement, &NetworkElement::connectedToOtherNetworkEntity, this, &MainWindow::startGame);
    gameLogic->changeControllersConnection();
}

void MainWindow::createServer()
{
    deleteButtons();
    connectButton = new QPushButton("Start game");
    centralWidget->layout()->addWidget(connectButton);
    networkElement = new Server(gameLogic);
    connect(networkElement, &NetworkElement::connectedToOtherNetworkEntity, this, &MainWindow::startGame);
}

MainWindow::~MainWindow()
{
    delete left;
    delete right;
    delete up;
    delete down;
    delete space;
    delete view;
    delete gameLogic;
}
