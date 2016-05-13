#include <QtCore/QCoreApplication>
#include "listTester.h"

int main()
{
	ListTester tester;
	QTest::qExec(&tester);
}

