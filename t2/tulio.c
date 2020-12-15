#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arv.h"

int  main(int argc, char* argv[])
{
    if (argc == 2) {
        // pega o arquivo de entrada da linha de comando e  define o de saída como "saida.txt"
        FILE *entrada = fopen(argv[1], "r");
        FILE *saida = fopen("saida.txt", "w");

        // Verifica se os arquivos foram abertos corretamente
        if (entrada == NULL || saida == NULL) {
          printf("Erro ao ler os arquivos\n");
          exit(1);
        }

        // Lê o arquivo de entrada até a última linha
        while (!feof(entrada)) {
            // correção de bug no printf
            fflush(stdout);
            // Cria uma arvore interpretando os dados da linha
            Arvore* arv = parse_entrada(entrada, NULL);

            // Se a árvore for nula, termina a execução do código
            if (!arv) {
                return 0;
            }
            // Imprime o resultado da expressão
            printf("%f\n", calcula_arvore(arv));
            fprintf(saida, "%f\n", calcula_arvore(arv));

            // Libera memória
            destroi_arvore(arv);
        }


    } else {
        return 1;
    }
}
