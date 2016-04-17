#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	lineEdit = new QLineEdit;
	ui->gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

	signalMapper = new QSignalMapper(this);

	QPushButton *button = new QPushButton("0");
	connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(button, "0");
	ui->gridLayout->addWidget(button, 4, 1);

	for(int i = 1; i < 10; i++)
	{
		button = new QPushButton(QString::number(i));
		connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(button, QString::number(i));
		ui->gridLayout->addWidget(button, (i - 1) / 3 + 1, (i - 1) % 3);
	}

	QChar operations[4] = {'+', '-', '*', '/'};
	for(int i = 0; i < 4; i++)
	{
		button = new QPushButton(operations[i]);
		connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(button, operations[i]);
		ui->gridLayout->addWidget(button, i + 1, 3);
	}

	button = new QPushButton("(");
	connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(button, "(");
	ui->gridLayout->addWidget(button, 5, 0);

	button = new QPushButton(")");
	connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(button, ")");
	ui->gridLayout->addWidget(button, 5, 1);

	button = new QPushButton(".");
	connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
	signalMapper->setMapping(button, ".");
	ui->gridLayout->addWidget(button, 4, 2);

	button = new QPushButton("=");
	connect(button, SIGNAL(clicked()), this, SLOT(calculate()));
	ui->gridLayout->addWidget(button, 5, 3);

	button = new QPushButton("Clear");
	connect(button, SIGNAL(clicked()), this, SLOT(clear()));
	ui->gridLayout->addWidget(button, 5, 2);

	connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
 }

void MainWindow::clicked(const QString &text)
{
	lineEdit->insert(text);
}

void MainWindow::clear()
{
	lineEdit->clear();
}

void MainWindow::calculate()
{
	QByteArray array = lineEdit->text().toLocal8Bit();
	calculator = new Calculator(array.data());
	QString string;
	lineEdit->setText(string.setNum(calculator->calculation(), 'f', 2));
	delete calculator;
}

MainWindow::~MainWindow()
{
	delete ui;
}
