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
<<<<<<< HEAD
	HashFaq6(int hashSize);
	unsigned int hashCalculate(QString &str, int hashTableSize) const;
=======
	HashFaq6() {}
	~HashFaq6() {}

	unsigned int hashCalculate(const QString &str, int hashTableSize) const;
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
};
