#include "global.h"
#define STRMAX 999
#define SYMMAX 100

char lexemas[STRMAX];
int lastchar = -1;
struct entry tab_simb[SYMMAX];
int lastentry = 0;

int buscar(s)char s[];{
    int p;
    for (p = lastentry; p > 0; p = p-1)
        if (strcmp(tab_simb[p].lexptr, s) == 0)
            return p;
    return 0;
    
}
int insert(s, tok)char s[];int tok;{
    int len;
    len = strlen(s);
    if(lastentry + 1 >= SYMMAX)
        erro("tabela de símbolos está cheia");
    if(lastentry + len + 1 >= STRMAX)
        erro("array de lexemas está cheio");
    lastentry = lastentry + 1;
    tab_simb[lastentry].token = tok;
    tab_simb[lastentry].lexptr = &lexemas[lastchar + 1];
    strcpy(tab_simb[lastentry].lexptr, s);
    return lastentry;
}
