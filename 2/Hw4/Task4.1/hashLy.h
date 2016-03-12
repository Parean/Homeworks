#pragma once

#include "hashFunction.h"

class HashLy : public HashFunction
{
public:
	HashLy(int hashSize);
	unsigned int hashCalculate(QString str, int hashTableSize) const;
};
