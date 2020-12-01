#include <stdlib.h>

#include "pagina.h"
#include "cont.h"
#include "link.h"

struct pag_cel {
    Pagina* pagina;
    PagCel* prox;
    PagCel* ant;
};

struct pagina {
    char* nome;
    char* arquivo;
    ContCel* contribs;
    LinkCel* links;
};

PagCel* cria_lista_pagina() {
    PagCel* lista = (PagCel*) malloc(sizeof(PagCel));
    lista->pagina = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Pagina* cria_pagina(char* nome, char* arquivo) {
    Pagina* pagina = (Pagina*) malloc(sizeof(Pagina));
    pagina->nome = nome;
    pagina->arquivo = arquivo;
    pagina->contribs = NULL;
    pagina->links = NULL;

    return pagina;
}

PagCel* insere_pagina_lista(PagCel* lista, Pagina* pagina) {
    if (lista->pagina == NULL) {
        lista->pagina = pagina;

        return lista;
    } else {
        PagCel* cel = (PagCel*) malloc(sizeof(PagCel));
        cel->pagina = pagina;
        cel->prox = NULL;
        cel->ant = lista;
        lista->prox = cel;

        return cel;
    }
}

void retira_pagina_lista(PagCel* lista, char* nome) {
    for (PagCel* cel = lista; cel != NULL; cel = cel->prox) {
        if (cel->pagina->nome == nome) {
            if (cel->pagina == NULL) {
                return;
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
        }
    }
}

void destroi_pagina(Pagina* pagina) {
    for (ContCel* cel = pagina->contribs; cel != NULL; cel = cel->prox) {
        destroi_cont(cel->cont);
    }

    for (LinkCel* cel = pagina->links; cel != NULL; cel = cel->prox) {
    }
    free(pagina);
}
