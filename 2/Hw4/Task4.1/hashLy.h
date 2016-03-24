#pragma once

#include "hashFunction.h"

/**
 * @class HashLy
 * The class implements a function that finds a hash by using multiplication of the number 1664525
 * and addition of the number 1013904223
 * The function was taken from here: http://vak.ru/doku.php/proj/hash/sources
 * and has the original author's name
 */
class HashLy : public HashFunction
{
public:
	HashLy(int hashSize);
	unsigned int hashCalculate(QString &str, int hashTableSize) const;
};
