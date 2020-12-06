#ifndef LINK
#define LINK

typedef struct link Link;
typedef struct link_cel LinkCel;

#include "pagina.h"

LinkCel* cria_lista_link();

Link* cria_link(Pagina* origem, Pagina* destino);

LinkCel* insere_link_lista(LinkCel* lista, Link* link);

void destroi_link(Link* link);

Link* get_link(LinkCel* cel);

LinkCel* get_prox_link(LinkCel* cel);

Pagina* get_pagina_origem(Link* link);

Pagina* get_pagina_destino(Link* link);

int checa_caminho_link(Link* link, char* origem, char* destino);

#endif /* ifndef LINK */
