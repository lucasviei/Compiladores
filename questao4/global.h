#include <stdio.h>
#include <ctype.h>

#define BSIZE 128
#define NONE -1
#define EOS     '\0'

#define NUM     256
#define DIV     257
#define MOD     258
#define ID      259
#define DONE    260

#define IF      261
#define THEN    262
#define WHILE   263
#define DO      264
#define BEGIN   265
#define END     266

int tokenval;
int clinha;

struct entry
{
    char *lexptr;
    int token;
};

struct entry tab_simb[100];