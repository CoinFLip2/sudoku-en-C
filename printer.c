#include "printer.h"

void printGrid(table *grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d", grid[i].array[j]);
        }
        printf("\n");
    }
}