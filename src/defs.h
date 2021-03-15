#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {
    PLUS,
    DASH,
    STAR,
    SLASH,
    INTLIT
};

struct token {
    int type;
    int operand;
};