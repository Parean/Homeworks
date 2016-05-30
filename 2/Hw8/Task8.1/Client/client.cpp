#include "client.h"

Client::~Client()
{
	delete serverSocket;
}

bool Client::sendMessageToServer(const QString &message)
{
	if (!serverSocket)
	{
		emit info("You doesn`t connect to the server");
		return false;
	}
	sendMessage(serverSocket, message);

	return true;
}

void Client::getMessageFromServer()
{
	getMessage(serverSocket);
}

void Client::serverDisconnected()
{
	emit info("You disconnected");
}

void Client::disconnectFromServer()
{
	serverSocket->disconnectFromHost();
}

void Client::connectToServer(const QString &ip, quint16 port)
{
	if (serverSocket)
		serverSocket->disconnectFromHost();

	serverSocket = new QTcpSocket();
	connect(serverSocket, &QTcpSocket::readyRead, this, &Client::getMessageFromServer);
	connect(serverSocket, &QTcpSocket::disconnected, this, &Client::serverDisconnected);
	serverSocket->connectToHost(ip, port);

	if (!serverSocket->waitForConnected())
	{
		emit info("Can not connect to the server");
		return;
	}

	emit info("You connected");
}

