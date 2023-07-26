#ifndef FONCTIONS_H
#define FONCTIONS_H

// #include <SDL2/SDL_ttf.h>
// #include <SDL2/SDL.h>

typedef struct      s_sudoku
{
    // SDL_Window      *window;
    // SDL_Renderer    *renderer;
    // SDL_Texture     *bigFonts[9];

    int             range[9];
    int             grid[9][9];
    int             gridClone[9][9];
    int             megaTab[9][9][9];
}                   sudoku;

/*
Trouver une case vide
*/
int case_vide(sudoku *sud, int *x, int *y);

/*
Tester si un chiffre est valide
*/
int test_chiffre(int n, sudoku *sud, int x, int y);

/*
Recursivite pour solutionner le sudoku
*/
int solver(sudoku *sud);

/* 
mélanger les chiffre
*/
void shuffle(sudoku *sud);

/*
remplace des chiffre aléatoire par zéro
*/
void remove(sudoku *sud, int number_to_remove);

/*
résout les sudoku de manière humainement possible
*/
int gridasse(sudoku *sud);

/*
cherche plusieur réponse possible
*/
int idiot_solver(sudoku *sud);


/*

*/
int celib_nu(sudoku *sud);


/*

*/
int clib_cache(sudoku *sud);















#endif