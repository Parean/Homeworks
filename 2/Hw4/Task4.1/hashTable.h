#pragma once

#include "hashFunction.h"
#include "listPointer.h"
#include "hashFaq6.h"
#include "hashLy.h"
#include "hashRot13.h"

/**
 * @brief The KindOfFunction enum
 * It contains the names of hash functions, which the user can select to calculate the hash
 */
enum KindOfFunction
{
	faq6,
	ly,
	rot
};

/**
 * @class HashTable
 * The class implements hashtable using lists to resolve collisions
 */
class HashTable
{
public:
	HashTable(int hashSize);
<<<<<<< HEAD
	void addInTable(QString &value);
	void removeFromTable(QString &value);
	bool isPlaced(QString &value) const;
=======
	void addInTable(const QString &value);
	void removeFromTable(const QString &value);
	bool isPlaced(const QString &value) const;
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
	void getStatistic() const;
	int findMaxCollision() const;
	void switchHashFunction(KindOfFunction kind);
	~HashTable();

private:
	ListPointer **hashTable;
	HashFunction *hashFunction;
	KindOfFunction kindOfFunction;
	int hashTableSize;
	int numberOfCollisions;
	int numberOfElements;

	/**
	 * @brief increaseHashTable
	 * The function is automatically called if the load factor becomes >= 10
	 * @return Hastable, size of which is twice more than was
	 */
	ListPointer **increaseHashTable();

	/**
<<<<<<< HEAD
	 * @brief rebuilding
=======
	 * @brief rebuild
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
	 * The function is automatically called from functions "increaseHashTable"
	 * and "switchHashFunction". It creates a new table and overwrites the data into it
	 * @return New hashtable
	 */
<<<<<<< HEAD
	ListPointer **rebuilding(int sizeOfNewTable);
=======
	ListPointer **rebuild(int sizeOfNewTable);
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
};
