#pragma once

#include "client.h"

#include <QMainWindow>

namespace Ui {
class ClientWindow;
}

/**
 * @class ClientWindow
 * Represent main window for Client
 */
class ClientWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit ClientWindow(QWidget *parent = 0);
	virtual ~ClientWindow();

private slots:

	/**
	 * @brief sendMessage
	 * Called when user clicked on button "Send message"
	 */
	void sendMessage();

	/**
	 * @brief getMessage
	 * Called when new message arrives
	 */
	void getMessage(const QString &newMessage);

	/**
	 * @brief getInfo
	 * Called when information about connection arrives
	 */
	void getInfo(const QString &newMessage);

	/**
	 * @brief connectToServer
	 * Called when user clicked on button "Connect"
	 */
	void connectToServer();

private:
	Ui::ClientWindow *ui;
	Client client;

};

