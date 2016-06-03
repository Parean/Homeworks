#include "hashTable.h"

HashTable::HashTable(int hashSize):
<<<<<<< HEAD
	hashTableSize(hashSize),
	numberOfElements(0),
	numberOfCollisions(0),
	kindOfFunction(faq6)
=======
	kindOfFunction(faq6),
	hashTableSize(hashSize),
	numberOfCollisions(0),
	numberOfElements(0)
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
{
	hashTable = new ListPointer *[hashTableSize];
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = new ListPointer;
	}
<<<<<<< HEAD
	hashFunction = new HashFaq6(hashTableSize);
}

void HashTable::addInTable(QString &value)
=======
	hashFunction = new HashFaq6();
}

void HashTable::addInTable(const QString &value)
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
{
	unsigned int index = hashFunction->hashCalculate(value, hashTableSize);
	hashTable[index]->addInList(value);
	if (numberOfElements / hashTableSize >= 10)
		hashTable = increaseHashTable();
	if (hashTable[index]->length() > 1)
		numberOfCollisions++;
	numberOfElements++;
}

ListPointer **HashTable::increaseHashTable()
{
<<<<<<< HEAD
	return rebuilding(hashTableSize * 2);
}

ListPointer **HashTable::rebuilding(int sizeOfNewTable)
=======
	return rebuild(hashTableSize * 2);
}

ListPointer **HashTable::rebuild(int sizeOfNewTable)
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
{
	int index = 0;
	ListPointer **newHashTable = new ListPointer *[sizeOfNewTable];
	for (int i = 0; i < sizeOfNewTable; i++)
		newHashTable[i] = new ListPointer;
	for (int i = 0; i < hashTableSize; i++)
	{
		while(!hashTable[i]->isEmpty())
		{
			QString value = hashTable[i]->pop();
			index = hashFunction->hashCalculate(value, sizeOfNewTable);
			newHashTable[index]->addInList(value);
		}
		delete hashTable[i];
	}
	hashTableSize = sizeOfNewTable;
	return newHashTable;
}

void HashTable::switchHashFunction(KindOfFunction kind)
{
	kindOfFunction = kind;
	switch (kindOfFunction)
	{
	case faq6:
<<<<<<< HEAD
		hashFunction = new HashFaq6(hashTableSize);
		break;
	case ly:
		hashFunction = new HashLy(hashTableSize);
		break;
	case rot:
		hashFunction = new HashRot13(hashTableSize);
		break;
	}
	hashTable = rebuilding(hashTableSize);
}

void HashTable::removeFromTable(QString &value)
=======
		hashFunction = new HashFaq6();
		break;
	case ly:
		hashFunction = new HashLy();
		break;
	case rot:
		hashFunction = new HashRot13();
		break;
	}
	hashTable = rebuild(hashTableSize);
}

void HashTable::removeFromTable(const QString &value)
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
{
	unsigned int index = hashFunction->hashCalculate(value, hashTableSize);
	hashTable[index]->removeValue(value);
	if (hashTable[index]->length() > 0)
		numberOfCollisions--;
	numberOfElements--;
}

<<<<<<< HEAD
bool HashTable::isPlaced(QString &value) const
=======
bool HashTable::isPlaced(const QString &value) const
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
{
	unsigned int index = hashFunction->hashCalculate(value, hashTableSize);
	return hashTable[index]->findPositionOfValue(value) != -1;
}

void HashTable::getStatistic() const
{
	printf("Statistic:\n\nNumber of elements: %d\n", numberOfElements);
	printf("Load factor: %d\n", numberOfElements / hashTableSize);
	printf("Number of collisions: %d\n", numberOfCollisions);
	printf("Maximum length of collision: %d\n", findMaxCollision());
	printf("Kind of hash function - ");
	switch (kindOfFunction)
	{
	case faq6:
		printf("FAQ6\n");
		break;
	case ly:
		printf("Ly\n");
		break;
	case rot:
		printf("Rot13\n");;
		break;
	}
}

int HashTable::findMaxCollision() const
{
	if (numberOfCollisions == 0)
		return 0;
	int maxCollision = 0;
	int length = 0;
	for(int i = 0; i < hashTableSize; i++)
	{
		length = hashTable[i]->length();
		if (length > maxCollision)
			maxCollision = length;
	}
	return maxCollision;
}

HashTable::~HashTable()
{
	for (int i = 0; i < hashTableSize; i++)
		delete hashTable[i];
	delete[] hashTable;
}
