CFLAGS = -Wall -Wextra -std=c11 -pedantic

.PHONY: main clean

main: ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -o lex

clean:
	rm -vf ./lex