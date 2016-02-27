#include "consolOutputer.h"
#include "fileOutputer.h"
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int size = 11;
    printf("The program outputs the array in a spiral, "
           "to select the output type, use the keyboard"
           "\n\nThe initial array:\n\n");
    int **numbers = new int *[size];
    for (int i = 0; i < size; i++)
        numbers[i] = new int[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            numbers[i][j] = 0 + rand() % 9;
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    printf("\n\nMenu:\n\n 1 - Output to consol\n 2 - Output to file\n\n");
    int kind = 0;
    scanf("%d", &kind);
    Outputer *outputer = nullptr;
    switch (kind)
    {
    case file:
    {
                 outputer = new FileOutputer(numbers, size);
                 break;
    }
    case consol:
    {
                 outputer = new ConsolOutputer(numbers, size);
    }
    }
    outputer->output();
    for (int i = 0; i < size; i++)
        delete[] numbers[i];
    delete[] numbers;
}
