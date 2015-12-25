#include "Stack.h"
#include "List.h"
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = nullptr;
	char symbol = 0;
	if ((file = fopen("text.txt", "r")) == nullptr)
		printf("Ошибка открытия файла\n");
	else
	{
		printf("Однострочные комментарии: \n\n");
		Stack *stack = createStack();
		List *list = createList();
		bool beginOfComment = true;
		while (!feof(file))
		{
			beginOfComment = true;
			symbol = 0;
			while (!feof(file) && symbol != '\n')
			{
				fscanf(file, "%c", &symbol);
				if (beginOfComment)
				{
					if (symbol == '\"' && (stackIsEmpty(stack) || lookInStack(stack) != '('))
					{
						if (stackIsEmpty(stack))
							addInStack('\"', stack);
						else
							pop(stack);
					}
					if (symbol == '*')
					{
						if (lookInStack(stack) == '/')
						{
							pop(stack);
							addInStack('(', stack);
						}
						else if (lookInStack(stack) != '\"')
							addInStack('*', stack);
					}
					if (symbol == '/')
					{
						if (stackIsEmpty(stack))
							addInStack(symbol, stack);
						else {
							if (lookInStack(stack) == '*')
							{
								pop(stack);
								pop(stack);
							}
							else if (lookInStack(stack) == '/')
							{
								addInList(pop(stack), list);
								addInList(symbol, list);
								beginOfComment = false;
							}
						}
					}
				}
				else
					addInList(symbol, list);
			}
			if (!beginOfComment)
			{
				printList(list);
				deleteList(list);
				List *list = createList();
			}
		}
		deleteList(list);
		deleteStack(stack);
		fclose(file);
	}
	
}

