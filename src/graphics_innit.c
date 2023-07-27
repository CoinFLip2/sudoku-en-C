#include"fonctions.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>





void innitGraphics(sudoku *sud)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    sud -> window = SDL_CreateWindow("Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    sud -> renderer = SDL_CreateRenderer(sud -> window, -1, SDL_RENDERER_ACCELERATED);
    // init_grid_surface(sud);
    // init_font(sud);
}    

void quitGraphics(sudoku *sud)
{
    SDL_DestroyRenderer(sud -> renderer);
    SDL_DestroyWindow(sud -> window);
    // SDL_DestroyTexture(sud -> gridTexture);
    TTF_Quit();
    SDL_Quit();
    // for (int i = 0; i < 9; i++)
    //     SDL_DestroyTexture(sud -> cellTexture[i]);
}