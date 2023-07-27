#include "fonctions.h"

int solver(sudoku *sud)
{
    int x;
    int y;
    if (case_vide(sud -> grid, &x, &y) == 0)
    {
        return 1;
    }
       
    for (int n = 0; n < 9; n++)
    {
        if (test_chiffre(sud->range[n], sud->grid, x, y) == 1)
        {
            sud->grid[x][y] = sud->range[n];

            if (solver(sud) == 1)
            {
                return 1;
            }
                
            sud->grid[x][y] = 0;
        }
    }
    return 0;
}
