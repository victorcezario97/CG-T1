all:
	gcc -o main src/main.c -I./include src/utils.c src/CG.c -lm -Wall `sdl2-config --cflags --libs`
	gcc -o coordenadaPolar src/coordenadaPolar.c -I./include src/utils.c -lm `sdl2-config --cflags --libs`
	gcc -o eqCircunferencia src/eqCircunferencia.c -I./include src/utils.c -lm `sdl2-config --cflags --libs`

run:
	./main 10
	./main 100
	./main 500
	./main 1000
	./main 2500

clean:
	rm pontoMedio
	rm eqCircunferencia
	rm coordenadaPolar
