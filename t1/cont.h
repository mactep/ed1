#include "edit.h"

typedef struct cont_cel ContCel;
typedef struct cont Cont;

ContCel* cria_lista_cont();

Cont* cria_cont(Editor* editor, char* nome_arquivo);

ContCel* insere_cont_lista(ContCel* lista, Cont* cont);

void destroi_cont(Cont* cont);
