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
    case IF:
        emitir(IF, tokenval);
        reconhecer(IF);
    case THEN:
        emitir(IF, tokenval);
        reconhecer(IF);
        break;
    case WHILE:
        emitir(IF, tokenval);
        reconhecer(IF);   
    case DO:
        emitir(IF, tokenval);
        reconhecer(IF);
        break;
    case BEGIN:
        emitir(IF, tokenval);
        reconhecer(IF);
    case END:
        emitir(IF, tokenval);
        reconhecer(IF);
        break;
    default:
        erro("erro de sintaxe");
    }
}

void cmd(){
    switch (lookahead)
    {
    case ID:
        expr();
        break;
    case IF:
        expr();
    case THEN:
        cmd();
        break;
    case WHILE:
        expr();    
    case DO:
        cmd();
        break;
    case BEGIN:
        opt_cmd();
    case END:
        break;
    default:
        break;
    }
}

void opt_cmd(){
   if(lookahead != NULL){
       cmd_list();
   }
}

void cmd_list(){
    cmd();
}

void reconhecer(t)int t;{
    if (lookahead == t)
        lookahead = lexan();
    else erro("erro de sintaxe2");
}