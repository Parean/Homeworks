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
	unsigned int hashCalculate(const QString &str, int hashTableSize) const;
};
