#include "sharedptrtester.h"

int main()
{
	SharedPtrTester test;
	QTest::qExec(&test);
	return 0;
}
