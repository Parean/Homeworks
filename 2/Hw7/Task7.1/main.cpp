#include "bagtester.h"

int main()
{
	BagTester bagTester;
	QTest::qExec(&bagTester);
}
