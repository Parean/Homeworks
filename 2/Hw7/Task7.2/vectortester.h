#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include "vector.h"

class VectorTester : public QObject
{
	Q_OBJECT

public:
	explicit VectorTester(QObject *parent = 0):
		QObject(parent)
	{
		srand(time(0));
	}

private:
	static const int size = 10;
	int array[size];

private slots:

	void initTestCase()
	{
		for (int i = 0; i < size; i++)
			array[i] = rand() % size;
	}

	void testCreateEmptyVector()
	{
		Vector<size> vector;
		QVERIFY(vector.isNull());
	}

	void testAt()
	{
		Vector<size> vector(array);
		for (int i = 0; i < size; i++)
		{
			QVERIFY2(vector.at(i) == array[i], "At return incorrect value");
		}
	}

	void testEqualOperator()
	{
		int array2[size];
		for(int i = 0; i < size; i++)
			array2[i] = array[i] + 1;

		Vector<size> firstVector(array);
		Vector<size> secondVector(array2);
		QVERIFY(!(firstVector == secondVector));

		Vector<size> thirdVector(array);
		QVERIFY(firstVector == thirdVector);
	}

	void testCopyConstructor()
	{
		Vector<size> vector(array);
		Vector<size> secondVector(vector);

		QVERIFY2(vector == secondVector, "Vectors must be equaly");
	}

	void testOutOfRange()
	{
		Vector<size> vector;
		QVERIFY_EXCEPTION_THROWN(vector.at(-12), OutOfRange);
		QVERIFY_EXCEPTION_THROWN(vector.at(25), OutOfRange);
	}

	void testSumOperator()
	{
		int array2[size];
		for(int i = 0; i < size; i++)
			array2[i] = -array[i];

		Vector<size> firstVector(array);
		Vector<size> secondVector(array2);
		Vector<size> resultVector = secondVector + firstVector;

		QVERIFY(resultVector.isNull());
	}

	void testDifferenceOperator()
	{
		int array2[size];
		for(int i = 0; i < size; i++)
			array2[i] = array[i];

		Vector<size> firstVector(array);
		Vector<size> secondVector(array2);
		Vector<size> resultVector = secondVector - firstVector;

		QVERIFY(resultVector.isNull());
	}

	void testScalarProduct()
	{
		int array2[size];
		for(int i = 0; i < size; i++)
			array2[i] = array[i] + 5;

		Vector<size> vector(array);
		Vector<size> secondVector(array2);

		int product = 0;
		for (int i = 0; i < size; i++)
		{
			product += array[i] * array2[i];
		}
		QVERIFY2(product == (vector * secondVector), "Scalar product return incorrect result");
	}
};
