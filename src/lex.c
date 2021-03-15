#include "defs.h"
#include "data.h"
#include "func.h"

static int chrpos(char *s, int c)
{
    char *p;
    p = strchr(s, c);
    return p ? p - s : -1;
}

static int next()
{
    int c;
    
    if (Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if ('\n' == c) {
        Line++;
    }
    return c;
}

static void putback(int c)
{
    Putback = c;
}

static int skip()
{
    int c = next();
    while(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
        c = next();
    }
    return c;
}

static int lexint(int c)
{
    int k, val = 0;

    while((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    putback(c);
    return val;
}

int lex(struct token *t) 
{
    int c = skip();

    switch (c) {
    case EOF:
        return 0;
    case '+':
        t->type = PLUS;
        break;
    case '-':
        t->type = DASH;
        break;
    case '*':
        t->type = STAR;
        break;
    case '/':
        t->type = SLASH;
        break;
    default:
        if (isdigit(c)) {
            t->operand = lexint(c);
            t->type = INTLIT;
            break;
        }

        printf("unrecognised character %c on line %d\n", c, Line);
        exit(1);
    }

    return 1;
}
