#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "eventhandler.h"

class GameTester : public QObject
{
	Q_OBJECT

public:
	explicit GameTester(QObject *parent = 0):
		QObject(parent)
	{
		connect(eventHandler, &EventHandler::gameOver, this, &GameTester::getMessage);
	}

private:
	EventHandler *eventHandler = new EventHandler(7,5);
	QString message;

private slots:

	void getMessage(const QString &msg)
	{
		message = msg;
		init();
	}

	void init()
	{
		eventHandler->startNewGame();
	}

	void cleanupTestCase()
	{
		delete eventHandler;
	}

	void testColumn()
	{
		for (int i = 0; i < 5; i++)
		{
			eventHandler->move(1, i);
			eventHandler->move(2, i);
		}
		QVERIFY2(!QString::compare(message, "Player X win"), "Incorrect winner");
	}

	void testString()
	{
		for (int i = 0; i < 5; i++)
		{
			eventHandler->move(i, 1);
			eventHandler->move(i, 2);
		}
		QVERIFY2(!QString::compare(message, "Player X win"), "Incorrect winner");
	}

	void testMaindiagonal()
	{
		for (int i = 0; i < 5; i++)
		{
			eventHandler->move(i, i);
			eventHandler->move(i + 1, i + 1);
		}
		QVERIFY2(!QString::compare(message, "Player X win"), "Incorrect winner");
	}

	void testSecondaryDiagonal()
	{
		for (int i = 0; i < 5; i++)
		{
			eventHandler->move(5-i, 5-i);
			eventHandler->move(4-i, 4-i);
		}
		QVERIFY2(!QString::compare(message, "Player X win"), "Incorrect winner");
	}

	void checkChainLongerThanMaxChain()
	{
		for (int i = 0; i < 3; i++)
		{
			eventHandler->move(1, i);
			eventHandler->move(2, i);
		}

		for (int i = 4; i < 7; i++)
		{
			eventHandler->move(1, i);
			eventHandler->move(2, i);
		}

		eventHandler->move(1,3);
		QVERIFY2(!QString::compare(message, "Player X win"), "Incorrect winner");
	}
};
