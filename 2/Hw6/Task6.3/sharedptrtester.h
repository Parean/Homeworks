#pragma once

#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "sharedptr.h"

class SharedPtrTester : public QObject
{
	Q_OBJECT

public:
	explicit SharedPtrTester(QObject *parent = 0):
		QObject(parent)
	{}

private slots:

	void testCreatePointer()
	{
		SharedPtr<int> ptr1(new int(70));
	}

	void testDereference()
	{
		SharedPtr<int> ptr1(new int(70));
		QVERIFY2(*ptr1 == 70, "Dereference incorrectly");
	}

	void testReturnPointer()
	{
		SharedPtr<int> ptr1(new int(70));
		QVERIFY2(*ptr1.get() == 70, "Pointer was not returned");
	}

	void testAssignment()
	{
		SharedPtr<int> ptr1(new int(1));
		SharedPtr<int> ptr2(new int(2));
		ptr2 = ptr1;
		QVERIFY2(ptr1.get() == ptr2.get(), "After assignment the values do not match");
	}

	void testUseCount()
	{
		SharedPtr<int> ptr1(new int(1));
		QVERIFY2(ptr1.useCount() == 1, "useCount returns incorrect value");
	}

	void testAssignmentAndUseCount()
	{
		SharedPtr<int> ptr1(new int(1));
		QVERIFY2(ptr1.useCount() == 1, "useCount returns incorrect value");
		SharedPtr<int> ptr2(new int(2));
		ptr2 = ptr1;
		QVERIFY2(ptr1.get() == ptr2.get(), "After assignment the values do not match");
		QVERIFY2(ptr1.useCount() == 2, "useCount or assignmenr work incorrectly");
	}

	void testCopyConstructor()
	{
		SharedPtr<int> ptr1(new int(42));
		SharedPtr<int> ptr2(ptr1);
		QVERIFY2(ptr1.get() == ptr2.get(), "After copying the values do not match");
		QVERIFY2(ptr1.useCount() == 2, "The object is incorrectly created");
	}

	void testUnique()
	{
		SharedPtr<int> ptr1(new int(42));
		QVERIFY2(ptr1.unique(), "unique returnes incorrect value");
	}

	void testSwap()
	{
		SharedPtr<int> ptr1(new int(1));
		SharedPtr<int> ptr2(new int(2));
		ptr1.swap(ptr2);
		QVERIFY2(*ptr1.get() == 2, "Value was lost");
		QVERIFY2(*ptr2.get() == 1, "Value was lost");
	}

	void testDestructor()
	{
		SharedPtr<int> ptr1(new int(7));
		auto ptr2 = new SharedPtr<int>(ptr1);
		delete ptr2;
		QVERIFY2(ptr1.unique(), "Destructor work incorrectly");
	}
};
