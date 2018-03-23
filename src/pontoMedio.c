#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <utils.h>

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	char a;
	int r, x, y, h, xx, yy, sizeX, sizeY;
	clock_t tStart, tEnd;

	if(argc != 4){
		printf("Usage: ./pontoMedio SIZEX SIZEY Radius\n");
		return -1;
	}
	getArgs(argv, &sizeX, &sizeY, &r);

	SDL_CreateWindowAndRenderer(sizeX, sizeY, 0, &window, &renderer);

	//drawCoord(sizeX, sizeY, renderer);

	x = 0; y = r; h = 1-r;

	tStart = clock();
	while(y>x){
		if(h < 0){
			h += 2*(x) + 3;
			x++;
		}else{
			h += 2*((x)-(y)) + 5;
			x++; y--;
		}
		draw8Points(x, y, renderer, sizeX, sizeY);
	}
	tEnd = clock();

	printf("Raio: %d --> %ldms\n", r, tEnd - tStart);

//	SDL_RenderPresent(renderer);
	return 0;
}
