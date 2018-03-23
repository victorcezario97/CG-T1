
#include <SDL2/SDL.h>
#include <utils.h>
#include <CG.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int sizeX, sizeY, r, flag = 0;
	clock_t t = 0;

	//Checks the parameters
	if(argc == 3){
		//If there's a third parameter, sets the flag to show the drawings
		flag = 1;
		argc--;
	}
	if(argc != 2){
		printf("Usage: ./pontoMedio Radius\n");
		return -1;
	}
	//Gets the radius from the parameter
	getArgs(argv, &r);

	//Sets the window size to fit the circumference
	sizeX = sizeY = r*2+10;

	SDL_CreateWindowAndRenderer(sizeX, sizeY, 0, &window, &renderer);

	SDL_RenderClear(renderer);
	//Runs the "pontoMedio" algorithm 150 times
	for(int i =0; i<150; i++){
		t += pontoMedio(r, sizeX, sizeY, renderer);
	}

	//Prints the average time for the radius
	printf("Ponto Medio --> Raio: %d --> %ldms\n", r, t/150);

	//Shows the circumference
	if(flag == 1){
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
	}

	SDL_RenderClear(renderer);
	t = 0;
	//Runs the "coordenadaPolar" algorithm 150 times
	for(int i =0; i<150; i++)
		t += coordenadaPolar(r, sizeX, sizeY, renderer);

	//Prints the average time for the radius
	printf("Coordenada Polar --> Raio: %d --> %ldms\n", r, t/150);

	//Shows the circumference
	if(flag == 1){
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
	}

	t = 0;
	SDL_RenderClear(renderer);
	//Runs the "eqCircunferencia" algorithm 150 times
	for(int i =0; i<150; i++)
		t += eqCircunferencia(r, sizeX, sizeY, renderer);

	//Prints the average time for the radius
	printf("Equacao da Circunferencia --> Raio: %d --> %ldms\n", r, t/150);
	
	//Shows the circumference
	if(flag == 1){
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
	}

	return 0;
}