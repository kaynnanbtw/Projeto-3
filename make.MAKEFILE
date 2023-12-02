CC = gcc
CFLAGS = -Wall -O2

all: quebra-senha

quebra-senha: quebra-senha.c
	$(CC) $(CFLAGS) quebra-senha.c -o quebra-senha

clean:
	rm -f quebra-senha
