#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <utils.h>

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	char a;
	int x, y, d, xx, yy, sizeX, sizeY, deltaE, deltaSE, r;
	clock_t tStart, tEnd;

	if(argc != 2){
		printf("Usage: ./pontoMedio Radius\n");
		return -1;
	}
	getArgs(argv, &r);

	sizeX = sizeY = r*2+10;

	SDL_CreateWindowAndRenderer(sizeX, sizeY, 0, &window, &renderer);

	x = 0; 
	y = r; 
	d = 1-r;
	deltaE = 3;
	deltaSE = -2*r + 5;

	draw8Points(x, y, renderer, sizeX, sizeY);

	tStart = clock();
	while(y > x){
		if(d < 0){
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}else{
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		draw8Points(x, y, renderer, sizeX, sizeY);
	}
	tEnd = clock();

	printf("Raio: %d --> %ldms\n", r, tEnd - tStart);

	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	
	return 0;
}
