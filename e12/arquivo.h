#ifndef lista_gen_h
#define lista_gen_h

typedef struct cel Cel;

Cel* criaLista();

void set_cont(Cel* cel, void* cont);

void* get_cont(Cel* cel);

void set_prox(Cel* cel, Cel* prox);

Cel* get_prox(Cel* cel);

void set_ant(Cel* cel, Cel* ant);

Cel* get_ant(Cel* cel);

Cel* insereElemento(Cel* lista, void* cont);

Cel* retiraElemento(Cel* lista, int pos);

int percorreLista(Cel* lista, int (*cb)(void*));

void destroiLista(Cel* lista);

#endif
