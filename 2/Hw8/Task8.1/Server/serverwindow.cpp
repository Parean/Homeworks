#include <QApplication>

#include "server.h"
#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ServerWindow)
{
	ui->setupUi(this);

	ui->ipLabel->setText(QString("IP: %1").arg(server.getIP()));
	ui->portLabel->setText(QString("Port: %1").arg(server.getPort()));

	connect(ui->sendButton, &QPushButton::clicked, this, &ServerWindow::sendMessage);
	connect(&server, &Server::message, this, &ServerWindow::getMessage);
	connect(&server, &Server::info, this, &ServerWindow::getInfo);
}

void ServerWindow::sendMessage()
{
	QString newMessage = ui->newMessageTextEdit->toPlainText();
	ui->newMessageTextEdit->setText("");

	if (!server.sendMessageToClient(newMessage))
		return;

	ui->allMessageTextEdit->append(QString(">> %1").arg(newMessage));
}

void ServerWindow::getMessage(const QString &newMessage)
{
	ui->allMessageTextEdit->append(QString("<< %1").arg(newMessage));
}

void ServerWindow::getInfo(const QString &newMessage)
{
	ui->allMessageTextEdit->append(QString("<< %1").arg(newMessage));
}

ServerWindow::~ServerWindow()
{
	delete ui;
}
