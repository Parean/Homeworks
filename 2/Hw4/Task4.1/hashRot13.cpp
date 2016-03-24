#include "hashRot13.h"

HashRot13::HashRot13(int hashSize) : HashFunction(hashSize){}

unsigned int HashRot13::hashCalculate(QString &str, int hashTableSize) const
{
	QByteArray byteArray = str.toLocal8Bit();
	char *string = byteArray.data();
	unsigned int hash = 0;

	for(; *string; string++)
	{
		hash += (unsigned char)(*string);
		hash -= (hash << 13) | (hash >> 19);
	}

	return hash % hashTableSize;
}
