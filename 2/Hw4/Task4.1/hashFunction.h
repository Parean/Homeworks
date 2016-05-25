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
	HashFunction() {}
	virtual ~HashFunction() {}

	///@return a value in the interval from 0 to hashTableSize-1
	virtual unsigned int hashCalculate(const QString &str, int hashTableSize) const = 0;
};

