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
	HashFunction(int hashSize);
	virtual unsigned int hashCalculate(QString str, int hashTableSize) const = 0;

private:
	int hashTableSize;
};

