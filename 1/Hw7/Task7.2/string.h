#pragma once

struct String
{
	char *symbols;
	int size;
};

enum Comparison
{
	equivalent = 0,
	bigger,
	smaller
};

String *createString();
String *clone(String *string);
String *concatenation(String *string, String *argument);
int returnLength(String *string);
Comparison comparisonOfStrings(String *firstString, String *secondString);
String *returnSubstring(String *string, int position, int length);
bool stringIsEmpty(String *string);
char *stringToChar(String *string);