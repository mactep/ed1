typedef struct editor Editor;
typedef struct edit_cel EditCel;

EditCel* cria_lista_editor();

Editor* cria_editor(char* nome);

EditCel* insere_editor_lista(EditCel* lista, Editor* editor);

void destroi_editor(Editor* editor);
