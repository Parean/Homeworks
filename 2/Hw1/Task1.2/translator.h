#pragma once
#include "stackArray.h"
#include "stackPointer.h"

class Translator
{
public:
	Translator(kindOfStack kind, char *string);
	char *translation();
	~Translator();
private:
	Stack *stack;
	char *inputString;
	bool isPlusOrMinus() const;
	bool isAsteriskOrSlash() const;
};


