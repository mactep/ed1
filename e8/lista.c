#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "lista.h"

Lista* criaLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereElemento(Lista* lista, Aluno* aluno) {
    Cel* cel = (Cel*) malloc(sizeof(Cel));
    cel->aluno = aluno;
    cel->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = cel;
        lista->ult = cel;
    } else {
        lista->ult->prox = cel;
        lista->ult = cel;
    }
}

Cel* retiraElemento(Lista* lista, int pos) {
    Cel* cel = lista->prim;
    Cel* prev = NULL;

    // for (Cel* cel = lista->prim; cel != NULL; cel = cel->prox) {
    for (int i = 0; i < pos; i++) {
        prev = cel;
        cel = cel->prox;
    }

    if (cel == NULL) {
        return NULL;
    }

    if (cel == lista->prim && cel == lista->ult) {
        lista->prim = NULL;
        lista->ult = NULL;
    } else if (cel == lista->prim) {
        lista->prim = cel->prox;
    } else if (cel == lista->ult) {
        lista->ult = prev;
    } else {
        prev->prox = cel->prox;
    }

    return cel;
}

void imprimeLista(Lista* lista) {
    for (Cel* cel = lista->prim; cel != NULL; cel = cel->prox) {
        imprimeAluno(cel->aluno);
        printf("\n");
    }
}

void destroiLista(Lista* lista) {
    Cel* cel = lista->prim;
    Cel* aux;

    while (cel != NULL) {
        aux = cel->prox;
        free(cel);
        cel = aux;
    }

    free(lista);
}
