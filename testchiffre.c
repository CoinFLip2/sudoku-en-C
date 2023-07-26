#include "fonctions.h"

int test_chiffre(int n, int grid[9][9], int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][y] == n)
        {
            return 0;
        }
    }

    for (int j = 0; j < 9; j++)
    {
        if (grid[x][j] == n)
        {
            return 0;
        }
    }

    int _i = 3 * (x / 3);
    int _j = 3 * (y / 3);

    for (int i = _i; i < _i + 3; i++)
    {
        for (int j = _j; j < _j + 3; j++)
        {
            if (grid[i][j] == n)
                return 0;
        }
    }
    return 1;
}
