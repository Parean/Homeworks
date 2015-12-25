#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = nullptr;
	char symbol = 0;
	if ((file = fopen("text.txt", "r")) == NULL)
		printf("ќшибка открыти€ файла\n");
	else
	{
		const int size = 58;
		bool used[size];
		for (int i = 0; i < size; i++)
			used[i] = false;
		printf("—лова из текста без повтор€ющихс€ букв:\n\n");
		while (!feof(file))
		{
			fscanf(file, "%c", &symbol);
			if (symbol == ' ' || symbol == '\n')
			{
				for (int i = 0; i < size; i++)
					used[i] = false;
				printf("%c", symbol);
			}
			else if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
			{
				if (!used[symbol - 'A'])
					printf("%c", symbol);
				used[symbol - 'A'] = true;
			}
			else
				printf("%c", symbol);
		}
		fclose(file);
	}
}