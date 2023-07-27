#include <stdlib.h>
#include "fonctions.h"

void shuffle(sudoku *sud)
{
    for (int i = 0; i < 9; i++)
    {
        sud->range[i] =  i + 1;
    }
    int resulta_temporaire;
    for (int i = 0; i < 9; i++)
    {
        int n = rand()%9;
        resulta_temporaire = sud->range[i];
        sud->range[i] = sud->range[n];
        sud->range[n] = resulta_temporaire;
    }
}