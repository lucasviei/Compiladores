#include "global.h"

int lookahead;

void parse(){
    lookahead = lexan();
    while (lookahead != DONE)
    {
        expr();
        reconhecer(';');
    }
    
}

void expr(){
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

void termo(){
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

void fator(){
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
        if(lookahead != ';'){
            printf("erro %c\n",lookahead);
            //lookahead++;
            clinha++;
            //lookahead = lexan();
        }else{
            //erro("erro de sintaxe");
        }
        
    }
}

void reconhecer(t)int t;{
    if (lookahead == t)
        lookahead = lexan();
    else if(lookahead != ';'){
        printf("erro2 %c\n",lookahead);
        lookahead++;
        clinha++;
        lookahead = lexan();
    }
    else if(lookahead == ';'){
        erro("erro de sintaxe2");
    }
}