#pragma once

#include "hashFunction.h"

class HashFaq6 : public HashFunction
{
public:
	HashFaq6(int hashSize);
	unsigned int hashCalculate(QString str, int hashTableSize) const;
};
