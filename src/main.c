
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

	if(argc == 3){
		flag = 1;
		argc--;
	}
	if(argc != 2){
		printf("Usage: ./pontoMedio Radius\n");
		return -1;
	}
	getArgs(argv, &r);

	sizeX = sizeY = r*2+10;

	SDL_CreateWindowAndRenderer(sizeX, sizeY, 0, &window, &renderer);

	SDL_RenderClear(renderer);
	for(int i =0; i<150; i++){
		t += pontoMedio(r, sizeX, sizeY, renderer);
	}

	printf("Ponto Medio --> Raio: %d --> %ldms\n", r, t/150);

	if(flag == 1){
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
	}

	SDL_RenderClear(renderer);
	t = 0;
	for(int i =0; i<150; i++)
		t += coordenadaPolar(r, sizeX, sizeY, renderer);

	printf("Coordenada Polar --> Raio: %d --> %ldms\n", r, t/150);

	if(flag == 1){
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
	}

	t = 0;
	SDL_RenderClear(renderer);
	for(int i =0; i<150; i++)
		t += eqCircunferencia(r, sizeX, sizeY, renderer);

	printf("Equacao da Circunferencia --> Raio: %d --> %ldms\n", r, t/150);
	
	if(flag == 1){
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
	}

	return 0;
}