#include "aluno.h"

typedef struct arv Arvore;

Arvore* cria_arvore_vazia();

Arvore* cria_arvore(Aluno* al, Arvore* esq, Arvore* dir);

void destroi_arvore(Arvore* arv);

int arvore_vazia(Arvore* arv);

int pertence_arvore(Arvore* arv, Aluno* al);

void imprime_arvore(Arvore* arv);

int altura(Arvore* arv);

int folhas(Arvore* arv);

int ocorrencias(Arvore* arv, Aluno* al);
