all:
	gcc -o pontoMedio src/pontoMedio.c -I./include src/utils.c -lm `sdl2-config --cflags --libs`
	gcc -o coordenadaPolar src/coordenadaPolar.c -I./include src/utils.c -lm `sdl2-config --cflags --libs`
	gcc -o eqCircunferencia src/eqCircunferencia.c -I./include src/utils.c -lm `sdl2-config --cflags --libs`

run:
	./pontoMedio 10
	./pontoMedio 100
	./pontoMedio 500
	./pontoMedio 1000
	./pontoMedio 2500

clean:
	rm pontoMedio
	rm eqCircunferencia
	rm coordenadaPolar
