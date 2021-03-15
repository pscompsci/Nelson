CFLAGS = -Wall -Wextra -std=c11 -pedantic

SRC = $(wildcard ./src/*.c)

.PHONY: main clean

main: ./src/main.c
	$(CC) $(CFLAGS) $(SRC) -o lex

clean:
	rm -vf ./lex