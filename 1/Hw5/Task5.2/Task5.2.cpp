#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите число\n");
	double number = 0;
	cin >> number;
	unsigned char *bytes = (unsigned char*)&number;
	int exponent = (unsigned)bytes[7] % 128 * 16 + (unsigned)bytes[6] / 16 - 1023;
	double mantissa = 1;
	long long degree = 2;
	for (int i = 8; i >= 1; i /= 2)
	{
		mantissa += (unsigned)bytes[6] / i % 2 * (1.0 / degree);
		degree *= 2;
	}
	for (int i = 5; i >= 0; i--)
	{
		for (int j = 128; j >= 1; j /= 2)
		{
			mantissa += (unsigned)bytes[i] / j % 2 * (1.0 / degree);
			degree *= 2;
		}
	}
	bool sign = (unsigned)bytes[7] / 128;
	printf("\n„исло в экспоненциальной форме:\n\n");
	if (sign)
		printf("-");
	else
		printf("+");
	printf("%.52g*2^(%d)", mantissa, exponent);
}
