#ifndef EDITOR
#define EDITOR

typedef struct editor Editor;
typedef struct edit_cel EditCel;

EditCel* cria_lista_editor();

Editor* cria_editor(char* nome);

EditCel* insere_editor_lista(EditCel* lista, Editor* editor);

void destroi_editor(Editor* editor);

EditCel* get_prox_editor(EditCel* cel);

Editor* get_editor(EditCel* cel);

void imprime_editor(Editor* editor);

char* get_editor_nome(Editor* editor);

#endif /* ifndef EDITOR */
