#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

#define CELL_SIZE 50
#define CELL_MARGIN 5
#define GRID_SIZE ((CELL_SIZE * 9))
#define FONT_SIZE (CELL_SIZE - CELL_MARGIN * 2)
#define WINDOW_WIDTH (GRID_SIZE)
#define WINDOW_HEIGHT (GRID_SIZE)
#define WIDTHSCREEN 800
#define HEIGHTSCREEN 600


typedef struct      s_sudoku
{
    SDL_Window      *window;
    SDL_Renderer    *renderer;
    SDL_Texture     *gridTexture;
    SDL_Texture     *cellTexture[9];
    int gridPos[9];

    int             range[9];
    int             grid[9][9];
    int             gridClone[9][9];
    int             megaTab[9][9][9];

    int selectedCellX;
    int selectedCellY;
}                   sudoku;

/*
Trouver une case vide
*/
int case_vide(int grid[9][9], int *x, int *y);

/*
Tester si un chiffre est valide
*/
int test_chiffre(int n, int grid[9][9], int x, int y);

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
void removes(sudoku *sud, int number_to_remove);

/*
résout les sudoku de manière humainement possible
*/
int gridasse(sudoku *sud);

/*
cherche plusieur réponse possible
*/
int idiot_solver(sudoku *sud);

int celib_nu(sudoku *sud);

int clib_cache(sudoku *sud);

int segment(sudoku *sud);

int segment2(sudoku *sud);

int main(int argc, char **argv);

void innitGraphics(sudoku *sud);

void quitGraphics(sudoku *sud);

void drawSudoku(SDL_Renderer* pRenderer, sudoku* sud);




#endif