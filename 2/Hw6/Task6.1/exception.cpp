#include "exception.h"

Exception::Exception(const char *message)
	: message(message) {}

void Exception::throwException()
{
	throw Exception("Something happened");
}
