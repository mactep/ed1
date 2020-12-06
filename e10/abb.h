#ifndef abb_h
#define abb_h

#include "aluno.h"

typedef struct arv Arvore;

Arvore* cria_arvore();

void imprime_arvore(Arvore* arv);

Arvore* busca_arvore(Arvore* arv, int chave);

Arvore* insere_arvore(Arvore* arv, Aluno* al);

Arvore* retira_arvore(Arvore* arv, int v);

void destroi_arvore(Arvore* arv);

Aluno* get_aluno(Arvore* arv);

#endif
