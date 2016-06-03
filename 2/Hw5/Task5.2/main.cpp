#include <iostream>

#include "setTester.h"

int main()
{
	SetTester setTester;
	QTest::qExec(&setTester);
}
