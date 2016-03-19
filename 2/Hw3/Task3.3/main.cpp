#include "mainwindow.h"
#include "calculatorTester.h"
#include "translatorTester.h"

#include <QApplication>

void testOfComponents()
{
	TranslatorTester translatorTester;
	QTest::qExec(&translatorTester);
	CalculatorTester calculatorTester;
	QTest::qExec(&calculatorTester);
}

int main(int argc, char *argv[])
{
	testOfComponents();
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
