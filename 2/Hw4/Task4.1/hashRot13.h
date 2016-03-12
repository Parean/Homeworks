#pragma once

#include "hashFunction.h"

class HashRot13 : public HashFunction
{
public:
	HashRot13(int hashSize);
	unsigned int hashCalculate(QString str, int hashTableSize) const;
};
