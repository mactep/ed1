#include <stdlib.h>

#include "abb.h"
#include "aluno.h"

struct arv {
    Aluno* al;
    Arvore* esq;
    Arvore* dir;
};

Arvore* cria_arvore() {
    return NULL;
}

void imprime_arvore(Arvore* arv) {
    if (arv != NULL) {
        imprimeAluno(arv->al);
        imprime_arvore(arv->esq);
        imprime_arvore(arv->dir);
    }
}

Arvore* busca_arvore(Arvore* arv, int chave) {
    if (arv == NULL) {
        return NULL;
    } else if (chave < getMatricula(arv->al)) {
        return busca_arvore(arv->esq, chave);
    } else if (chave > getMatricula(arv->al)) {
        return busca_arvore(arv->dir, chave);
    } else {
        return arv;
    }
}

Arvore* insere_arvore(Arvore* arv, Aluno* al) {
    if (arv == NULL) {
        arv = (Arvore*) malloc(sizeof(Arvore));
        arv->al = al;

        arv->esq = NULL;
        arv->dir = NULL;
    } else if (getMatricula(al) < getMatricula(arv->al)) {
        arv->esq = insere_arvore(arv->esq, al);
    } else {
        arv->dir = insere_arvore(arv->dir, al);
    }

    return arv;
}

Arvore* retira_arvore(Arvore* arv, int v) {
    if (arv == NULL) {
        return NULL;
    } else if (getMatricula(arv->al) > v) {
        arv->esq = retira_arvore(arv->esq, v);
    } else if (getMatricula(arv->al) < v) {
        arv->dir = retira_arvore(arv->dir, v);
    } else {
        if (arv->esq == NULL && arv->dir == NULL) {
            free(arv);
            arv = NULL;
        } else if (arv->esq == NULL) {
            Arvore* t = arv;
            arv = arv->dir;
            free(t);
        } else if (arv->dir == NULL) {
            Arvore* t = arv;
            arv = arv->esq;
            free(t);
        } else {
            Arvore* f = arv->esq;
            while (f->dir != NULL) {
                f = f->dir;
            }

            Aluno* t = arv->al;
            arv->al = f->al;
            f->al = t;

            arv->esq = retira_arvore(arv->esq, v);
        }
    }

    return arv;
}

void destroi_arvore(Arvore* arv) {
    if (arv != NULL) {
        destroi_arvore(arv->esq);
        destroi_arvore(arv->dir);
        free(arv);
    }
}

Aluno* get_aluno(Arvore* arv) {
    return arv->al;
}
