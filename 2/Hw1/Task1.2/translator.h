#pragma once
#include "stackArray.h"
#include "stackPointer.h"

/**
 * @class Translator
 * It translates the input expression into postfix form
 */
class Translator
{
public:
    Translator(KindOfStack kind, char *string);

    /// @return The expression in the Polish notation
    char *translation();
	~Translator();
private:
	Stack *stack;
	char *inputString;

	bool isPlusOrMinus() const;
	bool isAsteriskOrSlash() const;
};


