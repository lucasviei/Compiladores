#include "global.h"

void emitir(t, tval)int t,tval;{
    switch (t)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        printf("%c\n", t);
        break;
    case DIV:
        printf("DIV\n");
        break;
    case MOD:
        printf("MOD\n");
        break;
    case NUM:
        printf("%d\n", tval);
        break;
    case ID:
        printf("%s\n", tab_simb[tval].lexptr);
        break;
    case IF:
        printf("%s\n", tab_simb[tval].lexptr);
        break;
    case WHILE:
        printf("%s\n", tab_simb[tval].lexptr);
        break;
    case DO:
        printf("%s\n", tab_simb[tval].lexptr);
        break;
    case BEGIN:
        printf("%s\n", tab_simb[tval].lexptr);
        break;
    case END:
        printf("%s\n", tab_simb[tval].lexptr);
        break;
    default:
        printf("token %d, tokeval %d\n", t, tval);
    }
}