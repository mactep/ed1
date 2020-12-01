#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(int argc, char* argv[])
{
    if (argc == 2) {
        FILE *entrada = fopen(argv[1], "r");
        FILE *log = fopen("Arquivo de log.txt", "w");

        if (entrada == NULL || log == NULL) {
          printf("Erro ao ler arquivo de entrada\n");
          exit(1);
        }

        char comando[256];
        char arg1[256];
        char arg2[256];
        char arg3[256];
        while (!feof(entrada)) {
            fscanf(entrada, "%s\n", comando);
            if (strcmp(comando, "INSEREPAGINA") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                // insere_pagina(arg1, arg2);
            } else if (strcmp(comando, "RETIRAPAGINA") == 0) {
                fscanf(entrada, "%s\n", arg1);
                // retira_pagina(arg1, arg2);
            } else if (strcmp(comando, "INSEREEDITOR") == 0) {
                fscanf(entrada, "%s\n", arg1);
                // insere_editor(arg1, arg2);
            } else if (strcmp(comando, "RETIRAEDITOR") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fprintf(log, "Comando 'RETIRAEDITOR' não é cobrado\n");
            } else if (strcmp(comando, "INSERECONTRIBUICAO") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                fscanf(entrada, "%s\n", arg3);
                // insere_contribuicao(arg1, arg2, arg3);
            } else if (strcmp(comando, "INSERELINK") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                // insere_link(arg1, arg2, arg3);
            } else if (strcmp(comando, "IMPRIMEPAGINA") == 0) {
                fscanf(entrada, "%s\n", arg1);
                // imprime_pagina(arg1, arg2, arg3);
            } else if (strcmp(comando, "RETIRACONTRIBUICAO") == 0) {
                fscanf(entrada, "%s\n", arg1);
                fscanf(entrada, "%s\n", arg2);
                fscanf(entrada, "%s\n", arg3);
                // retira_contribuicao(arg1, arg2, arg3);
            } else if (strcmp(comando, "CAMINHO") == 0) {
                fscanf(entrada, "%s\n", arg1);
                // caminho(arg1);
            } else if (strcmp(comando, "IMPRIMEWIKED") == 0) {
                // imprime_wiked();
            } else if (strcmp(comando, "FIM") == 0) {
                fclose(entrada);
                fclose(log);
                return 0;
            } else {
                printf("Sei la o que ta rolando aqui");
            }

            fprintf(log, "lendo arquivo de entrada\n");
        }
    } else {
        return 1;
    }
}
