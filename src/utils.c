#include <SDL2/SDL.h>
#include <math.h>

//Function that draws the 2D cartesian axes
void drawCoord(int sizeX, int sizeY, SDL_Renderer *renderer){
	for(int i=0; i<sizeX; i++) SDL_RenderDrawPoint(renderer, i, sizeY/2);
	for(int i=0; i<sizeY; i++) SDL_RenderDrawPoint(renderer, sizeX/2, i);
	SDL_RenderPresent(renderer);

	return;
}

//Function that converts the coordinates to be in the center od the SDL Window
void convertToCenter(int x, int y, int *newX, int *newY, int sizeX, int sizeY){

	*newX = x + sizeX/2;
	*newY = sizeY - (y+(sizeY/2));
}

//Function that draws the 8 symmetrical points in the window
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

//Function that converts a string to an integer
int stringToInt(char *string){
	int size = 0, n = 0;
	char c = string[0];

	while(c != '\0') c = string[++size];

	for(int i=size-1; i>=0; i--)
		n += (string[i]-48) * (pow(10, (size-1)-i));

	return n;
}

//Function that gets the arguments(radius)
void getArgs(char *argv[], int *r){
	(*r) = stringToInt(argv[1]);
}