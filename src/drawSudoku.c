#include"fonctions.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


// Fonction pour dessiner les numéros de la grille de Sudoku sur la fenêtre
void drawSudoku(SDL_Renderer* pRenderer, sudoku* sud) 
{
    int cellSize = CELL_SIZE;


    TTF_Font* font = TTF_OpenFont("SHORTBABY-MG2W.TTF", 16); // Remplacez le chiffre par la taille de police souhaitée
    SDL_Color textColor = { 0, 0, 0, 255 }; // Couleur noire pour le texte

    // Parcourez la grille de Sudoku et dessinez les chiffres
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) 
        {
            int num = sud->grid[y][x];
            if (num != 0) 
            {
                char numStr[2] = {num + '1', 0};
                // snprintf(numStr, sizeof(numStr), "%d", num);
                // Calculer la position pour dessiner le nombre au centre de la cellule
                int textX = x * cellSize + cellSize / 2;
                int textY = y * cellSize + cellSize / 2;

                // Créez une texture à partir de la chaîne numérique et affichez-la sur la fenêtre
                SDL_Surface* textSurface = TTF_RenderText_Solid(font, numStr, textColor);
                SDL_Texture* textTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);

                SDL_Rect textRect;
                textRect.x = textX - textSurface->w / 2;
                textRect.y = textY - textSurface->h / 2;
                textRect.w = textSurface->w;
                textRect.h = textSurface->h;

                SDL_RenderCopy(pRenderer, textTexture, NULL, &textRect);

                SDL_DestroyTexture(textTexture);
                SDL_FreeSurface(textSurface);
            }
        }
    }
    
    TTF_CloseFont(font);
}