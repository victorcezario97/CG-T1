#include <time.h>
#include <SDL2/SDL.h>
#include <utils.h>

clock_t pontoMedio(int r, int sizeX, int sizeY, SDL_Renderer *renderer){
	int x = 0, y = r, d = 1-r, deltaE, deltaSE;
	clock_t tStart, tEnd;

	deltaE = 3;	deltaSE = -2*r + 5;

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

	return tEnd - tStart;
}

clock_t coordenadaPolar(int r, int sizeX, int sizeY, SDL_Renderer *renderer){
	int x, y, angle = 90;
	clock_t tStart, tEnd;

	tStart = clock();
    while(angle >= 45)
    {
        x = r*cos(angle);
        y = r*sin(angle);
        draw8Points(x, y, renderer, sizeX, sizeY);
        angle--;
    }
    tEnd = clock();

    return tEnd - tStart;
}

clock_t eqCircunferencia(int r, int sizeX, int sizeY, SDL_Renderer *renderer){
	int x = 0;
	double y;
	clock_t tStart, tEnd;

	tStart = clock();
    while(x <= y)
    {
        y = sqrt(pow(r,2) - pow(x,2));
        draw8Points(x, y, renderer, sizeX, sizeY);
        x ++;
    }
    tEnd = clock();

    return tEnd - tStart;
}