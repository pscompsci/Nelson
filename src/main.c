#include "defs.h"
#include "data.h"
#include "func.h"
#include <errno.h>

extern int Line;
extern int Putback;
extern FILE *Infile;

static void init()
{
    Line = 1;
    Putback = '\n';
}

static void usage(char *program)
{
    fprintf(stderr, "Usage: %s infile\n", program);
    exit(1);
}

char *tokstr[] = {"+", "-", "*", "/", "integer"};

static void lexprogram()
{
    struct token t;

    while(lex(&t)) {
        printf("Token: %s", tokstr[t.type]);
        if (t.type == INTLIT) {
            printf(", Operand: %d", t.operand);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        usage(argv[0]);
    }

    init();

    if ((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    lexprogram();
    fclose(Infile);

    exit(0);
}