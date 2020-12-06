#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wiki.h"

struct wiki {
    char* nome;
    PagCel* paginas;
    EditCel* editores;
};

Wiki* cria_wiki(char* nome) {
    Wiki* wiki = (Wiki*) malloc(sizeof(Wiki));

    wiki->nome = nome;
    wiki->paginas = cria_lista_pagina();
    wiki->editores = cria_lista_editor();

    return wiki;
}

void insere_pagina(Wiki* wiki, char* nome_pagina, char* filename) {
    Pagina* pagina = cria_pagina(nome_pagina, filename);
    wiki->paginas = insere_pagina_lista(wiki->paginas, pagina);
}

int retira_pagina(Wiki* wiki, char* nome_pagina) {
    return retira_pagina_lista(wiki->paginas, nome_pagina);
}

int retira_link(Wiki* wiki, char* origem, char* destino) {
}

void imprime_pagina(Wiki* wiki, char* nome) {
    for (PagCel* cel = wiki->paginas; cel != NULL; cel = get_prox_pagina(cel)) {
        if (strcmp(get_pagina_nome(get_pagina(cel)), nome) == 0) {
            imprime_pagina_info(get_pagina(cel));
        }
    }
}

void imprime_wiki(Wiki* wiki) {
    for (PagCel* cel = wiki->paginas; cel != NULL; cel = get_prox_pagina(cel)) {
        imprime_pagina_info(get_pagina(cel));
    }
}

void insere_editor(Wiki* wiki, char* nome_editor) {
    Editor* editor = cria_editor(nome_editor);
    wiki->editores = insere_editor_lista(wiki->editores, editor);
}

void imprime_editores(Wiki* wiki) {
    for (EditCel* cel = wiki->editores; cel != NULL; cel = get_prox_editor(cel)) {
        imprime_editor(get_editor(cel));
    }
}

Editor* seleciona_editor(Wiki* wiki, char* nome_editor) {
    for (EditCel* cel = wiki->editores; cel != NULL; cel = get_prox_editor(cel)) {
        Editor* editor = get_editor(cel);
        if (strcmp(get_editor_nome(editor), nome_editor) == 0) {
            return editor;
        }
    }

    return NULL;
}

Pagina* seleciona_pagina(Wiki* wiki, char* nome_pagina) {
    for (PagCel* cel = wiki->paginas; cel != NULL; cel = get_prox_pagina(cel)) {
        Pagina* pagina = get_pagina(cel);
        if (strcmp(get_pagina_nome(pagina), nome_pagina) == 0) {
            return pagina;
        }
    }

    return NULL;
}

void insere_contribuicao(Wiki* wiki, char* nome_pagina, char* nome_editor, char* arquivo) {
    Pagina* pagina = seleciona_pagina(wiki, nome_pagina);
    Editor* editor = seleciona_editor(wiki, nome_editor);
    Cont* cont = cria_cont(editor, arquivo);

    insere_cont_pagina(pagina, cont);
}

void insere_link(Wiki* wiki, char* origem, char* destino) {
    Pagina* pag1 = seleciona_pagina(wiki, origem);
    Pagina* pag2 = seleciona_pagina(wiki, destino);

    Link* link = cria_link(pag1, pag2);

    insere_link_pagina(pag1, link);
}

int caminho(Wiki* wiki, char* origem, char* destino) {
    Pagina* pag1 = seleciona_pagina(wiki, origem);
    if (contem_caminho(pag1, destino)) {
        return 1;
    }

    return 0;
}
