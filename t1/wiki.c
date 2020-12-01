#include <stdlib.h>
#include "wiki.h"
#include "pagina.h"
#include "edit.h"

struct wiki {
    char* nome;
    PagCel* paginas;
    EditCel* editores;
};

Wiki* cria_wiki(char* nome) {
    Wiki* wiki = (Wiki*) malloc(sizeof(Wiki));

    wiki->nome = nome;
    wiki->paginas = NULL;
    wiki->editores = NULL;

    return wiki;
}

void insere_pagina(Wiki* wiki, char* nome_pagina, char* filename) {
    Pagina* pagina = cria_pagina(nome_pagina, filename);
    insere_pagina_lista(wiki->paginas, pagina);
}

void retira_pagina(Wiki* wiki, char* nome_pagina) {
    retira_pagina_lista(wiki->paginas, nome_pagina);
}
