#include <stdlib.h>

#include "arvore.h"
#include "aluno.h"

struct arv {
    Aluno* al;
    Arvore* esq;
    Arvore* dir;
};

Arvore* cria_arvore_vazia() {
    return NULL;
}

Arvore* cria_arvore(Aluno* al, Arvore* esq, Arvore* dir) {
    Arvore* p = (Arvore*) malloc(sizeof(Arvore));

    p->al = al;
    p->esq = esq;
    p->dir = dir;

    return p;
}

int arvore_vazia(Arvore* arv) {
    return arv == NULL;
}

void destroi_arvore(Arvore* arv) {
    if (!arvore_vazia(arv)) {
        destroi_arvore(arv->esq);
        destroi_arvore(arv->dir);
        free(arv);
    }
}

int pertence_arvore(Arvore* arv, Aluno* al) {
    if (arvore_vazia(arv)) {
        return 0;
    } else {
        return arv->al->matricula == al->matricula ||
            pertence_arvore(arv->esq, al) ||
            pertence_arvore(arv->dir, al);
    }
}

void imprime_arvore(Arvore* arv) {
    if (!arvore_vazia(arv)) {
        imprimeAluno(arv->al);
        imprime_arvore(arv->esq);
        imprime_arvore(arv->dir);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Arvore* arv) {
    if (arvore_vazia(arv)) {
        return -1;
    } else {
        return 1 + max(altura(arv->esq), altura(arv->dir));
    }
}

int folhas(Arvore* arv) {
    if (arvore_vazia(arv->esq) && arvore_vazia(arv->dir)) {
        return 1;
    } else if (!arvore_vazia(arv->esq) && arvore_vazia(arv->dir)) {
        return folhas(arv->esq);
    } else if (arvore_vazia(arv->esq) && !arvore_vazia(arv->dir)) {
        return folhas(arv->dir);
    }

    return folhas(arv->esq) + folhas(arv->dir);
}

int ocorrencias(Arvore* arv, Aluno* al) {
    if (arvore_vazia(arv)) {
        return 0;
    }

    if (arv->al->matricula == al->matricula) {
        return (1 + ocorrencias(arv->esq, al) + ocorrencias(arv->dir, al));
    }
    return (ocorrencias(arv->esq, al) + ocorrencias(arv->dir, al));
}
