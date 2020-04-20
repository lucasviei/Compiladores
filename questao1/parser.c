#include "global.h"
int lookahead;

parse(){
    lookahead = lexan();
    while (lookahead != DONE)
    {
        expr();
        reconhecer(';');
    }
    
}

expr(){
    int t;
    termo();
    while (1)
    {
        switch (lookahead)
        {
        case '+':
        case '-':
            t = lookahead;
            reconhecer(lookahead);
            termo();
            emitir(t , NONE);
            continue;
        default:
            return;
        }
    }
    
}

termo(){
    int t;
    fator();
    while (1)
    {
        switch (lookahead)
        {
        case '*':
        case '/':
        case DIV:
        case MOD:
            t = lookahead;
            reconhecer(lookahead);
            fator();
            emitir(t, NONE);
            continue;
        default:
            return;
        }
    }
    
}

fator(){
    switch (lookahead)
    {
    case '(':
        reconhecer('(');
        expr();
        reconhecer(')');
        break;
    case NUM:
        emitir(NUM, tokenval);
        reconhecer(NUM);
        break;
    case ID:
        emitir(ID, tokenval);
        reconhecer(ID);
        break;
    default:
        erro("erro de sintaxe");
    }
}

reconhecer(t)int t;{
    if (lookahead == t)
        lookahead = lexan();
    else erro("erro de sintaxe");
}