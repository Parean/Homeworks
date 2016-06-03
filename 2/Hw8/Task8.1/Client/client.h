#pragma once
#include "../chatApp.h"

/**
 * @class Client
 * Represent chat application which can to connect to the server and exchange messages with it
 */
class Client : public ChatApp
{
	Q_OBJECT

public:
	explicit Client() {}
	~Client();

	/**
	 * @brief connectToServer
	 * Function takes ip and number of a port and try to connect to the server
	 * In the end emit signal with message about connection
	 */
	void connectToServer(const QString &ip, quint16 port);

	/**
	 * @brief disconnectFromServer
	 * Called when user disconnects from server
	 */
	void disconnectFromServer();

	/**
	 * @brief sendMessageToServer
	 * It sends user`s message to server
	 * Returns true if message was sent succesfully and false if no
	 */
	bool sendMessageToServer(const QString &message);

private:
	QTcpSocket *serverSocket = nullptr;

private slots:

	/**
	 * @brief getMessageFromServer
	 * It gets new message from serevr
	 */
	void getMessageFromServer();

	/**
	 * @brief serverDisconnected
	 * Called when user disconnected
	 */
	void serverDisconnected();
};

