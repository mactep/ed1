#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "edit.h"

struct edit_cel {
    Editor* editor;
    EditCel* prox;
    EditCel* ant;
};

struct editor {
    char* nome;
};

EditCel* cria_lista_editor() {
    EditCel* lista = (EditCel*) malloc(sizeof(EditCel));
    lista->editor = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Editor* cria_editor(char* nome) {
    Editor* editor = (Editor*) malloc(sizeof(Editor));
    editor->nome = strdup(nome);

    return editor;
}

EditCel* insere_editor_lista(EditCel* lista, Editor* editor) {
    if (lista->editor == NULL) {
        lista->editor = editor;
        return lista;
    } else {
        EditCel* cel = (EditCel*) malloc(sizeof(EditCel));
        cel->editor = editor;
        cel->ant = NULL;
        cel->prox = lista;
        lista->ant = cel;

        return cel;
    }
}

void destroi_editor(Editor* editor) {
    free(editor);
}

EditCel* get_prox_editor(EditCel* cel) {
    return cel->prox;
}

Editor* get_editor(EditCel* cel) {
    return cel->editor;
}

void imprime_editor(Editor* editor) {
    printf("%s\n", editor->nome);
}

char* get_editor_nome(Editor* editor) {
    return editor->nome;
}
