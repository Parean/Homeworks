#pragma once

#include <QString>
#include <QByteArray>

/**
 * @class HashFunction
 * Virtual class from which inherit other classes
 * with different implementations of hash functions
 */
class HashFunction
{
public:
<<<<<<< HEAD
	HashFunction(int hashSize);

	///@return a value in the interval from 0 to hashTableSize-1
	virtual unsigned int hashCalculate(QString &str, int hashTableSize) const = 0;

private:
	int hashTableSize;
=======
	HashFunction() {}
	virtual ~HashFunction() {}

	///@return a value in the interval from 0 to hashTableSize-1
	virtual unsigned int hashCalculate(const QString &str, int hashTableSize) const = 0;
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
};

