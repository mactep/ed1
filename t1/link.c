#include <stdlib.h>
#include "link.h"

struct link_cel {
    Link* link;
    LinkCel* prox;
    LinkCel* ant;
};

struct link {
    char* nome_arquivo;
};

LinkCel* cria_lista_link() {
    LinkCel* lista = (LinkCel*) malloc(sizeof(LinkCel));
    lista->link = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Link* cria_link(char* nome_arquivo) {
    Link* link = (Link*) malloc(sizeof(Link));
    link->nome_arquivo = nome_arquivo;

    return link;
}

LinkCel* insere_nome_arquivo_lista(LinkCel* lista, Link* link) {
    if (lista->link == NULL) {
        lista->link = link;

        return lista;
    } else {
        LinkCel* cel = (LinkCel*) malloc(sizeof(LinkCel));
        cel->link = link;
        cel->prox = NULL;
        cel->ant = lista;
        lista->prox = cel;

        return cel;
    }
}

void destroi_nome_arquivo(Link* link) {
    free(link);
}
