all:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc main.c fila_encadeada.o pilha_encadeada.o

clean:
	rm *.o
	rm exercicio1
	rm exercicio2
	rm exercicio3
	rm exercicio4

exercicio1:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc exercicio1.c fila_encadeada.o pilha_encadeada.o -o exercicio1

exercicio2:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc exercicio2.c fila_encadeada.o pilha_encadeada.o -o exercicio2

exercicio3:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc exercicio3.c fila_encadeada.o pilha_encadeada.o -o exercicio3

exercicio4:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc -c pilha_encadeada.c -o pilha_encadeada.o
	gcc exercicio4.c fila_encadeada.o pilha_encadeada.o -o exercicio4

benchmark_encadeada:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc benchmark_queue.c fila_encadeada.o -o benchmark_encadeada
