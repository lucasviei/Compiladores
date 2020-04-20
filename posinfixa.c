#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lookahead;
void expr();
void termo();
void reconhecer();
void erro();

int main(){
    lookahead = getchar();
    expr();
    putchar('\n');
}
void expr(){
    termo();
    while (1)
    {
        if (lookahead == '+')
        {
            reconhecer('+');
            termo();
            putchar('+');
        }
        else if(lookahead == '-'){
            reconhecer('-');
            termo();
            putchar('-');
        }
        else{
            break;
        }
    }
    
}
void termo(){
    if (isdigit(lookahead)){
        putchar(lookahead);
        reconhecer(lookahead);
    }
    else{
        erro();
    }
}
void reconhecer(t)int(t);{
    if (lookahead == t)
    {
        lookahead = getchar();
    }
    else{
        erro();
    }
    
}
void erro(){
    printf("erro de sintaxe\n");
    exit(1);
}