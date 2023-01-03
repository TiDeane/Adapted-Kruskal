# type of compiler
CC=g++
CFLAGS=-std=c++11 -O3 -Wall

FILE_NAME=project
FICHEIRO_TESTE=test.txt

NUMERO_VERTICES=8


all:
# clear the things in the terminal
	clear
# compile
	$(CC) $(CFLAGS) $(FILE_NAME).cpp -lm
#  execute the file -> input in the terminal the file test.in -> output the result int the file result.out
	./a.out <$(FICHEIRO_TESTE) >result.out

# nao funciona
geraGrafoDenso:
	clear
	gcc -O3 -Wall -o dgg dgg.c
# <número de vértices>: substituir pelo número de vértices do grafo
# <nome do ficheiro de teste>: substituir pelo nome do ficheiro de teste a gerar
# Exemplo: ./dgg 10 > d10.txt
	./dgg $(NUMERO_VERTICES) > $(FICHEIRO_TESTE)

geraGrafoRealista:
	clear
	g++ -std=c++11 -O3 -o d2g delaunay2graph.cpp -lm
# <número de vértices>: substituir pelo número de vértices do grafo |V|
# <coordenada máxima>: substituir por M, coordenada máxima (M,M), onde M >= |V|
# <probabilidade>: substituir pela probabilidade para criar o novo grafo
# <semente>: substituir pela semente aleatória (opcional)
# Exemplo: ./d2g 10 100 0.8 15 > v10.txt
	./d2g $(NUMERO_VERTICES) <coordenada máxima> 1 <semente> > $(FICHEIRO_TESTE)

step:
	clear
	$(CC) -g -Wall -std=c17 -c $(FILE_NAME).cpp -o $(FILE_NAME).o
	$(CC) -g -Wall -std=c17 $(FILE_NAME).o -o $(FILE_NAME)
	gdb $(FILE_NAME)
# a partir daqui é precico por manualmente
# breakpoint na função resultado (se eu quiser ver todos os breakpoints é só fazer -> info b)
#->	b resultado
# run
#->	r
# analisar cada linha
#->	s
# avançar muitas linhas de codigo
#->	n
# analisar o valor da variavel
#->	p <variavel>

clean:
	rm -rf $(FILE_NAME) *.o