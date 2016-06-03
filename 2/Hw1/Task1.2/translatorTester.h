#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "translator.h"

class TranslatorTester : public QObject
{
	Q_OBJECT
public:
	explicit TranslatorTester(QObject *parent = 0) : QObject(parent) {}

private:
	Translator *translator;

private slots:
	void init()
	{
		translator = new Translator(array, "5*5-34\0");
	}

	void cleanup()
	{
		delete translator;
	}

	void testTranslation()
	{
		QString string = translator->translation();
		QVERIFY2(QString::compare(string, "5 5 * 34 - \0") == 0, "Incorrect expression");
	}
};
