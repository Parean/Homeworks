#include "networktester.h"
#include "network.h"

int main()
{
    NetworkTester networkTester;
    QTest::qExec(&networkTester);
}

