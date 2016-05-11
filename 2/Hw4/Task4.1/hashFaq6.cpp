#include "hashFaq6.h"

unsigned int HashFaq6::hashCalculate(const QString &str, int hashTableSize) const
{
	QByteArray byteArray = str.toLocal8Bit();
	char *string = byteArray.data();
	unsigned int hash = 0;

	for (; *string; string++)
	{
		hash += (unsigned char)(*string);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash % hashTableSize;
}
