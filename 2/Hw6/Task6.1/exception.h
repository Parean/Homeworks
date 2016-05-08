#pragma once

class Exception
{
public:
	Exception(const char *message);
	static void throwException();

private:
	const char *message;
};


