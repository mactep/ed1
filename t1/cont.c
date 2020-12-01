#include <stdlib.h>

#include "cont.h"

struct cont_cel {
    Cont* cont;
    ContCel* prox;
    ContCel* ant;
};

struct cont {
    Editor* editor;
    char* nome_arquivo;
};

ContCel* cria_lista_cont() {
    ContCel* lista = (ContCel*) malloc(sizeof(ContCel));
    lista->cont = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Cont* cria_cont(Editor* editor, char* nome_arquivo) {
    Cont* cont = (Cont*) malloc(sizeof(Cont));
    cont->editor = editor;
    cont->nome_arquivo = nome_arquivo;

    return cont;
}

ContCel* insere_cont_lista(ContCel* lista, Cont* cont) {
    if (lista->cont == NULL) {
        lista->cont = cont;

        return lista;
    } else {
        ContCel* cel = (ContCel*) malloc(sizeof(ContCel));
        cel->cont = cont;
        cel->prox = NULL;
        cel->ant = lista;
        lista->prox = cel;

        return cel;
    }
}

void destroi_cont(Cont* cont) {
    destroi_editor(cont->editor);
    free(cont);
}
