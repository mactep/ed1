#include <stdio.h>
#include <stdlib.h>

#include "pilha_dupla.h"

int main()
{
    PilhaDupla* pilha = inicPilha();
    int a = 10;
    int b = 5;
    int c = 3;
    int d = 21;

    push(pilha, 1, &a);
    push(pilha, 1, &b);
    push(pilha, 1, &c);
    push(pilha, 1, &d);

    push(pilha, 2, &d);
    push(pilha, 2, &c);
    push(pilha, 2, &b);
    push(pilha, 2, &a);

    printf("pilha 1\n");
    imprime(pilha, 1);

    printf("pilha 2\n");
    imprime(pilha, 2);

    printf("pop\n");
    printf("%d\n", *pop(pilha, 1));
    printf("%d\n", *pop(pilha, 2));

    printf("destroi");
    destroi(pilha);
}
