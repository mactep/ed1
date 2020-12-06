#ifndef CONTRIB
#define CONTRIB

#include "edit.h"

typedef struct cont_cel ContCel;
typedef struct cont Cont;

ContCel* cria_lista_cont();

Cont* cria_cont(Editor* editor, char* nome_arquivo);

ContCel* insere_cont_lista(ContCel* lista, Cont* cont);

int retira_cont_lista(ContCel* lista, char* cont);

void destroi_cont(Cont* cont);

Cont* get_cont(ContCel* cel);

char* get_cont_arquivo(Cont* cont);

Editor* get_cont_editor(Cont* cont);

ContCel* get_prox_cont(ContCel* cel);

#endif /* ifndef CONTRIB */
