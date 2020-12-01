typedef struct link Link;
typedef struct link_cel LinkCel;

LinkCel* cria_lista_link();

Link* cria_link(char* nome_arquivo);

LinkCel* insere_nome_arquivo_lista(LinkCel* lista, Link* link);

void destroi_nome_arquivo(Link* link);
