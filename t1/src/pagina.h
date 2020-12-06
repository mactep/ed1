#ifndef PAGINA
#define PAGINA

typedef struct pagina Pagina;
typedef struct pag_cel PagCel;

#include "cont.h"
#include "link.h"

PagCel* cria_lista_pagina();

Pagina* cria_pagina(char* nome, char* arquivo);

PagCel* insere_pagina_lista(PagCel* lista, Pagina* pagina);

int retira_pagina_lista(PagCel* lista, char* nome);

void destroi_pagina(Pagina* pagina);

Pagina* get_pagina(PagCel* cel);

char* get_pagina_nome(Pagina* pagina);

char* get_pagina_arquivo(Pagina* pagina);

PagCel* get_prox_pagina(PagCel* cel);

void imprime_pagina_info(Pagina* pagina);

void insere_cont_pagina(Pagina* pagina, Cont* cont);

void insere_link_pagina(Pagina* pagina, Link* link);

int contem_caminho(Pagina* origem, char* destino);

#endif /* ifndef PAGINA */
