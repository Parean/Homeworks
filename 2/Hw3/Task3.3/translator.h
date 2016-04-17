#pragma once

#include "stackPointer.h"

/**
 * @class Translator
 * It translates the input expression into postfix form
 */
class Translator
{
public:
	Translator(char *string);

	/// @return The expression in the Polish notation
	char *translation();
	~Translator();

private:
	StackPointer *stack;
	char *inputString;

	bool isPlusOrMinus() const;
	bool isAsteriskOrSlash() const;
};


