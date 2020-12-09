#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

void le_numero(FILE* entrada, char* string) {
    char car = fgetc(entrada);

    int len = 0;
    char num[256];

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

    while (!feof(entrada)) {
        car = fgetc(entrada);

        if (car == '(') {
            Arvore* aux = cria_node_arvore();

            if (arv == NULL) {
                arv = aux;
            } else if (get_esq(arv) == NULL) {
                set_esq(arv, aux);
            }

            aux = parse_entrada(entrada, aux);
            return arv;
        }

        else if (isdigit(car)) {
            fseek(entrada, -1, SEEK_CUR);
            char* num = (char*) malloc(sizeof(char) * 256);
            le_numero(entrada, num);

            set_val(arv, num);

            return arv;
        }

        else if (car == ')') {
            return arv;
        }

        else if (car == '+' || car == '-' || car == '*' || car == '/') {
            set_val(arv, strdup(&car));

            set_dir(arv, parse_entrada(entrada, arv));

            return arv;
        }
    }

    return arv;
}

int  main(int argc, char* argv[])
{
    if (argc == 2) {
        FILE *entrada = fopen(argv[1], "r");

        if (entrada == NULL) {
          printf("Erro ao ler arquivo de entrada\n");
          exit(1);
        }

        Arvore* arv = parse_entrada(entrada, NULL);

    } else {
        return 1;
    }
}
