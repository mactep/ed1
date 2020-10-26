#include <stdlib.h>

#include "matriz.h"
#include "listaMat.h"

struct cel {
    Matriz* mat;
    Cel* prox;
};

struct lista {
    Cel* prim;
    Cel* ult;
};

Lista* criaLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereLista(Lista* lista, Matriz* mat) {
    Cel* cel = (Cel*) malloc(sizeof(Cel));
    cel->mat = mat;
    cel->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = cel;
        lista->ult = cel;
    } else {
        lista->ult->prox = cel;
        lista->ult = cel;
    }
}

Cel* retiraLista(Lista* lista, int pos) {
    int count = 0;
    Cel* prev = lista->prim;

    for (Cel* cel = lista->prim; cel != NULL; cel = cel->prox) {
        if (count == pos) {
            prev->prox = cel->prox;

            return cel->prox;
        }

        prev = cel;
        count++;
    }

    return NULL;
}

void imprimeLista(Lista* lista) {
    for (Cel* cel = lista->prim; cel != NULL; cel = cel->prox) {
        imprimeMatriz(cel->mat);
    }
}

void destroiLista(Lista* lista) {
    free(lista->prim);
    free(lista->ult);
    free(lista);
}
