all: pratica.o lista.o
	@gcc pratica.o lista.o -o programa -g
pratica.o: pratica.c
		@gcc pratica.c -c -g
lista.o: lista.c
	@gcc lista.c -c -g
run:
	@./programa
