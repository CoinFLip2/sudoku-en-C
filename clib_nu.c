#include "fonctions.h"

int celib_nu(sudoku *sud)
{
    int collect_true;
    int last;
    int return_value = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sud->gridClone[i][j] == 0)
            {
                collect_true = 0;
                for (int n = 0; n < 9; n++)
                {
                    if (sud->megaTab[i][j][n] == 1)
                    {
                        collect_true++;
                        last = n + 1;
                    }
                    if (collect_true == 1)
                    {
                        sud->gridClone[i][j] = last;
                        return_value++;
                    }
                }
            }
        }
    }
    return return_value;
}