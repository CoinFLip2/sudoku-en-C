#include "fonctions.h"

int gridasse(sudoku *sud)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sud->grid[i][j] == 0)
            {
                for (int n = 1; n < 10; n++)
                {
                    if (test_chiffre(n, sud->gridClone, i, j))
                    {
                        sud->megaTab[i][j][n - 1] = 1;
                    }
                    else
                    {
                        sud->megaTab[i][j][n - 1] = 0;
                    }
                }
            }
        }
    }
    return 0;
}