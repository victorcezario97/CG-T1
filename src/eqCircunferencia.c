#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <utils.h>

int main(int argc, char** argv)
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    /*General purpose variables*/
    int sizeX = 400, sizeY = 400, r = 150, x = 0;
    double y;
    /*Time Mark Variables*/
    clock_t tStart, tEnd;

    /*Initializing everything*/
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("ComputerGraphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              sizeX, sizeY, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    /*Change the drawing color for green*/
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    tStart = clock();
    while(x <= y)
    {
        y = sqrt(pow(r,2) - pow(x,2));
        draw8Points(x, y, renderer, sizeX, sizeY);
        x ++;
    }
    tEnd = clock();
    printf("Raio: %d --> %ldms\n", r, tEnd - tStart);

    /*Reload the render*/
    SDL_RenderPresent(renderer);

    /*Delay for see the window*/
    SDL_Delay(5000);

    /*Ending the window and the renderer*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
