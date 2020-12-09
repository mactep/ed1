#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "abb.h"

struct arv {
    char* val;
    Arvore* esq;
    Arvore* dir;
    Arvore* pai;
};

Arvore* cria_node_arvore() {
    Arvore* arv = (Arvore*) malloc(sizeof(Arvore));
    arv->val = NULL;
    arv->esq = NULL;
    arv->dir = NULL;
    arv->pai = NULL;

    return arv;
}

void imprime_arvore(Arvore* arv) {
    if (arv != NULL) {
        printf("%s\n", arv->val);
        imprime_arvore(arv->esq);
        imprime_arvore(arv->dir);
    }
}

Arvore* insere_arvore(Arvore* arv, char val) {
    return NULL;
}

void destroi_arvore(Arvore* arv) {
    if (arv != NULL) {
        destroi_arvore(arv->esq);
        destroi_arvore(arv->dir);
        free(arv);
    }
}

char* get_val(Arvore* arv) {
    return arv->val;
}

void set_val(Arvore* arv, char* val) {
    arv->val = val;
}

void set_esq(Arvore* arv, Arvore* esq) {
    arv->esq = esq;
}

void set_dir(Arvore* arv, Arvore* dir) {
    arv->dir = dir;
}

Arvore* get_dir(Arvore* arv) {
    return arv->dir;
}

Arvore* get_esq(Arvore* arv) {
    return arv->esq;
}

Arvore* get_pai(Arvore* arv) {
    return arv->pai;
}
/*
Arvore* busca_arvore(Arvore* arv, int chave) {
    if (arv == NULL) {
        return NULL;
    } else if (chave < get(arv->al)) {
        return busca_arvore(arv->esq, chave);
    } else if (chave > getMatricula(arv->al)) {
        return busca_arvore(arv->dir, chave);
    } else {
        return arv;
    }
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
*/

