#include "fonctions.h"

int clib_cache(sudoku *sud)
{
    int return_value = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sud->gridClone[i][j] == 0)
            {
                int last = 0;
                for (int n = 0; n < 9; n++)
                {
                    if (sud->megaTab[i][j][n] == 1)
                    {
                        for (int x = 0; x < 9; x++)
                        {
                            if (sud->megaTab[x][j][n] == 1)
                            {
                                last++;
                            }
                        }
                        if (last == 1)
                        {
                            sud->gridClone[i][j] = n + 1;
                            return_value++;
                        }
                        last = 0;
                        for (int y = 0; y < 9; y++)
                        {
                            if (sud->megaTab[i][y][n] == 1)
                            {
                                last++;
                            }
                        }
                        if (last == 1)
                        {
                            sud->gridClone[i][j] = n + 1;
                            return_value++;
                        }
                        last = 0;
                        int _i = 3 * (i / 3);
                        int _j = 3 * (j / 3);
                        for (int x = _i; x < _i + 3; x++)
                        {
                            for (int y = _j; y < _j + 3; y++)
                            {
                                if (sud->megaTab[x][y][n] == 1)
                                {
                                    last++;
                                }
                            }
                        }
                        if (last == 1)
                        {
                            sud->gridClone[i][j] = n + 1;
                            return_value++;
                        }
                    }
                }
            }
        }
    }
    return return_value;
}