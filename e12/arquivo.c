#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"

struct cel {
    void* cont;
    Cel* prox;
    Cel* ant;
};

void set_cont(Cel* cel, void* cont) {
    cel->cont = cont;
}

void* get_cont(Cel* cel) {
    return cel->cont;
}

void set_prox(Cel* cel, Cel* prox) {
    cel->prox = prox;
}

Cel* get_prox(Cel* cel) {
    return cel->prox;
}

void set_ant(Cel* cel, Cel* ant) {
    cel->ant = ant;
}

Cel* get_ant(Cel* cel) {
    return cel->ant;
}

Cel* criaLista() {
    Cel* lista = (Cel*) malloc(sizeof(Cel));
    lista->cont = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Cel* insereElemento(Cel* lista, void* cont) {
    if (lista->cont == NULL) {
        lista->cont = cont;
        return lista;
    } else {
        Cel* cel = (Cel*) malloc(sizeof(Cel));
        cel->cont = cont;
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

    if (cel->cont == NULL) {
        return lista;
    }

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

int percorreLista(Cel* lista, int (*cb)(void*)) {
    for (Cel* cel = lista; cel != NULL; cel = cel->prox) {
        int r = cb(cel->cont);
        if (r == 0) {
            return r;
        }
    }
    return 1;
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
