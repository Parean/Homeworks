#include <stdio.h>
#include "listArray.h"
#include "listPointer.h"

enum
{
    exit,
    add,
    find,
    del,
    empty,
    length
};

int main()
{

    List *list = new ListArray();
    int state = -1;
    int value = 0;
    printf("This program tests the list functions\n\nMenu:\n\n"
           " 0 - Exit\n"
           " 1 - Add new element\n"
           " 2 - Find position of element\n"
           " 3 - Remove element from list\n"
           " 4 - Check the list for emptiness\n"
           " 5 - To know the length of the list\n");
    while(state)
    {
        printf("\nEnter the number\n");
        scanf("%d", &state);
        switch(state)
        {
        case add:
        {
            printf("\nEnter the value\n");
            scanf("%d", &value);
            list->addValue(value);
            break;
        }
        case find:
        {
            printf("\nEnter the value\n");
            scanf("%d", &value);
            int index = list->findPositionOfValue(value);
            if (index >= 0)
                printf("\nPosition of element - %d\n", index);
            else
                printf("\nIn the list there is no element with that value\n");
            break;
        }
        case del:
        {
            printf("\nEnter the value\n");
            scanf("%d", &value);
            list->removeValue(value);
            break;
        }
        case empty:
        {
            if (list->isEmpty())
                printf("\nList is empty\n");
            else
                printf("\nList is not empty\n");
            break;
        }
        case length:
            printf("\nThe length of the list - %d\n", list->length());
        }
    }
    delete list;
}
