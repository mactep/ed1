typedef struct pagina Pagina;
typedef struct pag_cel PagCel;

PagCel* cria_lista_pagina();

Pagina* cria_pagina(char* nome, char* arquivo);

PagCel* insere_pagina_lista(PagCel* lista, Pagina* pagina);

void retira_pagina_lista(PagCel* lista, char* nome);

void destroi_pagina(Pagina* pagina);
