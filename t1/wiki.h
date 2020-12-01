typedef struct wiki Wiki;

Wiki* cria_wiki(char* nome);

void insere_pagina(Wiki* wiki, char* nome_pagina, char* filename);

void retira_pagina(Wiki* wiki, char* nome_pagina);

void insere_editor(Wiki* wiki, char* editor);
void insere_contribuicao(Wiki* wiki, char* pagina, char* editor, char* filename);
void retira_contribuicao(Wiki* wiki, char* pagina, char* editor);
void insere_link(Wiki* wiki, char* origem, char* destino);
void retira_link(Wiki* wiki, char* origem, char* destino);
int caminho(Wiki* wiki, char* origem, char* destino);
void imprime_pagina(char* pagina);
void imprime_wiki(Wiki* wiki);
void detroi_wiki(Wiki* wiki);
