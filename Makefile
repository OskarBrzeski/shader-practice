LIBS = -I./raylib/ -L./raylib/ -l:libraylib.a -lm

run: build
	./main

build: src/main.c voronoi.o
	gcc -o main src/main.c voronoi.o ${LIBS}

voronoi.o: src/voronoi/voronoi.c src/voronoi/voronoi.h
	gcc -c src/voronoi/voronoi.c src/voronoi/voronoi.h ${LIBS}

clean:
	rm -f main
