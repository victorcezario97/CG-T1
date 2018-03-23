all:
	gcc -o main src/main.c -I./include src/utils.c src/CG.c -lm -Wall `sdl2-config --cflags --libs`

run:
	./main 10
	./main 100
	./main 500
	./main 1000
	./main 2500

show:
	./main 10 1
	./main 100 1
	./main 500 1
	./main 1000 1
	./main 2500 1

clean:
	rm main
