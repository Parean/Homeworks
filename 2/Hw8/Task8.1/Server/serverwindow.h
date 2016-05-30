#pragma once

#include <QMainWindow>

#include "server.h"

namespace Ui {
class ServerWindow;
}

/**
 * @class ServerWindow
 * Class represent main window for Server
 */
class ServerWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit ServerWindow(QWidget *parent = 0);
	~ServerWindow();

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

private:
	Ui::ServerWindow *ui;
	Server server;
};

