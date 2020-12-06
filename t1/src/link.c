#include <stdlib.h>
#include "link.h"

struct link_cel {
    Link* link;
    LinkCel* prox;
    LinkCel* ant;
};

struct link {
    Pagina* origem;
    Pagina* destino;
};

LinkCel* cria_lista_link() {
    LinkCel* lista = (LinkCel*) malloc(sizeof(LinkCel));
    lista->link = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Link* cria_link(Pagina* origem, Pagina* destino) {
    Link* link = (Link*) malloc(sizeof(Link));
    link->origem = origem;
    link->destino = destino;

    return link;
}

LinkCel* insere_link_lista(LinkCel* lista, Link* link) {
    if (lista->link == NULL) {
        lista->link = link;

        return lista;
    } else {
        LinkCel* cel = (LinkCel*) malloc(sizeof(LinkCel));
        cel->link = link;
        cel->ant = NULL;
        cel->prox = lista;
        lista->ant = cel;

        return cel;
    }
}

void destroi_link(Link* link) {
    free(link);
}

Link* get_link(LinkCel* cel) {
    return cel->link;
}

LinkCel* get_prox_link(LinkCel* cel) {
    return cel->prox;
}

Pagina* get_pagina_origem(Link* link) {
    return link->origem;
}

Pagina* get_pagina_destino(Link* link) {
    return link->destino;
}

int checa_caminho_link(Link* link, char* origem, char* destino) {
    if (get_pagina_nome(link->origem) == get_pagina_nome(link->destino)) {
        return 1;
    }

    return 0;
}
