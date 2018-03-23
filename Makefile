all:
	gcc -o main src/main.c -I./include src/utils.c src/CG.c -lm -Wall `sdl2-config --cflags --libs`

run:
	./main 10
	./main 50
	./main 100
	./main 500
	./main 1000
	./main 1500
	./main 2000
	./main 2500
	./main 2750
	./main 3000

show:
	./main 10 1
	./main 50 1
	./main 100 1
	./main 500 1
	./main 1000 1
	./main 1500 1
	./main 2000 1
	./main 2500 1
	./main 2750 1
	./main 3000 1

clean:
	-rm main -f
	-rm data.csv -f
