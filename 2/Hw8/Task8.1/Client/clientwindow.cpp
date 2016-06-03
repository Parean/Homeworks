#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ClientWindow)
{
	ui->setupUi(this);
	connect(ui->sendButton, &QPushButton::clicked, this, &ClientWindow::sendMessage);
	connect(ui->connectButton, &QPushButton::clicked, this, &ClientWindow::connectToServer);
	connect(ui->disconnectButton, &QPushButton::clicked, &client, &Client::disconnectFromServer);

	connect(&client, &Client::message, this, &ClientWindow::getMessage);
	connect(&client, &Client::info, this, &ClientWindow::getInfo);
}

void ClientWindow::connectToServer()
{
	client.connectToServer(ui->ipLineEdit->text(), ui->portLineEdit->text().toInt());
}

void ClientWindow::sendMessage()
{
	QString newMessage = ui->newMessageTextEdit->toPlainText();
	ui->newMessageTextEdit->setText("");

	if (!client.sendMessageToServer(newMessage))
		return;

	ui->allMessageTextEdit->append(QString(">> %1").arg(newMessage));
}

void ClientWindow::getMessage(const QString &newMessage)
{
	ui->allMessageTextEdit->append(QString("<< %1").arg(newMessage));
}

void ClientWindow::getInfo(const QString &newMessage)
{
	ui->allMessageTextEdit->append(QString("<< %1").arg(newMessage));
}

ClientWindow::~ClientWindow()
{
	delete ui;
}
