#ifndef abb_h
#define abb_h

#include <stdio.h>

typedef struct arv Arvore;

Arvore* cria_node_arvore();

void imprime_arvore(Arvore* arv);

void destroi_arvore(Arvore* arv);

float calcula_arvore(Arvore* arv);

Arvore* parse_entrada(FILE* entrada, Arvore* arv);

#endif
