#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "strsplit.h"
#include "printer.h"
#include "fonctions.h"
#include <time.h>
#include <windows.h>
#include <SDL2/SDL.h>

// afficher le fichier, utiliser split, créer un tableau d'entier avec les chiffres récupérés

int main(int ac, char **av)
{
    sudoku sud;
    srand(time(NULL));
    if (ac < 2)
    {
        printf("Usage: %s <file>\n", av[0]);
        return 1;
    }
    FILE *file = fopen(av[1], "r");
    if (!file)
    {
        printf("Error: could not open file %s\n", av[1]);
        return 1;
    }

    char line[1024];

    int j = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *pWindow = NULL;
    SDL_Renderer *pRenderer = NULL;

    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Event events;
    int isOpen = 1;

    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = 0;
                break;
            }
        }

        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderClear(pRenderer);

        SDL_Point point = {800 / 2, 600 / 2};
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

        SDL_RenderDrawPoint(pRenderer, point.x, point.y);

        SDL_RenderPresent(pRenderer);
    }

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return EXIT_SUCCESS;

    while (fgets(line, sizeof(line), file))
    {
        char **tab = strsplit(line, ' ');
        for (int i = 0; tab[i]; i++)
        {
            int num = atoi(tab[i]);
            sud.grid[j][i] = num;
            free(tab[i]);
        }
        free(tab);
        j++;
    }

    shuffle(&sud);

    if (solver(&sud) == 0)
        printf("Sudoku insoluble\n");

    removes(&sud, 81);

    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            printf("%i ", sud.grid[j][i]);
        }
        printf("\n");
    }

    innitGraphics(&sud);
    int quit = 1;
    while (quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = 0;
        }
    }

    quitGraphics(&sud);

    return 0;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    hInst = hInst;
    hInstPrev = hInstPrev;
    cmdshow = cmdshow;

    int ac = 1;
    char **av = NULL;

    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);
    av = realloc(av, sizeof(char *) * (ac));
    av[0] = exePath;
    char *token = strtok(cmdline, " ");

    while (token != NULL)
    {
        av = realloc(av, sizeof(char *) * (ac + 1));
        av[ac] = token;
        ac++;
        token = strtok(NULL, " ");
    }

    int result = main(ac, av);

    free(av);
    fclose(stdout);
    FreeConsole();

    return result;
}