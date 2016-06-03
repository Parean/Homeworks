#pragma once

#include <QObject>
#include <QTcpSocket>

/**
 * @class ChatApp
 * Class represents realisation of chat application which can sends and gets messages
 */
class ChatApp : public QObject
{
	Q_OBJECT

public:
	explicit ChatApp(QObject *parent = 0);

protected:
	/**
	 * @brief It gets message from other chat application
	 */
	void getMessage(QTcpSocket *socket);

	/**
	 * @brief It sends message to other chat application
	 */
	void sendMessage(QTcpSocket *socket, const QString &message);

signals:
	void message(const QString &);
	void info(const QString &);
};
