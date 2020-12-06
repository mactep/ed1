#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cont.h"

struct cont_cel {
    Cont* cont;
    ContCel* prox;
    ContCel* ant;
};

struct cont {
    Editor* editor;
    char* nome_arquivo;
    int removido;
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
    cont->nome_arquivo = strdup(nome_arquivo);
    cont->removido = 0;

    return cont;
}

ContCel* insere_cont_lista(ContCel* lista, Cont* cont) {
    if (lista->cont == NULL) {
        lista->cont = cont;

        return lista;
    } else {
        ContCel* cel = (ContCel*) malloc(sizeof(ContCel));
        cel->cont = cont;
        cel->ant = NULL;
        cel->prox = lista;
        lista->ant = cel;

        return cel;
    }
}

void destroi_cont(Cont* cont) {
    destroi_editor(cont->editor);
    free(cont);
}

Cont* get_cont(ContCel* cel) {
    return cel->cont;
}

char* get_cont_arquivo(Cont* cont) {
    return cont->nome_arquivo;
}

Editor* get_cont_editor(Cont* cont) {
    return cont->editor;
}

ContCel* get_prox_cont(ContCel* cel) {
    return cel->prox;
}
