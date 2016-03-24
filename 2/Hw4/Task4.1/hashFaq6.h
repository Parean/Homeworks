#pragma once

#include "hashFunction.h"

/**
 * @class HashFaq6
 * The class implements a function that finds a hash by using bit shifts and the operation "xor"
 * The function was taken from here: http://vak.ru/doku.php/proj/hash/sources
 * and has the original author's name
 */
class HashFaq6 : public HashFunction
{
public:
	HashFaq6(int hashSize);
	unsigned int hashCalculate(QString &str, int hashTableSize) const;
};
