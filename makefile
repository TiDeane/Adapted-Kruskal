CC=g++
CFLAGS=-std=c++11 -O3 -Wall

FILE_NAME=AdaptedKruskal

all:
	$(CC) $(CFLAGS) $(FILE_NAME).cpp -lm -o Kruskal

denseGraphGenerator:
	gcc -O3 -Wall testing/dgg.c -o dgg

realisticGraphGenerator:
	g++ -std=c++11 -O3 testing/delaunay2graph.cpp -lm -o d2g

clean:
	rm -rf Kruskal dgg d2g *.out