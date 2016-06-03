#include <QtCore/QObject>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QTcpServer>
#include <QString>

#include "server.h"


Server::Server():
	server(new QTcpServer(this))
{
	QList<QHostAddress> adresses = QNetworkInterface::allAddresses();
	for (auto a : adresses)
		if (a.protocol() == QAbstractSocket::IPv4Protocol && server->listen(a))
			break;

	if (!server->isListening())
		throw QString("Server is not listening");

	connect(server, &QTcpServer::newConnection,
			this, &Server::connectOfClient);

	emit info("Server is listennning");
}

Server::~Server()
{
	delete server;
	delete clientSocket;
}

QString Server::getIP() const
{
	return server->serverAddress().toString();
}

quint16 Server::getPort() const
{
	return server->serverPort();
}

bool Server::sendMessageToClient(const QString &message)
{
	if (!clientSocket)
	{
		emit info("Client doesn`t connect");
		return false;
	}
	sendMessage(clientSocket, message);

	return true;
}

void Server::getMessageFromClient()
{
	getMessage(clientSocket);
}

void Server::clientDisconnected()
{
	emit info("Client disconnected");
}

void Server::connectOfClient()
{
	if (!server->hasPendingConnections())
		return;

	clientSocket = server->nextPendingConnection();

	connect(clientSocket, &QTcpSocket::readyRead, this, &Server::getMessageFromClient);
	connect(clientSocket, &QTcpSocket::disconnected, this, &Server::clientDisconnected);

	emit info("Client connected");
}

