#include "virustester.h"
#include "networktester.h"
#include "network.h"

int main()
{

    VirusTester virusTester;
    QTest::qExec(&virusTester);

    NetworkTester networkTester;
    QTest::qExec(&networkTester);

	Network network(5);
	network.start();
}

