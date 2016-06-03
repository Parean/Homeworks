#include "hashLy.h"

<<<<<<< HEAD
HashLy::HashLy(int hashSize) : HashFunction(hashSize){}

unsigned int HashLy::hashCalculate(QString &str, int hashTableSize) const
=======
unsigned int HashLy::hashCalculate(const QString &str, int hashTableSize) const
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
{
	QByteArray byteArray = str.toLocal8Bit();
	char *string = byteArray.data();
	unsigned int hash = 0;

	for(; *string; string++)
		hash = (hash * 1664525) + (unsigned char)(*string) + 1013904223;

	return hash % hashTableSize;
}
