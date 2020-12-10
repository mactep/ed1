#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

void le_numero(FILE* entrada, char* string) {
    char car = fgetc(entrada);

    int len = 0;
    char num[256] = "";

    while (isdigit(car)) {
        num[len] = car;
        len++;
        car = fgetc(entrada);
    }

    num[len + 1] = '\0';
    fseek(entrada, -1, SEEK_CUR);
    strcpy(string, num);
}

Arvore* parse_entrada(FILE* entrada, Arvore* arv) {
    char car;

    while (car != '\n') {
        car = fgetc(entrada);
        if (car == EOF) {
            return NULL;
        }

        if (car == '(') {
            // printf("cai no caso (\n");
            Arvore* aux = cria_node_arvore();

            if (arv == NULL) {
                arv = aux;
            } else if (get_esq(arv) == NULL) {
                set_esq(arv, aux);
            } 
            else if (get_dir(arv) == NULL) {
                set_dir(arv, aux);
            }
            aux = parse_entrada(entrada, aux);
        }

        else if (isdigit(car)) {
            // printf("cai no de numero\n");
            fseek(entrada, -1, SEEK_CUR);
            char* num = (char*) malloc(sizeof(char) * 256);
            le_numero(entrada, num);

            set_val(arv, num);
        }

        else if (car == '+' || car == '-' || car == '*' || car == '/') {
            // printf("cai no caso do operador\n");
            char *val = malloc(sizeof(char)*2);
            val[0] = car;
            val[1] = '\0';
            set_val(arv, val);
        }

        else if (car == ')') {
            // printf("cai no caso )\n");
            return arv;
        }
    }

    return arv;
}

int  main(int argc, char* argv[])
{
    if (argc == 2) {
        FILE *entrada = fopen(argv[1], "r");
        FILE *saida = fopen("saida.txt", "w");

        if (entrada == NULL || saida == NULL) {
          printf("Erro ao ler arquivo de entrada\n");
          exit(1);
        }

        while (!feof(entrada)) {
            fflush(stdout);
            Arvore* arv = parse_entrada(entrada, NULL);
            if (!arv) {
                return 0;
            }
            fprintf(saida,"%d\n", calcula_arvore(arv));
        }

    } else {
        return 1;
    }
}
