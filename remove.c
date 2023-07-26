#include <stdlib.h>
#include "fonctions.h"

void remove(sudoku *sud, int number_to_remove)
{
    int rand_x;
    int rand_y;

    for (int i = 0; i < number_to_remove; i++)
    {
        int x = rand() % 9;
        int y = rand() % 9;

        if (sud->grid[rand_x][rand_y] == 0)
        {
            i--;
        }   

        int stock_fantom = sud -> grid[rand_x][rand_y];
        sud->grid[rand_x][rand_y] = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                sud -> gridClone[i][j] = sud -> grid[i][j];
                printf("%i ",sud -> gridClone[i][j] );
            }
            
        }
        if (idiot_solver(sud) == 0)
        {
            sud -> grid[rand_x][rand_y] = stock_fantom;
        }
    }
}
