#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pagina.h"

struct pag_cel {
    Pagina* pagina;
    PagCel* prox;
    PagCel* ant;
};

struct pagina {
    char* nome;
    char* arquivo;
    ContCel* contribs;
    LinkCel* links;
};

PagCel* cria_lista_pagina() {
    PagCel* lista = (PagCel*) malloc(sizeof(PagCel));
    lista->pagina = NULL;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

Pagina* cria_pagina(char* nome, char* arquivo) {
    Pagina* pagina = (Pagina*) malloc(sizeof(Pagina));
    pagina->nome = strdup(nome);
    pagina->arquivo = strdup(arquivo);
    pagina->contribs = cria_lista_cont();
    pagina->links = cria_lista_link();

    return pagina;
}

PagCel* insere_pagina_lista(PagCel* lista, Pagina* pagina) {
    if (lista->pagina == NULL) {
        lista->pagina = pagina;
        return lista;
    } else {
        PagCel* cel = (PagCel*) malloc(sizeof(PagCel));
        cel->pagina = pagina;
        cel->ant = NULL;
        cel->prox = lista;
        lista->ant = cel;

        return cel;
    }
}

int retira_pagina_lista(PagCel* lista, char* nome) {
    for (PagCel* cel = lista; cel != NULL; cel = cel->prox) {
        if (cel->pagina->nome == nome) {
            if (cel->pagina == NULL) {
                return 0;
            }

            if (cel->ant == NULL) {
                lista = cel->prox;
                lista->ant = NULL;
            } else if (cel->prox == NULL) {
                cel->ant->prox = NULL;
            } else {
                cel->ant->prox = cel->prox;
                cel->prox->ant = cel->ant;
            }

            free(cel);
            return 1;
        }
    }
    return 0;
}

void destroi_pagina(Pagina* pagina) {
    for (ContCel* cel = pagina->contribs; cel != NULL; cel = get_prox_cont(cel)) {
        destroi_cont(get_cont(get_prox_cont(cel)));
    }

    for (LinkCel* cel = pagina->links; cel != NULL; cel = get_prox_link(cel)) {
        destroi_link(get_link(get_prox_link(cel)));
    }

    free(pagina);
}

Pagina* get_pagina(PagCel* cel) {
    return cel->pagina;
}

char* get_pagina_nome(Pagina* pagina) {
    return pagina->nome;
}

char* get_pagina_arquivo(Pagina* pagina) {
    return pagina->arquivo;
}

PagCel* get_prox_pagina(PagCel* cel) {
    return cel->prox;
}

void imprime_pagina_info(Pagina* pagina) {
    FILE *entrada;
    FILE *saida = fopen(pagina->arquivo, "w");

    fprintf(saida, "Pagina %s\n\n", pagina->nome);

    fprintf(saida, "Historico de contribuicoes: ");
    for (ContCel* cel = pagina->contribs; cel != NULL; cel = get_prox_cont(cel)) {
        fprintf(saida, "%s ", get_cont_arquivo(get_cont(cel)));
        fprintf(saida, "%s, ", get_editor_nome(get_cont_editor(get_cont(cel))));
    }
    fprintf(saida, "\n\n");

    fprintf(saida, "Lista de links: ");
    for (LinkCel* cel = pagina->links; cel != NULL; cel = get_prox_link(cel)) {
        fprintf(saida, "l-%s, ", get_pagina_destino(get_link(cel))->nome);
    }
    fprintf(saida, "\n\n");

    fprintf(saida, "Textos:\n");
    char palavra[256];
    for (ContCel* cel = pagina->contribs; cel != NULL; cel = get_prox_cont(cel)) {
        entrada = fopen(get_cont_arquivo(get_cont(cel)), "r");
        while (!feof(entrada)) {
            fscanf(entrada, "%s\n", palavra);
            fprintf(saida, "%s ", palavra);
        }
    }
}

void insere_cont_pagina(Pagina* pagina, Cont* cont) {
    pagina->contribs = insere_cont_lista(pagina->contribs, cont);
}

void insere_link_pagina(Pagina* pagina, Link* link) {
    pagina->links = insere_link_lista(pagina->links, link);
}

int contem_caminho(Pagina* origem, char* destino) {
    for (LinkCel* cel = origem->links; cel != NULL; cel = get_prox_link(cel)) {
        Pagina* pag_destino = get_pagina_destino(get_link(cel));
        if (strcmp(destino, get_pagina_nome(pag_destino)) == 0) {
            return 1;
        }
    }

    return 0;
}
