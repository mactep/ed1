#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "listaMat.h"

Cel* criaLista() {
    Cel* lista = (Cel*) malloc(sizeof(Cel));
    lista->mat = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Cel* insereElemento(Cel* lista, Matriz* mat) {
    if (lista->mat == NULL) {
        lista->mat = mat;
        return lista;
    } else {
        Cel* cel = (Cel*) malloc(sizeof(Cel));
        cel->mat = mat;
        cel->prox = lista;
        cel->ant = NULL;
        lista->ant = cel;
        return cel;
    }
}

Cel* retiraElemento(Cel* lista, int pos) {
    Cel* cel = lista;

    for (int i = 0; i < pos; i++) {
        cel = cel->prox;
    }

    if (cel->mat == NULL) {
        return lista;
    }

    // if (lista == cel) {
    if (cel->ant == NULL) {
        lista = cel->prox;
        lista->ant = NULL;
    } else if (cel->prox == NULL) {
        cel->ant->prox = NULL;
    } else {
        cel->ant->prox = cel->prox;
        cel->prox->ant = cel->ant;
    }

    free(cel);

    return lista;
}

void imprimeLista(Cel* lista) {
    for (Cel* cel = lista; cel != NULL; cel = cel->prox) {
        imprimeMatriz(cel->mat);
        printf("\n");
    }
}

void destroiLista(Cel* lista) {
    Cel* cel = lista;
    Cel* aux;

    while (cel != NULL) {
        aux = cel->prox;
        free(cel);
        cel = aux;
    }
}
