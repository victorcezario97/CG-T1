all:
	gcc -o pontoMedio src/pontoMedio.c -I./include src/utils.c -lm `sdl2-config --cflags --libs`
run:
	./pontoMedio 5000 5000 10
	./pontoMedio 5000 5000 100
	./pontoMedio 5000 5000 500
	./pontoMedio 5000 5000 1000
	./pontoMedio 5000 5000 2500

clean:
	rm pontoMedio
