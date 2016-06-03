#include <QDataStream>

#include "chatApp.h"

ChatApp::ChatApp(QObject *parent) : QObject(parent)
{}

void ChatApp::getMessage(QTcpSocket *socket)
{
	QDataStream in(socket);
	quint16 blockSize = 0;
	if (blockSize == 0)
	{
		if (socket->bytesAvailable() < (int)sizeof(quint16))
			return;
		in >> blockSize;
	}
	if (socket->bytesAvailable() < blockSize)
		return;
	QString msg;
	in >> msg;

	emit message(msg);
}

void ChatApp::sendMessage(QTcpSocket *socket, const QString &message)
{
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << (quint16)0;
	out << message;
	out.device()->seek(0);
	out << (quint16)(data.size() - sizeof(quint16));

	socket->write(data);
}
