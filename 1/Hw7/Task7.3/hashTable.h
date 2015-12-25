#pragma once
#include "string.h"
#include "List.h"

List **createHashTable(int hashSize);
int hashFunction(String *value, int hashSize);
void rebuilging(List *list, List **newHashTable, int hashSize, int count, bool isRebuilding);
void deleteHashTable(int hashSize, bool isRebuilding, List **hashTable);
List **increaseHashTable(int &hashSize, List **hashTable, int count);