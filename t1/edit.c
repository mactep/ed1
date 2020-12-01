#include <stdlib.h>
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
    editor->nome = nome;

    return editor;
}

EditCel* insere_editor_lista(EditCel* lista, Editor* editor) {
    if (lista->editor == NULL) {
        lista->editor = editor;

        return lista;
    } else {
        EditCel* cel = (EditCel*) malloc(sizeof(EditCel));
        cel->editor = editor;
        cel->prox = NULL;
        cel->ant = lista;
        lista->prox = cel;

        return cel;
    }
}

void destroi_editor(Editor* editor) {
    free(editor);
}
