#include "hashRot13.h"

<<<<<<< HEAD
HashRot13::HashRot13(int hashSize) : HashFunction(hashSize){}

unsigned int HashRot13::hashCalculate(QString &str, int hashTableSize) const
=======
unsigned int HashRot13::hashCalculate(const QString &str, int hashTableSize) const
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
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
