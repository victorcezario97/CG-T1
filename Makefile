all:
	gcc -o main src/main.c -I./include src/utils.c src/CG.c -lm -Wall `sdl2-config --cflags --libs`

install:
	sudo apt-get install libsdl2-dev

run:
	./main 1
	./main 5
	./main 10
	./main 25
	./main 50
	./main 75
	./main 100
	./main 150
	./main 200
	./main 250
	./main 300
	./main 350
	./main 400

show:
	./main 1 1
	./main 5 1
	./main 10 1
	./main 25 1
	./main 50 1
	./main 75 1
	./main 100 1
	./main 150 1
	./main 200 1
	./main 250 1
	./main 300 1
	./main 350 1
	./main 400 1

clean:
	-rm main -f
	-rm data.csv -f
