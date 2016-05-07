#include "hashLy.h"

HashLy::HashLy(int hashSize) : HashFunction(hashSize){}

unsigned int HashLy::hashCalculate(const QString &str, int hashTableSize) const
{
	QByteArray byteArray = str.toLocal8Bit();
	char *string = byteArray.data();
	unsigned int hash = 0;

	for(; *string; string++)
		hash = (hash * 1664525) + (unsigned char)(*string) + 1013904223;

	return hash % hashTableSize;
}
