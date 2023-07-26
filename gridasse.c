#include "fonctions.h"

int gridasse(sudoku *sud)
{
    for i
    {
        for j
        {
            if (sud->grid[i][j] == 0)
            {
                for (int n = 1; n < 10; n++)
                {
                    if testchiffre[n]
                    {
                        sud->gridClone[i][j][n - 1] = true;
                    }
                    else
                    {
                        sud->gridClone[i][j][n - 1] = false;
                    }
                }
            }
        }
    }
}