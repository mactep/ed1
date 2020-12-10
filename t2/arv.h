#ifndef abb_h
#define abb_h

typedef struct arv Arvore;

Arvore* cria_node_arvore();

void imprime_arvore(Arvore* arv);

Arvore* insere_arvore(Arvore* arv, char caractere);

Arvore* retira_arvore(Arvore* arv, int v);

void destroi_arvore(Arvore* arv);

char* get_val(Arvore* arv);

void set_val(Arvore* arv, char* val);

Arvore* get_esq(Arvore* arv);

void set_esq(Arvore* arv, Arvore* esq);

Arvore* get_dir(Arvore* arv);

void set_dir(Arvore* arv, Arvore* dir);

Arvore* get_pai(Arvore* arv);

Arvore* busca_arvore(Arvore* arv, int chave);

int calcula_arvore(Arvore* arv);

#endif
