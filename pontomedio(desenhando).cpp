#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL2/SDL.h>

/* Function capable of draw one 'X' */
void drawCoord(int sizeX, int sizeY, SDL_Renderer *renderer){
	for(int i=0; i<sizeX; i++) SDL_RenderDrawPoint(renderer, i, sizeY/2);
	for(int i=0; i<sizeY; i++) SDL_RenderDrawPoint(renderer, sizeX/2, i);
	SDL_RenderPresent(renderer);
	return;
}

void convertToCenter(int x, int y, int *newX, int *newY, int sizeX, int sizeY){

	*newX = x + sizeX/2;
	*newY = sizeY - (y+(sizeY/2));
}

void draw8Points(int x, int y, SDL_Renderer *renderer, int sizeX, int sizeY){
	int newX, newY;

	convertToCenter(x, y, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(-x, y, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(x, -y, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(-x, -y, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(y, x, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(-y, x, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(y, -x, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);

	convertToCenter(-y, -x, &newX, &newY, sizeX, sizeY);
	SDL_RenderDrawPoint(renderer, newX, newY);
}

int main(int argc, char** argv)
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    /*General purpose variables*/
    int sizeX=1000, sizeY=1000, r = 500, x = 0, y = r, h = 1-r;
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
    while(y>x)
    {
        if(h < 0)
        {
            h += 2*(x) + 3;
            x++;
        }
        else
        {
            h += 2*((x)-(y)) + 5;
            x++;
            y--;
        }
        draw8Points(x, y, renderer, sizeX, sizeY);
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
