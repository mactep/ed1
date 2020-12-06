#ifndef WIKI
#define WIKI

#include "pagina.h"

typedef struct wiki Wiki;

Wiki* cria_wiki(char* nome);

void insere_pagina(Wiki* wiki, char* nome_pagina, char* filename);

int retira_pagina(Wiki* wiki, char* nome_pagina);

void insere_editor(Wiki* wiki, char* editor);

void insere_contribuicao(Wiki* wiki, char* nome_pagina, char* nome_editor, char* arquivo);

int retira_contribuicao(Wiki* wiki, char* pagina, char* editor);

void insere_link(Wiki* wiki, char* origem, char* destino);

int retira_link(Wiki* wiki, char* origem, char* destino);

int caminho(Wiki* wiki, char* origem, char* destino);

void imprime_pagina(Wiki* wiki, char* pagina);

void imprime_wiki(Wiki* wiki);

void detroi_wiki(Wiki* wiki);

void imprime_editores(Wiki* wiki);

Editor* seleciona_editor(Wiki* wiki, char* nome_editor);

Pagina* seleciona_pagina(Wiki* wiki, char* nome_pagina);

#endif /* ifndef WIKI */
