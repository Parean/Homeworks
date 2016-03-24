#pragma once

#include "hashFunction.h"

/**
 * @class HashFaq6
 * The class implements a function that finds a hash by using bit shifts and the operation "or"
 * The function was taken from here: http://vak.ru/doku.php/proj/hash/sources
 * and has the original author's name
 */
class HashRot13 : public HashFunction
{
public:
	HashRot13(int hashSize);
	unsigned int hashCalculate(QString &str, int hashTableSize) const;
};
