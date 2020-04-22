#include "global.h"

void emitir(t, tval)int t,tval;{
    switch (t)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        printf("Empilha: %c\tOpera e Desempilha!.\n", t);
        break;
    case DIV:
        printf("Empilha: DIV\tOpera e Desempilha!.\n");
        break;
    case MOD:
        printf("Empilha: MOD\tOpera e Desempilha!\n");
        break;
    case NUM:
        printf("Empilha: %d\n", tval);
        break;
    case ID:
        printf("Empilha: %s\n", tab_simb[tval].lexptr);
        break;
    default:
        printf("token %d, tokeval %d\n", t, tval);
    }
}