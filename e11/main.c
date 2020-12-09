#include <stdio.h>

#include "hash.h"

int main(int argc, char *argv[])
{
    if (argc == 2) {
        FILE *entrada = fopen(argv[1], "r");

        if (entrada == NULL) {
          printf("Erro ao ler arquivo de entrada\n");
          return 1;
        }

        Hash* hash_table = cria_hash(150);

        char string[256];
        while (!feof(entrada)) {
            fscanf(entrada, "%s\n", string);
            Palavra* pal = acessa(hash_table, string);
            inc_ocorrencia(pal);
        }

        imprime_hash(hash_table);

        destro_hash(hash_table);

        return 0;
    } else {
        return 1;
    }
}
