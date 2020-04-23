#include "global.h"

struct entry palavras_chave[] = {
    "div",  DIV,
    "mod",  MOD,
    "if",   IF,
    "then", THEN,
    "while",WHILE,
    "do",   DO,      
    "begin",BEGIN,   
    "end",  END,     
    "0", 0
};

void init(){
    struct entry *p;
    for (p = palavras_chave; p -> token; p++)
    {
        insert(p->lexptr,p->token);
    }
}

