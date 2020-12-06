#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wiki.h"

int  main(int argc, char* argv[])
{
    if (argc == 2) {
        FILE *entrada = fopen(argv[1], "r");
        FILE *log = fopen("Arquivo de log.txt", "w");

        if (entrada == NULL || log == NULL) {
          printf("Erro ao ler arquivo de entrada\n");
          exit(1);
        }

        Wiki* wiked = cria_wiki("WikED!");

        char comando[256];
        char arg1[256];
        char arg2[256];
        char arg3[256];
        while (!feof(entrada)) {
            fscanf(entrada, "%s\n", comando);
            if (strcmp(comando, "INSEREPAGINA") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                insere_pagina(wiked, arg1, arg2);
            } else if (strcmp(comando, "RETIRAPAGINA") == 0) {
                fscanf(entrada, "%s\n", arg1);
                int r = retira_pagina(wiked, arg1);
                if (!r) {
                    fprintf(log, "Erro: pagina %s nao existente\n", arg1);
                }
            } else if (strcmp(comando, "INSEREEDITOR") == 0) {
                fscanf(entrada, "%s\n", arg1);
                insere_editor(wiked, arg1);
            } else if (strcmp(comando, "RETIRAEDITOR") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fprintf(log, "Comando 'RETIRAEDITOR' não é cobrado\n");
            } else if (strcmp(comando, "INSERECONTRIBUICAO") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                fscanf(entrada, "%s\n", arg3);
                insere_contribuicao(wiked, arg1, arg2, arg3);
            } else if (strcmp(comando, "INSERELINK") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                insere_link(wiked, arg1, arg2);
            } else if (strcmp(comando, "REMOVELINK") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                // remove_link(wiked, arg1, arg2);
                fprintf(log, "Comando 'REMOVELINK' não implementado\n");
            } else if (strcmp(comando, "IMPRIMEPAGINA") == 0) {
                fscanf(entrada, "%s\n", arg1);
                imprime_pagina(wiked, arg1);
            } else if (strcmp(comando, "RETIRACONTRIBUICAO") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                fscanf(entrada, "%s\n", arg3);
                fprintf(log, "Comando 'RETIRACONTRIBUICAO' não implementado\n");
                // retira_contribuicao(arg1, arg2, arg3);
            } else if (strcmp(comando, "CAMINHO") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                int r = caminho(wiked, arg1, arg2);
                if (r) {
                    fprintf(log, "Ha caminho entre %s e %s\n", arg1, arg2);
                } else {
                    fprintf(log, "Não ha caminho entre %s e %s\n", arg1, arg2);
                }
            } else if (strcmp(comando, "IMPRIMEWIKED") == 0) {
                imprime_wiki(wiked);
            } else if (strcmp(comando, "FIM") == 0) {
                fclose(entrada);
                fclose(log);
                return 0;
            } else {
                printf("Sei la o que ta rolando aqui\n");
                printf("%s\n", comando);
            }
        }
    } else {
        return 1;
    }
}
