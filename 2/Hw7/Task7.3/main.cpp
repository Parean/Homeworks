#include <QApplication>

#include "mainwindow.h"
#include "eventHandlerTester.h"

int main(int argc, char *argv[])
{
	GameTester tester;
	QTest::qExec(&tester);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
