#pragma once

#include "../chatApp.h"

#include <QTcpServer>
#include <QTcpSocket>

/**
 * @class Server
 * Represent chat application which can to accept the connection request from client and exchange messages with it
 */
class Server : public ChatApp
{
	Q_OBJECT
public:
	explicit Server();
	~Server();

	/**
	 * @brief sendMessageToClient
	 * Sends message to client
	 * Returns true if message was sent succesfully and false if no
	 */
	bool sendMessageToClient(const QString &message);

	/**
	 * @brief getIP
	 * @return current ip for connection
	 */
	QString getIP() const;

	/**
	 * @brief getPort
	 * @return current port for connection
	 */
	quint16 getPort() const;

private:
	QTcpServer *server = nullptr;
	QTcpSocket *clientSocket = nullptr;

public slots:

	/**
	 * @brief getMessageFromClient
	 * It gets new message from serevr
	 */
	void getMessageFromClient();

	/**
	 * @brief connectOfClient
	 * Called when client try to connect
	 */
	void connectOfClient();

	/**
	 * @brief clientDisconnected
	 * Called when client disconnected
	 */
	void clientDisconnected();
};
