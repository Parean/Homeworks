#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QList>
#include <QMessageBox>

#include "mainwindow.h"
#include "playingbutton.h"

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
	spinBoxField->setValue(3);
	spinBoxChain->setValue(3);
	connect(spinBoxField, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainWindow::changeSizeOfField);
	connect(spinBoxChain, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainWindow::changeLengthOfChain);

	QGridLayout *mainLayout = new QGridLayout(this);
	QVBoxLayout *labelLayout = new QVBoxLayout();
	QVBoxLayout *spinBoxLayout = new QVBoxLayout();

	mainLayout->addLayout(labelLayout, 0, 0);
	mainLayout->addLayout(spinBoxLayout, 0, 1);
	mainLayout->addLayout(buttonsLayout, 1, 0);

	QLabel *label = new QLabel("Size of field");
	labelLayout->addWidget(label);
	label = new QLabel("Length of winning chain");
	labelLayout->addWidget(label);

	spinBoxLayout->addWidget(spinBoxField);
	spinBoxField->setFixedSize(35, 20);
	spinBoxLayout->addWidget(spinBoxChain);
	spinBoxChain->setFixedSize(35, 20);

	fillTheFeild();
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

void MainWindow::fillTheFeild()
{
	PlayingButton *button = nullptr;

	eventHandler = new EventHandler(sizeOfField, spinBoxChain->value());

	for(int i = 0; i < sizeOfField; i++)
		for(int j = 0; j < sizeOfField; j++)
		{
			button = new PlayingButton(j, i);
			button->setFixedSize(25, 25);

			connect(button, &QPushButton::clicked,
					signalMapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
			signalMapper->setMapping(button, button);

			buttons.push_front(button);
			buttonsLayout->addWidget(button, i % sizeOfField + 1, j % sizeOfField);
		}

	connect(signalMapper, static_cast<void(QSignalMapper::*)(QWidget *)>(&QSignalMapper::mapped),
			eventHandler, static_cast<void(EventHandler::*)(QWidget *)>(&EventHandler::move));

	QPushButton *newGameButton = new QPushButton("New game");

	connect(this, &MainWindow::startGame, newGameButton, &QPushButton::click);
	connect(newGameButton, &QPushButton::clicked, eventHandler, &EventHandler::startNewGame);
	connect(newGameButton, &QPushButton::clicked, this, &MainWindow::startNewGame);

	connect(eventHandler, &EventHandler::gameOver, this, &MainWindow::showMessage);

	buttonsLayout->addWidget(newGameButton, sizeOfField + 1, 0, 1, sizeOfField);
}

void MainWindow::startNewGame()
{
	for (auto b : this->buttons)
	{
		b->setEnabled(true);
		b->setText("");
	}
}

void MainWindow::changeLengthOfChain()
{
	int newLength = spinBoxChain->value();

	if (newLength > sizeOfField)
	{
		spinBoxChain->setValue(spinBoxField->value());
		return;
	}

	if (newLength < 3)
	{
		spinBoxChain->setValue(3);
		return;
	}

	eventHandler->setLengthOfChain(newLength);
}

void MainWindow::changeSizeOfField()
{
	int newSize = spinBoxField->value();

	if (newSize == 3 && sizeOfField == 3)
		return;

	if (newSize < 3)
	{
		sizeOfField = 3;
		spinBoxField->setValue(3);
		return;
	}

	sizeOfField = newSize;

	if (sizeOfField < spinBoxChain->value())
		spinBoxChain->setValue(spinBoxField->value());

	delete eventHandler;
	deleteButtons();
	fillTheFeild();
}

void MainWindow::showMessage(const QString &message)
{
	QMessageBox msgBox;
	msgBox.setText(message);
	msgBox.setInformativeText("Do you want to start new game?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::NoButton);
	int ret = msgBox.exec();

	switch(ret)
	{
	case QMessageBox::Yes:
		emit startGame();
		break;
	case QMessageBox::No:
		this->close();
		break;
	}
}

void MainWindow::deleteButtons()
{
	for (auto b : buttons)
		delete b;

	QPushButton *button = this->findChild<QPushButton *>();
	delete button;

	buttons.clear();
}

MainWindow::~MainWindow()
{
	deleteButtons();

	delete spinBoxChain;
	delete spinBoxField;

	QList<QLabel *> listOfLabels = this->findChildren<QLabel *>();
	for (auto l : listOfLabels)
		delete l;

	QList<QVBoxLayout *> listOfVBoxLayouts = this->findChildren<QVBoxLayout *>();
	for (auto l : listOfVBoxLayouts)
		delete l;

	delete buttonsLayout;
	QGridLayout *mainLayout = this->findChild<QGridLayout *>();
	delete mainLayout;

	delete signalMapper;
	delete eventHandler;
}
